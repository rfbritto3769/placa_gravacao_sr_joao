#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"
#include "string.h"

unsigned int ReadExecutiveData(void)
	{
	int DataRet = 0;
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x8000;	// bit 15
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x4000;	// bit 14
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x2000;	// bit 13
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x1000;	// bit 12
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0800;	// bit 11
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0400;	// bit 10
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0200;	// bit 9
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0100;	// bit 8
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0080;	// bit 7
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0040;	// bit 6
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0020;	// bit 5
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0010;	// bit 4
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0008;	// bit 3
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0004;	// bit 2
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0002;	// bit 1
	PGC = 1;
	NoP();
	PGC = 0;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0001;	// bit 0
	PGC = 0;

//	PGD_DIR=true;		//output
//	TRISG=TrisGInit;

	return DataRet;
	}
	
// Envia intrução "data"
void SendExecutiveData(unsigned int data) 
{
	PGC = 1;
	if(data & 0x8000)	//bit 15
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x4000)	//bit 14
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x2000)	//bit 13
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x1000)	//bit 12
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0800)	//bit 11
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0400)	//bit 10
	{
		PGD = 1;
		PGC = 1;
	}
	else
		{
		PGD = 0;
		PGC = 1;
		}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0200)	//bit 9
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0100)	//bit 8
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0080)	//bit 7
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0040)	//bit 6
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0020)	//bit 5
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0010)	//bit 4
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0008)	//bit 3
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0004)	//bit 2
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0002)	//bit 1
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
	if(data & 0x0001)	//bit 0
	{
		PGD = 1;
		PGC = 1;
	}
	else
	{
		PGD = 0;
		PGC = 1;
	}
	NoP();
	NoP();
	PGC = 0;
}	

//Le Application ID Word, se retorno==0xbb programa executive esta presente
unsigned char LeAppID(void)
{
	volatile unsigned int AppWord=0, AppWord1=0;
	volatile unsigned char Retorno=0;

	// Step 1: Exit Reset vector
	SendSIX_Command(NOP);
	SendSIX_Command(GOTO_200);
	SendSIX_Command(NOP);
	// Step 2: Initialize TBLPAG and the Read Pointer (W0) for TBLRD instruction
	SendSIX_Command(0x200800);
	SendSIX_Command(0x880190);
	SendSIX_Command(0x205be0);
	SendSIX_Command(0x207841);
	SendSIX_Command(NOP);
	SendSIX_Command(0xba0890);
	SendSIX_Command(NOP);
	SendSIX_Command(NOP);
	// Step 3: Output the VISI register using the REGOUT command
	AppWord = SendREGOUT_Command();
	SendSIX_Command(NOP);
	
	SendSIX_Command(0x205860);
	SendSIX_Command(0x207841);
	SendSIX_Command(NOP);
	SendSIX_Command(0xba0890);
	SendSIX_Command(NOP);
	SendSIX_Command(NOP);
	// Step 3: Output the VISI register using the REGOUT command
	AppWord1 = SendREGOUT_Command();
	SendSIX_Command(NOP);

	if((AppWord==0x002e) && (AppWord1==0x00a9))
		Retorno=0;
	else
		Retorno=1;
	
	return(Retorno);
}

//Grava programa executive na memoria do PIC
void ProgExecutiveProg(void)
{
	volatile unsigned char i=0,ret=0,a,retorno;
	unsigned long BackupEnderecoBase;
//	LastAddr=0;	

	InicializaBloco();
	BackupEnderecoBase=EnderecoBase;
	EnderecoBase=Programa_7;
	Endereco=EnderecoBase;
	StatusGr=0x02;			// Gravação em andamento
	do
	{
		MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
		Endereco+=512;
		IndexBuffer=0;
		if(i==0x00&&MemoryBuffer[IndexBuffer]==':')
			IndexBuffer++;
		while(RecordType!=0x01&&IndexBuffer<512&&ret!=1&&!AbortaGr)
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
				ret=MontaBloco64();
				if(ret)
				{
					if(ret==0xaa)
					{
						StatusGr=0x04;
					}
					else
					{
						StatusGr=0xf3;
						ret=1;
					}
				}
			}
		}
	}while(RecordType!=0x01&&ret!=1&&!AbortaGr&&StatusGr<0x04);

	EnderecoBase=BackupEnderecoBase;
}

//Apaga area do programa executive
void EraseExecutiveProg(void)
{
	unsigned int count;
	volatile unsigned long addr=0;
	unsigned int visi;	// deve ser uma variável de 16bits
	
//	EnterICSP_Mode();
//	LeConfigurationMemory24FJ();

	delay_50us(10);
//Step 1: Exit Reset vector
	SendSIX_Command(NOP);
	SendSIX_Command(GOTO_200);
	SendSIX_Command(NOP);
//Step 2: Initializa pointers to read Diagnostic and Calibration Words for storage in W6-W13
	SendSIX_Command(0x200800);
	SendSIX_Command(0x880190);
	SendSIX_Command(0x207f01);//(0x207f00);
	SendSIX_Command(0x2000c2);
	SendSIX_Command(NOP);
//Step 3: Read Diagnostic and Calibration Words
	count=8;
	do
	{
		SendSIX_Command(0xba1931);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		--count;
	}while(count);
//Step 4: Initializa the NVMCON to erase executive memory
	SendSIX_Command(0x240420);
	SendSIX_Command(0x883b00);
	count=2;
	do
	{
//Step 5: Initializa Erase Pointer to first page of executive and initiate the erase cycle
		SendSIX_Command(0x200800);
		SendSIX_Command(0x880190);
		addr <<= 4;
		addr |= 0x200001;
		SendSIX_Command(addr);	//0x200001);
		SendSIX_Command(NOP);
		SendSIX_Command(0xbb0881);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xa8e761);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
//Step 6: Repeat this step to poll the WR bit (bit 15 of NVMCON) until it is cleared by the hardware
		AguardaWR1();
		addr=0x400;
		--count;
	}while(count); // Step 7: Repeat Steps 5 and 6
// Step 8: 
	SendSIX_Command(0x200800);
	SendSIX_Command(0x880190);
	SendSIX_Command(0x240031);
	SendSIX_Command(0x883b01);
	SendSIX_Command(0x207f01);//(0x207f00);
	SendSIX_Command(0x2000c2);
	SendSIX_Command(NOP);
	count=8;
	do
	{
//Step 9: 
		SendSIX_Command(0xbb18b2);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xa8e761);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
//Step 10: 
		do 
		{
			SendSIX_Command(GOTO_200);
			SendSIX_Command(NOP);
			SendSIX_Command(0x803b00);
			SendSIX_Command(0x883C20);
			SendSIX_Command(NOP);
			visi = SendREGOUT_Command();
			SendSIX_Command(NOP);
		} while(visi & 0x8000);
		--count;
	}while(count); // Step 11:  Repeat Steps 9 and 10
//Step 12
}

//Grava imagem do arquivo HEX na Flash
void Programa24fjExecutiveFlash(void)
{
	volatile unsigned char i=0,ret=0, contador = 0;
	unsigned long Ender;
	unsigned int Temp, address_high = 0, address_low = 0;
	CountBlock=0;
	InicializaBloco();
	FlagExecutive=true;	

	Ender=DestEnder;
	for(i=0;i<32;i++)
	{
		MemoryEraseBlock(Ender);
		Ender+=0x4000;
	}
	i=0;
	RecordType=0x00;
	if(!ret)
	{
		Endereco=EnderecoBase;
		EnderecoFlash=DestEnder;
		ret=0;
		StatusGr=0x2a;			// Gravação em andamento
		do
		{
			MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
			Endereco+=512;
			IndexBuffer=0;
			if(i==0x00&&MemoryBuffer[IndexBuffer]==':')
				IndexBuffer++;
			while(RecordType!=0x01&&IndexBuffer<512&&ret!=1&&!AbortaGr)
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
					ret=MontaBloco64();
					if(ret)
					{
						if(ret==0xaa)
						{
							AddrFlash=EndFinal;//(conf_address1*2)+DestEnder+2;
							Ender=LastAddr & 0xffff0000;
							address_high = (unsigned int*)(Ender >> 16);
							address_low = (unsigned int*)(LastAddr & 0x00ffff);
							contador = 0;
							
							BufferTesteFlash[contador++]=(unsigned char*)(address_low &0x00ff);
							BufferTesteFlash[contador++]=(unsigned char*)((address_low>>8)&0x00ff);
							BufferTesteFlash[contador++]=(unsigned char*)(address_high &0x00ff);
							BufferTesteFlash[contador++]=(unsigned char*)((address_high>>8)&0x00ff);

						// O PIC24FJ128GA106 possui 3 Config Registers, o PIC24FJ64GA104
						// possui 4 Config Registers e os demais possuem 2 Config Registers.
							Temp=cw1;
							BufferTesteFlash[contador++]=(unsigned char*)(Temp &0x00ff);
							BufferTesteFlash[contador++]=(unsigned char*)((Temp>>8)&0x00ff);

							Temp=cw2;
							BufferTesteFlash[contador++]=(unsigned char*)(Temp &0x00ff);
							BufferTesteFlash[contador++]=(unsigned char*)((Temp>>8)&0x00ff);

							if((Processador == PIC_24FJ128GA106) || (Processador == PIC_24FJ64GA104))
							{
								Temp=cw3;
								BufferTesteFlash[contador++]=(unsigned char*)(Temp &0x00ff);
								BufferTesteFlash[contador++]=(unsigned char*)((Temp>>8)&0x00ff);
							}

							if(Processador == PIC_24FJ64GA104)
							{
								Temp=cw4;
								BufferTesteFlash[contador++]=(unsigned char*)(Temp &0x00ff);
								BufferTesteFlash[contador++]=(unsigned char*)((Temp>>8)&0x00ff);
							}

							BufferTesteFlash[contador++]=VersaoSW[NumProg][0];
							BufferTesteFlash[contador++]=VersaoSW[NumProg][1];
							BufferTesteFlash[contador++]=VersaoSW[NumProg][2];
							BufferTesteFlash[contador]=Processador;

							MemoryWriteSector(AddrFlash, BufferTesteFlash);
							MemoryReadSector(AddrFlash, BufferTeste);
						}
					}
				}
			}
		}while(RecordType!=0x01&&ret!=1&&!AbortaGr&&StatusGr<0x2f);
	}
}
	
void VerifyExecutive(void)
{
	unsigned int  cont=0;

	// Step 1: 
	SendSIX_Command(NOP);
	SendSIX_Command(GOTO_200);
	SendSIX_Command(NOP);

	// Step 2: 
	SendSIX_Command(0x200800);
	SendSIX_Command(0x880190);
	SendSIX_Command(0xeb0300);

	// Step 3: 
	SendSIX_Command(0x207847);
	SendSIX_Command(NOP);
	
	do
	{
		// Step 4: 
		SendSIX_Command(0xba0b96);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		MemoryBuffer[cont] = SendREGOUT_Command();
		cont++;
		
		SendSIX_Command(NOP);
		SendSIX_Command(0xbadbb6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xbad3d6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		MemoryBuffer[cont] = SendREGOUT_Command();
		cont++;
		
		SendSIX_Command(NOP);
		SendSIX_Command(0xba0bb6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		MemoryBuffer[cont] = SendREGOUT_Command();
		SendSIX_Command(NOP);
		cont++;
		// Step 5 : 
		SendSIX_Command(GOTO_200);
		SendSIX_Command(NOP);
	}while(cont<1024);
}
	
// Programa o PIC24 utilizando o programa executive
void ProgExecutive24FJ(void)
{
	volatile unsigned char i=0,ret=0,a,retorno;
	LastAddr=0;	
	StatusGr=0x01;			// Apagando
	PGC=false;
	PGD=false;
	OE_U2=false;			//hightZ
	OE_U5=true;				//output
	PGD_DIR=true;			//output
	Vpp_3V();
	Vdd_3V();				//Seta alimentação para 3V3
	ret=0;
	ContError=0;
	
	ret=EnterICSP_Mode();
	if(!ret)
	{
		SendSIX_startup();
		LeConfigurationMemory24FJ();
		ret=0;
		Flag_Addr=false;
		ChipErase();
		delay_50us(400);
		retorno=LeAppID();
		if(!retorno)
		{
			ExitICSP_Mode();
			FlagExecutive=true;	
			ret=EnterICSP_Mode();
			if(!ret)
				ret=BlockProgramCycleExecutive();
		}
		else
		{
			FlagProg=true;
			EraseExecutiveProg();	//Apaga area do programa executive
			FlagExecutiveProg=true;
			ProgExecutiveProg();	//Grava programa executive na memoria do PIC
			FlagProg=false;
			StatusGr=0x01;			// Apagando
			retorno=LeAppID();
			if(!retorno)
			{
				ExitICSP_Mode();
				FlagExecutive=true;	
				ret=EnterICSP_Mode();
				if(!ret)
					ret=BlockProgramCycleExecutive();
			}
			else
				StatusGr=0xfb;			// Falha no programa executive
		}
	}	
	FlagExecutiveProg=false;	
	AbortaGr=false;
	ExitICSP_Mode();
	PGD_DIR=false;			//hightZ
	OE_U2=false;			//hightZ
	OE_U5=false;			//hightZ
	RecordType=0x00;
}
	
// Escreve na memória de programa do PIC, em blocos com 64 instruções
unsigned char BlockProgramCycleExecutive()
{
	volatile unsigned int EnderAlto = 0, EnderBaixo = 0, indice, Data;
	volatile unsigned int Config1, Config2, Config3, Config4, testexy=0;
	volatile unsigned long AtualAddr;
	unsigned char ret = 0, index, MicroProcessador, contador;

	StatusGr=0x02;			// Gravação em andamento

	AddrFlash=EndFinal;//(conf_address1*2)+EnderecoBase+2;
	MemoryReadSector(AddrFlash, BufferTesteFlash);

	Data=BufferTesteFlash[1];
	Data=Data<<8;
	Data=Data | BufferTesteFlash[0];
	EnderBaixo=Data;
	Data=BufferTesteFlash[3];
	Data=Data<<8;
	Data=Data | BufferTesteFlash[2];
	EnderAlto=Data;
	LastAddr=EnderAlto;
	LastAddr=((LastAddr << 16) & 0xffff0000) | EnderBaixo;
	
	Config1 = BufferTesteFlash[5];
	Config1 = ((Config1 << 8) & 0xff00) | BufferTesteFlash[4];

	Config2 = BufferTesteFlash[7];
	Config2 = ((Config2 << 8) & 0xff00) | BufferTesteFlash[6];

	contador = 8;

	if((Processador == PIC_24FJ128GA106) || (Processador == PIC_24FJ64GA104))
	{
		Config3 = BufferTesteFlash[9];
		Config3 = ((Config3 << 8) & 0xff00) | BufferTesteFlash[8];
	
		contador = 10;
	}

	if(Processador == PIC_24FJ64GA104)
	{
		Config4 = BufferTesteFlash[11];
		Config4 = ((Config4 << 8) & 0xff00) | BufferTesteFlash[10];

		contador = 12;
	}

	VersaoSW[NumProg][0]=BufferTesteFlash[contador++];
	VersaoSW[NumProg][1]=BufferTesteFlash[contador++];
	VersaoSW[NumProg][2]=BufferTesteFlash[contador++];
	MicroProcessador=BufferTesteFlash[contador];

	AddrFlash=EnderecoBase;//Endereco para gravação na Flash
	do
	{	
		MemoryReadSector(AddrFlash, BufferTesteFlash);
		testexy++;
		index=0;
		indice=0;
		do
		{
			if(BufferTesteFlash[indice+1]!=0xff)
			{
				Data=BufferTesteFlash[indice+1];
				Data=Data<<8;
				Data=Data | BufferTesteFlash[indice];
				EnderAlto=Data;
				Data=BufferTesteFlash[indice+3];
				Data=Data<<8;
				Data=Data | BufferTesteFlash[indice+2];
				EnderBaixo=Data;
				indice += 4;
	
				AtualAddr=EnderAlto;
				AtualAddr=((AtualAddr << 16) & 0xffff0000) | EnderBaixo;
				ret=ProgramaBloco(EnderAlto, EnderBaixo, indice);
			}
			indice=256;
			index++;
		}while(!ret && (index<2));
		AddrFlash +=512;
	}while(!ret && (AtualAddr < LastAddr) && (AddrFlash < EndFinal));
	if(!ret)
	{
		StatusGr=0x03;		// gravação do config
		ret=ProgramaConfigBit(Config1, Config2, Config3, Config4);
		if(ret)
			StatusGr=0xf4;	// erro gravação do config
		else
			StatusGr=0x04;	// gravação OK
	}
	else
		StatusGr=0xf3;		// erro gravação da memoria
		
	return(ret);
}
	
unsigned char ProgramaConfigBit(unsigned int Cw_1, unsigned int Cw_2, unsigned int Cw_3, unsigned int Cw_4)
{
	volatile unsigned int EnderAlto = 0, EnderBaixo = 0, Retorno[2];
	volatile unsigned long AtualAddr;
	unsigned char Counter, Counter2;

	packed_instructions[0] = conf_address1;
	packed_instructions[1] = conf_address2;
	packed_instructions[2] = conf_address3;
	packed_instructions[3] = conf_address4;

	WordProg[0] = Cw_1;
	WordProg[1] = Cw_2;
	WordProg[2] = Cw_3;
	WordProg[3] = Cw_4;
	
	switch(Processador)
	{
	//----------------
		default:
			Counter2=2;
		break;
	//----------------
		case PIC_24FJ128GA106:
			Counter2=3;
		break;
	//----------------
		case PIC_24FJ64GA104:
			Counter2=4;
		break;
	//----------------
	}

	for(Counter=0;Counter<Counter2;Counter++)
	{
		AtualAddr = packed_instructions[Counter] & 0xffff0000;
		EnderAlto = (AtualAddr >> 16) & 0x0000ffff;
		EnderBaixo = packed_instructions[Counter] & 0x0000ffff;
		
		SendExecutiveData(0xd004); //comando PROGW
		SendExecutiveData(EnderAlto); //
		SendExecutiveData(EnderBaixo); //
		SendExecutiveData(WordProg[Counter]); //
		PGD_DIR=false;		//input
		TRISG=TrisGInp;
		LoopFlash=30;
		while(LoopFlash<=30);
		if(PGD_IN)
			while(PGD_IN);
		LoopFlash=2;
		while(LoopFlash<=2);
		Retorno[0]=ReadExecutiveData();
		NoP();
		Retorno[1]=ReadExecutiveData();
		PGD_DIR=true;		//output
		TRISG=TrisGInit;
		LoopFlash=2;
		while(LoopFlash<=2);
		if(Retorno[0]!=0x1d00)
			return(1);
	}
	return(0);
}
	
unsigned char ProgramaBloco(unsigned int AddressHigh, unsigned int AddressLow, unsigned int indice)
{
	volatile unsigned int Data, Retorno[2];
	volatile unsigned char counter = 16, index = 0, i=0;
	
	SendExecutiveData(0x5063); //comando PROGP
	NoP();
	SendExecutiveData(AddressHigh);
	NoP();
	SendExecutiveData(AddressLow);

	while(counter--) 
	{
		// with the next 4 instruction words to program
		do
		{
			Data=BufferTesteFlash[indice+1];
			Data=Data<<8;
			Data=Data | BufferTesteFlash[indice];
			indice+=2;
			packed_instructions[i]=Data;
			i++;
		}while( i<=5);
		i=0;
		
		SendExecutiveData(packed_instructions[0]);
		NoP();
		SendExecutiveData(packed_instructions[1]);
		NoP();
		SendExecutiveData(packed_instructions[2]);
		NoP();
		SendExecutiveData(packed_instructions[3]);
		NoP();
		SendExecutiveData(packed_instructions[4]);
		NoP();
		SendExecutiveData(packed_instructions[5]);
	}

	PGD_DIR=false;		//input
	TRISG=TrisGInp;
	LoopFlash=5;//20;
	while(LoopFlash<=5);//20);
	if(PGD_IN)
		while(PGD_IN);
	LoopFlash=2;
	while(LoopFlash<=2);
	Retorno[0]=ReadExecutiveData();
	NoP();
	Retorno[1]=ReadExecutiveData();
	PGD_DIR=true;		//output
	TRISG=TrisGInit;
	if(Retorno[0]==0x1500)
		return(0);
	else
		return(1);
}

// Escreve na memória flash o software em binario
unsigned char BlockProgramFlash(unsigned long *instr, unsigned int endereco_dest)
{
	volatile unsigned int address_high = 0, address_low = 0, Data[2],i,ix,iw=0, temp;
	volatile unsigned long Temporario=0;
	unsigned char counter = 16, ret, index = 0;//, teste[512];//xyz=0;
	volatile unsigned char teste[512];
	
	LED_LD2=~LED_LD2;
		
	Temporario = TesteDebug & 0x00ff0000;
	address_high = (unsigned int*)(Temporario >> 16);//12

	address_low = (unsigned int*)(TesteDebug & 0x0000ffff);
	
	AddrFlash=(TesteDebug*2)+DestEnder;
	

	WordProg[0]=address_high;
	WordProg[1]=address_low;
	ContPacked=2;
	
	if(TesteDebug>LastAddr)
		LastAddr=TesteDebug;
	for(i=0;i<512;i++)
	{
		BufferTesteFlash[i]=0xff;
		teste[i]=0xff;
	}

	while(counter--) 
	{
		// with the next 4 instruction words to program
		PackInstructions(packed_instructions, &instr[index]);
		index += 4;
	}
	ix=0;
	i=(char*)((TesteDebug&0x000000ff)*2);
	if(!i)
		ix=256;

	do
	{
		temp=WordProg[iw];
		BufferTesteFlash[i]=(unsigned char*)(temp &0x00ff);
		i++;
		BufferTesteFlash[i]=(unsigned char*)((temp>>8)&0x00ff);
		iw++;
		i++;
	}while((i+ix)<512);

	CountBlock++;
	MemoryWriteSector(AddrFlash, BufferTesteFlash);
	MemoryReadSector(AddrFlash, teste);
	
	i=0;
	do
	{
		if((BufferTesteFlash[i]!=0xff) && (teste[i]!=BufferTesteFlash[i]))
		{
			return(1);
		}	
		i++;
	}while(i<196);
	return(0);
}
