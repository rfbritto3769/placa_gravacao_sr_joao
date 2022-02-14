#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"

unsigned char BulkEraseProgData677(void)
{
	unsigned int addr,data_rec;
	unsigned char ret=0;
	ret=EnterProgMode677();
	if(!ret)
	{
		SendCommand(LOAD_CONFIGURATION,0);
		SendCommand(BULK_ERASE_PROG_MEM,0);
		if(Processador!=PIC_16F506)
			SendCommand(BULK_ERASE_DATA_MEM,0);
		ExitProgMode677();
		delay_50us(20);
	}	
	if(!ret)
		ret=EnterProgMode677();
	if(!ret)
	{
		delay_50us(20);
		for(addr=0;addr<=MaxMemory;addr++)
		{
			data_rec=SendCommand(READ_DATA_PROG_MEM,0);	
			if(data_rec!=0x3fff)	//
			{
				StatusGr=0xf1;					// Erro no apagamento
				return(1);
			}
			SendCommand(INCREMENT_ADDRESS,0);	// incrementa PC
		}
	}
	ExitProgMode677();
	return(ret);
}
	
unsigned char EnterProgMode677(void)
{
	PGC=false;
	PGD=false;
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(20);
	Vpp_GND_OFF();
	VPP=ON;
	delay_50us(50);
	
	if((ADCValueVpp<=636)||(ADCValueVpp>=690))
	{
		VPP=OFF;
		Vpp_GND_ON();
		StatusGr=0xf7;			// Erro na tensão de gravação (VPP)
		return(1);
	}
	else
		return(0);
}

void ExitProgMode677(void) 
{
	PGC=false;
	PGD=false;
	delay_50us(10);
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(10);
}

void Programa677(void)
	{
	unsigned char i=0,ret=0,a,b;
	StatusGr=0x01;			// Apagando
	CountWord=0;
	PGC=false;
	PGD=false;
	Vdd_5V();			//Seta alimentação para 5V
	Vpp_13V();			//seta VPP para 13V
	OE_U2=false;		//input
	PGD_DIR=true;		//output
	OE_U5=true;			//output
	RecordType = 0;
	Endereco16F=0;
	Vpp_GND_OFF();		//desconecta VPP de GND
	VDD_GR=ON;			//liga alimentação
	delay_50us(500);//100);	//400);
//	if((ADCValueVdd<=280)||(ADCValueVdd>=300))
	if((ADCValueVdd<=230)||(ADCValueVdd>=350))
		{
//		VDD_GR=OFF;		//desliga alimentação
//		Vpp_GND_ON();
		StatusGr=0xf6;	// Erro na tensão de alimentação (VDD)
		ret=0xff;//return;
//		return;
		}
/**********************************************/
/*						Endereco=EnderecoBase;
						delay_50us(10);
						EnterProgMode677();
						delay_50us(10);
						ret=VerifyProgMem677();
						if(!ret&&!AbortaGr)
//							ProgConfigMem677();
		StatusGr=0x04;							// Gravação OK
						ExitProgMode677();
						delay_50us(10);
						VDD_GR=false;*/
/**********************************************/
	if(!ret)
		ret=BulkEraseProgData677();
	if(StatusGr==0xf1)			// Erro no apagamento
		ret=0xff;//return;
	delay_50us(10);
	if(!ret)
		ret=EnterProgMode677();
	if(!ret)
		{
		Endereco=EnderecoBase;
		StatusGr=0x02;			// Gravação em andamento
		do
			{
			MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
			Endereco+=512;
			IndexBuffer=0;
			if(i==0&&MemoryBuffer[IndexBuffer]==':')
				IndexBuffer++;
			while(IndexBuffer<512&&!ret&&!AbortaGr)
				{
				if(MemoryBuffer[IndexBuffer]!=':')
					{
					do											
						{
						BufferLine[i]=MemoryBuffer[IndexBuffer];
						i++;
						IndexBuffer++;
						}while (MemoryBuffer[IndexBuffer]!=':'&&IndexBuffer<512);
					}
				if(MemoryBuffer[IndexBuffer]==':')
					{
					IndexBuffer++;
					i=0;
					MontaHeader(BufferLine);
					if(RecordType==0x00)
						{
						if(Address != 0x400E)
							ProgFourWord677();
						else
							{
							if(CountWord!=0)
								SendCommand(BEGIN_PROGRAMMING,0);	// grava as quatro words
							ExitProgMode677();
							Endereco=EnderecoBase;
							delay_50us(10);
							EnterProgMode677();
							delay_50us(10);
							a=DataHex[0];
							b=DataHex[1];
							ret=VerifyProgMem677();
							if(!ret&&!AbortaGr)
								{
								DataHex[0]=a;
								DataHex[1]=b;
								ProgConfigMem677();
								}
							ExitProgMode677();
							delay_50us(10);
							VDD_GR=false;
							ret=1;
							}
						}
					}
				}
			}while(RecordType!=0x01&&!ret&&!AbortaGr);
		}	
	AbortaGr=false;
	ExitProgMode677();
//	delay_50us(20);
	PGD_DIR=false;			//hightZ
	OE_U2=false;			//hightZ
	OE_U5=false;			//hightZ
	VDD_GR=OFF;
	}

void ProgFourWord677(void)
	{
	volatile unsigned int datateste=0;
	unsigned char i=0;

	while(Endereco16F != Address) 
		{
		Endereco16F += 2;
		if(++CountWord==0x04)
			{
			SendCommand(BEGIN_PROGRAMMING,0);				// grava as quatro words
			CountWord=0;
			}
		SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
		}
	Endereco16F += (unsigned int)ByteCount;
	while(ByteCount) 
		{
		datateste=(unsigned int)DataHex[i+1];
		datateste=((datateste<<8)|(unsigned int)DataHex[i]);
		SendCommand(LOAD_DATA_PROG_MEM,datateste);		// primeira word
		if(++CountWord==0x04)
			{
			SendCommand(BEGIN_PROGRAMMING,0);				// grava as quatro words
			CountWord=0;
			}
		SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
		ByteCount -= 2;
		i+=2;
		if(ByteCount)
			{
			datateste=(unsigned int)DataHex[i+1];
			datateste=((datateste<<8)|(unsigned int)DataHex[i]);
			SendCommand(LOAD_DATA_PROG_MEM,datateste);	// segunda word
			if(++CountWord==0x04)
				{
				SendCommand(BEGIN_PROGRAMMING,0);				// grava as quatro words
				CountWord=0;
				}
			SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC
			ByteCount -= 2;
			i+=2;
			}
		if(ByteCount)
			{
			datateste=(unsigned int)DataHex[i+1];
			datateste=((datateste<<8)|(unsigned int)DataHex[i]);
			SendCommand(LOAD_DATA_PROG_MEM,datateste);	// terceira word
			if(++CountWord==0x04)
				{
				SendCommand(BEGIN_PROGRAMMING,0);				// grava as quatro words
				CountWord=0;
				}
			SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC
			ByteCount -= 2;
			i+=2;
			}
		if(ByteCount)
			{
			datateste=(unsigned int)DataHex[i+1];
			datateste=((datateste<<8)|(unsigned int)DataHex[i]);
			SendCommand(LOAD_DATA_PROG_MEM,datateste);	// quarta word
			if(++CountWord==0x04)
				{
				SendCommand(BEGIN_PROGRAMMING,0);				// grava as quatro words
				CountWord=0;
				}
			SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
			ByteCount -= 2;
			i+=2;
			}
		}
	}
	
unsigned char VerifyProgMem677(void)
	{
	unsigned char i=0,ix=0;
	volatile unsigned int datateste, AddrFinal, datarec;

	StatusGr=0x03;			// Verificando gravação

	AddrFinal=Endereco16F;
	Endereco16F=0;
	do
		{
		MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
		Endereco+=512;
		IndexBuffer=0;
		if(i==0&&MemoryBuffer[IndexBuffer]==':')
			IndexBuffer++;
		while(IndexBuffer<512)
			{
			if(MemoryBuffer[IndexBuffer]!=':')
				{
				do
					{
					BufferLine[i]=MemoryBuffer[IndexBuffer];
					i++;
					IndexBuffer++;
					}while (MemoryBuffer[IndexBuffer]!=':'&&IndexBuffer<512);
				}
				
			if(MemoryBuffer[IndexBuffer]==':')
				{
				IndexBuffer++;
				i=0;
				ix=0;
				MontaHeader(BufferLine);
				if(RecordType==0x00)
					{
					if(Address != 0x400E)
						{
						while(Endereco16F != Address) 
							{
							Endereco16F += 2;
							SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
							}
						Endereco16F += (unsigned int)ByteCount;
						
						while(ByteCount) 
							{
							datarec=SendCommand(READ_DATA_PROG_MEM,0);
							datateste=(unsigned int)DataHex[ix+1];
							datateste=((datateste<<8)|(unsigned int)DataHex[ix]);
							if(datateste!=datarec)	//
								{
								StatusGr=0xf3;			// Erro na gravação
								return(1);
								}
							SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
							ix+=2;
							ByteCount -= 2;
							AddrFinal -= 2;
							}
						}
					else
						return 0;
					}
				}
			}
		}while(AddrFinal);
	return(0);
	}
	
void ProgConfigMem677(void)
	{
	volatile unsigned int datateste;
	//,datax;
	SendCommand(LOAD_CONFIGURATION,0);			// > 0x2000
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2001
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2002
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2003
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2004
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2005
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2006
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x2007
	datateste=(unsigned int)DataHex[1];
	datateste=((datateste<<8)|(unsigned int)DataHex[0])&0x3fff;
	SendCommand(LOAD_DATA_PROG_MEM,datateste);	// terceira word
	SendCommand(BEGIN_PROGRAMMING,0);			// grava word de configuração
	if(datateste!=SendCommand(READ_DATA_PROG_MEM,0))
		StatusGr=0xf4;							// Erro de gravação
	else
		StatusGr=0x04;							// Gravação OK
	}	
