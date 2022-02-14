#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"


unsigned char BulkEraseProgData1828(void)
	{
	unsigned int addr,data_rec;
	unsigned char ret=0;
	ret=EnterProgMode1828();
	if(!ret)
		{
		SendCommand(LOAD_CONFIGURATION,0);
		SendCommand(BULK_ERASE_PROG_MEM,0);
		SendCommand(BULK_ERASE_DATA_MEM,0);
//		ExitProgMode1828();
		}
//	if(!ret)
//		ret=EnterProgMode1828();
	if(!ret)
		{
		SendCommand(RESET_ADDRESS,0);				// reset PC
		for(addr=0;addr<=MaxMemory;addr++)
			{
			data_rec=SendCommand(READ_DATA_PROG_MEM,0);
			if(data_rec!=0x3fff)	//
				{
				StatusGr=0xf1;			// Erro no apagamento
				return(1);
				}
			SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
			}
		}
//	ExitProgMode1828();
	return(ret);
	}
	
unsigned char EnterProgMode1828(void)
	{
	PGC=false;
	PGD=false;
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(20);
	Vpp_GND_OFF();
	VPP=ON;
	delay_50us(30);
	if((ADCValueVpp<=380)||(ADCValueVpp>=590))//510))
		{
		VPP=OFF;
		Vpp_GND_ON();
		StatusGr=0xf7;			// Erro na tensão de gravação (VPP)
		return(1);
		}
	else
		return(0);
	}

void ExitProgMode1828(void) 
	{
	PGC=false;
	PGD=false;
	delay_50us(10);
	VPP=OFF;
	Vpp_GND_OFF();
	delay_50us(10);
	}

void Programa1828(void)
{
	unsigned char i=0,ret=0,a,b,c,d,AddrExtend=0;
	volatile unsigned int testex=0;
	ContByteProg=0;
	AddrData=0;
	StatusGr=0x01;		// Apagando
	PGC=false;
	PGD=false;
	if(SetVdd3v)
		Vdd_3V();		//Seta alimentação para 5V
	if(SetVdd5v)
		Vdd_5V();		//Seta alimentação para 5V
	Vpp_9V();			//seta VPP para 9V
	PGD_DIR=true;		//output
	Vpp_GND_OFF();		//desconecta VPP de GND
	VDD_GR=ON;			//liga alimentação
	delay_50us(400);	//400);
	if(SetVdd3v)
	{
		if((ADCValueVdd<=200)||(ADCValueVdd>=250))
		{
			VDD_GR=OFF;		//desliga alimentação
			StatusGr=0xf6;	// Erro na tensão de alimentação (VDD)
			ret=0xff;
		}
	}
	else
	{
		if((ADCValueVdd<=200)||(ADCValueVdd>=350))
		{
			VDD_GR=OFF;		//desliga alimentação
			StatusGr=0xf6;	// Erro na tensão de alimentação (VDD)
			ret=0xff;
		}
	}
	if(!ret)
	{
		ret=BulkEraseProgData1828();
		delay_50us(10);
	}
	if(!ret)
	{
		SendCommand(RESET_ADDRESS,0);			// reset PC
		Endereco=EnderecoBase;
		StatusGr=0x02;			// Gravação em andamento
		RecordType = 0;
		Endereco16F=0;
		for(AddrProg=0;AddrProg<2048;AddrProg++)
			WordProg[AddrProg]=0x3fff;
		AddrProg=0;
		do
		{
			MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
			Endereco+=512;
			IndexBuffer=0;
			if(MemoryBuffer[IndexBuffer]==':'&&i==0)
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
					if(RecordType==0x00&&!AddrExtend)
					{
						MontaProg1828();
					}
					else if(RecordType==0x04&&!AddrExtend)
					{
						if(!Programado)
						{
							ProgWord1828();
							if(Address==0)
							{
								for(testex=0;testex<2048;testex++)
									WordProg[testex]=0x3fff;
							}
						}
						AddrExtend=DataHex[1];
					}
					else if(AddrExtend && RecordType==0x00&&Address>=0xe000&&Address<=0xe1ff) 						ProgData1828();
					else if(AddrExtend&&RecordType==0x00&&Address==0x000e)
					{
						Endereco=EnderecoBase;
						delay_50us(10);
						a=DataHex[0];
						b=DataHex[1];
						c=DataHex[2];
						d=DataHex[3];
						ret=VerifyProgMem1828();
						if(!ret&&!AbortaGr)
							{
							DataHex[0]=a;
							DataHex[1]=b;
							DataHex[2]=c;
							DataHex[3]=d;
							ProgConfigMem1828();
							}
						ExitProgMode1828();
						delay_50us(10);
						VDD_GR=false;
						ret=1;
					}
				}
			}
		}while(RecordType!=0x01&&!ret&&!AbortaGr);
	}	
	AbortaGr=false;
	ExitProgMode1828();
	Programado=false;
	PGD_DIR=false;			//hightZ      
	VDD_GR=OFF;
}

void ProgData1828(void)
{
	unsigned int datarec, addr, datateste=0;
	addr=(Address&0x0fff)/2;
	unsigned char i=0;
		
	while(ByteCount) 
	{
		datateste=(unsigned int)DataHex[i+1];
		datateste=((datateste<<8)|(unsigned int)DataHex[i]);
		WordProg[(AddrProg&0x07ff)]=datateste;
		ByteCount -= 2;
		i+=2;
		SendCommand(LOAD_DATA_DATA_MEM,datateste);	// envia word
		SendCommand(BEGIN_PROGRAMMING,0);			// grava byte na EEPROM
		datarec=SendCommand(READ_DATA_DATA_MEM,0);	
		if(datateste!=datarec)	//
		{
			StatusGr=0xf9;			// Erro na gravação
			return(1);
		}
		SendCommand(INCREMENT_ADDRESS,0);					// incrementa PC
	}
}
	
void MontaProg1828(void)
	{
	volatile unsigned int datateste=0;
	unsigned char i=0;

	while(Endereco16F != Address) 
		{
		Endereco16F += 2;
		AddrProg++;
		if((AddrProg&0x07ff)==0x0000) //indice igual a 0x0800
			{
			ProgWord1828();
			for(datateste=0;datateste<2048;datateste++)
				WordProg[datateste]=0x3fff;
			datateste=0;
			}
		}
	Endereco16F += (unsigned int)ByteCount;

	while(ByteCount) 
		{
		datateste=(unsigned int)DataHex[i+1];
		datateste=((datateste<<8)|(unsigned int)DataHex[i]);
		WordProg[(AddrProg&0x07ff)]=datateste;
		ByteCount -= 2;
		i+=2;
		AddrProg++;
if(AddrProg>=0x670)//0x07e0)
{
NoP();
NoP();
NoP();
NoP();
NoP();
NoP();
}
		if((AddrProg&0x07ff)==0x0000) //indice igual a 0x0800
			{
			ProgWord1828();
			for(datateste=0;datateste<2048;datateste++)
				WordProg[datateste]=0x3fff;
			datateste=0;
			}
		}
	}
	
void ProgWord1828(void)
{
	unsigned char wordCount,BlockCount=64;
	unsigned int indice=0,maxdata;
	Programado=true;
	maxdata=AddrProg-1;
	if(maxdata>0x7ff)
		maxdata=maxdata-0x7ff;
	while((indice<=maxdata)&&BlockCount)
	{
		wordCount=32;
		while(wordCount)
		{
			if(WordProg[indice]!=0x3fff)
				SendCommand(LOAD_DATA_PROG_MEM,WordProg[indice]);	// envia word
			wordCount--;
			if(wordCount)
				SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
			indice++;
		}
		SendCommand(BEGIN_PROGRAMMING,0);						// grava as trinta e duas words
		SendCommand(INCREMENT_ADDRESS,0);						// incrementa PC
		BlockCount--;
	}
}
	
unsigned char VerifyProgMem1828(void)
	{
	unsigned char i=0,ix=0;
	volatile unsigned int datateste, AddrFinal, datarec;

	StatusGr=0x03;			// Verificando gravação

	SendCommand(RESET_ADDRESS,0);				// reset PC
	AddrFinal=Endereco16F;
	Endereco16F=0;
	do
		{
		MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
		Endereco+=512;
		IndexBuffer=0;
		if(MemoryBuffer[IndexBuffer]==':'&&i==0)
			IndexBuffer++;
		while(IndexBuffer<512&&(Endereco16F<AddrFinal))
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
							datateste=(unsigned int)DataHex[ix+1];
							datateste=((datateste<<8)|(unsigned int)DataHex[ix]);
							datarec=SendCommand(READ_DATA_PROG_MEM,0);
							if(datateste!=datarec)	//
								{
								StatusGr=0xf3;			// Erro na gravação
								return(1);
								}
							SendCommand(INCREMENT_ADDRESS,0);				// incrementa PC
							ix+=2;
							ByteCount -= 2;
							}
						}
					else
						return 0;
					}
				}
			}
		}while(Endereco16F<AddrFinal);
	return 0;
	}
	
void ProgConfigMem1828(void)
{
	volatile unsigned int datateste, datarec;
	SendCommand(LOAD_CONFIGURATION,0);			// PC > 0x8000
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8001
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8002
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8003
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8004
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8005
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8006
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8007
	datateste=(unsigned int)DataHex[1];
	datateste=((datateste<<8)|(unsigned int)DataHex[0]);
	datateste=datateste&0x3fff;
	SendCommand(LOAD_DATA_PROG_MEM,datateste);	// primeira word
	SendCommand(BEGIN_PROGRAMMING,0);			// grava word de configuração 1
	delay_50us(20);//10);
	datarec=SendCommand(READ_DATA_PROG_MEM,0);
	if(datateste!=datarec)
		StatusGr=0xf4;							// Erro de gravação
	SendCommand(INCREMENT_ADDRESS,0);			// incrementa PC > 0x8008
	datateste=(unsigned int)DataHex[3];					/****** ????? ******/
	datateste=((datateste<<8)|(unsigned int)DataHex[2]);/****** ????? ******/
	datateste=datateste&0x3fff;
	datateste=datateste|0x08fc;
	SendCommand(LOAD_DATA_PROG_MEM,datateste);	// segunda word
	SendCommand(BEGIN_PROGRAMMING,0);			// grava word de configuração 2
	delay_50us(20);//10);
	datarec=SendCommand(READ_DATA_PROG_MEM,0);
	if(datateste!=datarec)
		StatusGr=0xf4;							// Erro de gravação
	else
		StatusGr=0x04;							// Gravação OK
}	
