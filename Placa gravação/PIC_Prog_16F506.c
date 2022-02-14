#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"

unsigned char BulkEraseProgData506(void)
	{
	unsigned int addr=0,data_rec;
	unsigned char ret=0;
	ret=EnterProgMode506();
	if(!ret)
		{
		SendCommand(BULK_ERASE_PROG_MEM,0);
		data_rec=(SendCommand(READ_DATA_PROG_MEM,0)&0x0fff);	
		if(data_rec!=0x0fff)				// Testa se Configuration word apagada
			{
			StatusGr=0xf1;					// Erro no apagamento
			return(1);
			}
		SendCommand(INCREMENT_ADDRESS,0);	// incrementa PC para 0x0000
		while(addr<=MaxMemory)				// Testa se memoria de programa apagada
			{
			data_rec=(SendCommand(READ_DATA_PROG_MEM,0)&0x0fff);	
			if(data_rec!=0x0fff)	//
				{
				StatusGr=0xf1;				// Erro no apagamento
				return(1);
				}
			SendCommand(INCREMENT_ADDRESS,0);// incrementa PC
			addr++;
			}
		while(addr<0x405)
			{
			if(addr==0x404)
				{
				WordProg[addr]=SendCommand(READ_DATA_PROG_MEM,0);
				if((WordProg[addr]&0x0f00)!=0x0c00)
					{
					StatusGr=0xf8;			// Erro no byte de calibra��o do oscilador
					return(1);
					}
				else
					WordProg[0x03ff]=WordProg[addr];
				}	
			SendCommand(INCREMENT_ADDRESS,0);	// incrementa PC
			addr++;
			}
		while(addr!=0x07ff)
			{
			SendCommand(INCREMENT_ADDRESS,0);// incrementa PC at� Configuration word
			addr++;
			}
		}
	return(ret);
	}
	
unsigned char EnterProgMode506(void)
{
	PGC=false;
	PGD=false;
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(20);
	Vpp_GND_OFF();
	VPP=ON;
	delay_50us(100);//20);
	if((ADCValueVpp<=600)||(ADCValueVpp>=700))
	{
		VPP=OFF;
		Vpp_GND_ON();
		StatusGr=0xf7;			// Erro na tens�o de grava��o (VPP)
		return(1);
	}
	else
		return(0);
}

void ExitProgMode506(void) 
{
	PGC=false;
	PGD=false;
	delay_50us(10);
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(10);
}

void Programa506(void)
{
	unsigned char i=0,ret=0;
	StatusGr=0x01;			// Apagando
	for(AddrProg=0;AddrProg<=2048;AddrProg++)
		WordProg[AddrProg]=0x0fff;
	AddrProg=0;
	PGC=false;
	PGD=false;
	Vdd_5V();			//Seta alimenta��o para 5V
	Vpp_13V();			//seta VPP para 13V
	PGD_DIR=true;		//output
	OE_U2=false;			//output
	OE_U5=true;			//output
	RecordType = 0;
	Endereco16F=0;
	Vpp_GND_OFF();		//desconecta VPP de GND
	VDD_GR=ON;			//liga alimenta��o
	delay_50us(200);	//400);
	if((ADCValueVdd<=250)||(ADCValueVdd>=350))
	{
		VDD_GR=OFF;		//desliga alimenta��o
		StatusGr=0xf6;	// Erro na tens�o de alimenta��o (VDD)
		return;
	}

	ret=BulkEraseProgData506();

	if(!ret)
	{
		Endereco=EnderecoBase;
		StatusGr=0x02;			// Grava��o em andamento
		do
		{
			MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
			Endereco+=512;
			IndexBuffer=0;
			if(MemoryBuffer[IndexBuffer]==':')
				IndexBuffer++;
			while(IndexBuffer<512&&!ret&&!AbortaGr)
			{
				do											
					{
					BufferLine[i]=MemoryBuffer[IndexBuffer];
					i++;
					IndexBuffer++;
					}while (MemoryBuffer[IndexBuffer]!=':'&&IndexBuffer<512);
				if(MemoryBuffer[IndexBuffer]==':')
				{
					IndexBuffer++;
					i=0;
					MontaHeader(BufferLine);
					if(RecordType==0x00)
					{
						if(Address != 0x1ffe)	// n�o � config word
							MontaProg506();
						else
						{
							ConfWord=(unsigned int)DataHex[1];
							ConfWord=((ConfWord<<8)|(unsigned int)DataHex[0]);
							ProgOneWord506();
							ExitProgMode506();
							delay_50us(10);
							VDD_GR=OFF;
							ret=1;
						}
					}
				}
			}
		}while(RecordType!=0x01&&!ret&&!AbortaGr);
	}	
	AbortaGr=false;
	ExitProgMode506();
	PGD_DIR=false;			//hightZ
	OE_U2=false;			//hightZ
	OE_U5=false;			//hightZ
	VDD_GR=OFF;
}

void MontaProg506(void)
	{
	volatile unsigned int datateste=0;
	unsigned char i=0;

	while(Endereco16F != Address) 
		{
		Endereco16F += 2;
		SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
		AddrProg++;
		}
	AddrProg=(Endereco16F/2);
	Endereco16F += (unsigned int)ByteCount;

	while(ByteCount) 
		{
		datateste=(unsigned int)DataHex[i+1];
		datateste=((datateste<<8)|(unsigned int)DataHex[i]);
		WordProg[AddrProg]=datateste;
		ByteCount -= 2;
		i+=2;
		AddrProg++;
		}
	}
	
unsigned char ProgOneWord506(void)
{
	volatile unsigned int datateste;
	unsigned char ret;
	StatusGr=0x02;			// Gravando
	AddrProg=0;
	SendCommand(INCREMENT_ADDRESS,0);		// incrementa PC

	while(AddrProg<0x405)
	{
		if(WordProg[AddrProg]!=0x0fff)
			{
			SendCommand(LOAD_DATA_PROG_MEM,WordProg[AddrProg]);	// envia word
			SendCommand(BEGIN_PROGRAMMING,0);		// grava word
			SendCommand(END_PROGRAMMING,0);			// finaliza grava��o word
			datateste=SendCommand(READ_DATA_PROG_MEM,0);//verifica grava��o
			if(WordProg[AddrProg]!=datateste)//verifica grava��o
			{
				StatusGr=0xf3;							// Erro de grava��o
				return(1);
			}
		}
		SendCommand(INCREMENT_ADDRESS,0);		// incrementa PC
		AddrProg++;
	}
	StatusGr=0x03;			// Verificando
	
	ExitProgMode506();
	delay_50us(10);
	ret=EnterProgMode506();
	if(!ret)
	{
		SendCommand(LOAD_DATA_PROG_MEM,ConfWord);	// envia config word
		SendCommand(BEGIN_PROGRAMMING,0);			// grava config word
		SendCommand(END_PROGRAMMING,0);			// finaliza grava��o config word
		datateste=SendCommand(READ_DATA_PROG_MEM,0);//verifica grava��o
		if(ConfWord!=datateste)// verifica config word
		{
			StatusGr=0xf4;							// Erro de grava��o
			return(1);
		}
		else
			StatusGr=0x04;							// Grava��o OK
	}
	return(0);
}
