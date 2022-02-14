/*
 * File:   grava_pic16f15344.c
 * Author: Rodrigo
 *
 * Created on 8 de Outubro de 2020, 08:07
 */


#include <xc.h>
#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"
////////////////////////////////////////////////////////////////////////////////
#define  ISP_CLK_DELAY  1
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
unsigned char p16c_enter_progmode(void)
	{
	PGC=false;
	PGD=false;
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(20);
	Vpp_GND_OFF();
	VPP=ON;
	delay_50us(30);//30
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
////////////////////////////////////////////////////////////////////////////////
void isp_send_8_msb (unsigned char data)
{
unsigned char i;
PGD_DIR=true;		//output
TRISG=TrisGInit;
//_delay_us(3*ISP_CLK_DELAY);
for (i=0;i<8;i++)
  {
  if (data&0x80)//0x80
    {
      PGD=1;
    }
  else
    {
      PGD=0;
    }
  
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
 //// delay_50us(ISP_CLK_DELAY);
  PGC=1;
  /////delay_50us(ISP_CLK_DELAY);
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  
  data = data << 1;
  PGC=0;
  PGD=0;
//  _delay_us(ISP_CLK_DELAY);
  }
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
void isp_send_24_msb (unsigned long data)
{
unsigned char i;
PGD_DIR=true;		//output
TRISG=TrisGInit;
//_delay_us(3*ISP_CLK_DELAY);
for (i=0;i<23;i++)
  {
  if (data&0x400000)
    {
      PGD=1;
    }
  else
    {
      PGD=0;
    }
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  PGC=1;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();

  data = data << 1;
  PGC=0;
//  _delay_us(ISP_CLK_DELAY);
  }
  PGD=0;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  

  PGC=1;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();

  PGC=0;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int isp_read_8_msb (void)
{
unsigned char i;
unsigned int out;
out = 0;
TRISG=TrisGInp;
PGD_DIR=false;		//input
//_delay_us(3*ISP_CLK_DELAY);
for (i=0;i<8;i++)
  {
    PGC=1;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  
   PGC=0;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  
  out = out << 1;
  if (PGD_IN)
    out = out | 0x1;
  }
PGD_DIR=true;		//output
TRISG=TrisGInit;
 return out;
}
////////////////////////////////////////////////////////////////////////////////
unsigned int isp_read_16_msb (void)
{
unsigned char i;
unsigned int out;
out = 0;
TRISG=TrisGInp;
PGD_DIR=false;		//input
//_delay_us(3*ISP_CLK_DELAY);
for (i=0;i<16;i++)
  {
   PGC=1;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  
   PGC=0;
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  
  out = out << 1;
  if (PGD_IN)
    out = out | 0x1;
  }
PGD_DIR=true;		//output
TRISG=TrisGInit;
 return out;
}
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
void p16c_set_pc (unsigned long pc)
{
  isp_send_8_msb(0x80);
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  

  
  isp_send_24_msb(pc); 
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();

}
////////////////////////////////////////////////////////////////////////////////
void p16c_bulk_erase (void)
{
  isp_send_8_msb(0x18);
  if(adapt_224==1)
  {
  delay_50us(150);//100
  }else
  {
  delay_50us(100);
  }
}
////////////////////////////////////////////////////////////////////////////////
void p16c_load_nvm (unsigned char inc, unsigned int data)
{
  if (inc==0) isp_send_8_msb(0x00);
  else isp_send_8_msb(0x02);
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
 
  isp_send_24_msb(data);
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  

  }
////////////////////////////////////////////////////////////////////////////////
unsigned int p16c_read_data_nvm (unsigned char inc)
{
  unsigned int retval;
  unsigned char tmp;
  if (inc==0) isp_send_8_msb(0xFC);
  else isp_send_8_msb(0xFE);
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  
 
  tmp = isp_read_8_msb();
  retval = isp_read_16_msb();
  retval = retval >> 1;
  if (tmp&0x01) retval = retval | 0x8000;
  return retval;
  }
////////////////////////////////////////////////////////////////////////////////
void p16c_begin_prog (unsigned char cfg_bit)
{
  isp_send_8_msb(0xE0);
   NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
   NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
   NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  NoP();
  ////delay_50us(60);  //60  10
  //if (cfg_bit!=0) delay_50us(60); //60
  }
////////////////////////////////////////////////////////////////////////////////
unsigned int p16c_get_ID (void)
{
  p16c_set_pc(0x8006);
  return p16c_read_data_nvm(1);
  }
////////////////////////////////////////////////////////////////////////////////
void p16c_isp_write_pgm (unsigned int * data, unsigned long addr, unsigned char n)
{
unsigned char i;
//_delay_us(3*ISP_CLK_DELAY);
p16c_set_pc(addr);
for (i=0;i<n;i++)  
  p16c_load_nvm(1 , data[i]);  
p16c_set_pc(addr);
p16c_begin_prog(0);
}
////////////////////////////////////////////////////////////////////////////////
void p16c_isp_read_pgm (unsigned int * data, unsigned long addr, unsigned char n)
{
unsigned char i;
unsigned int tmp1,tmp2;
//_delay_us(3*ISP_CLK_DELAY);
p16c_set_pc(addr);
for (i=0;i<n;i++)  
  data[i] = p16c_read_data_nvm(1);
}
////////////////////////////////////////////////////////////////////////////////
void isp_inc_pointer (void)
{
//_delay_us(3*ISP_CLK_DELAY);
isp_send_8_msb(0xf8);
//isp_send(0xf8,6);
}
////////////////////////////////////////////////////////////////////////////////
void ExitWordMode344_1(void) 
	{
	PGC=false;
	PGD=false;
	delay_50us(10);
	VPP=OFF;
	Vpp_GND_OFF();
	delay_50us(10);
	}
////////////////////////////////////////////////////////////////////////////////
unsigned char EnterProgMode344_xx(void)
	{
	PGC=false;
	PGD=false;
	VPP=OFF;
	Vpp_GND_ON();
	delay_50us(20);
	Vpp_GND_OFF();
	VPP=ON;
	delay_50us(30);//30
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
////////////////////////////////////////////////////////////////////////////////
void MontaHeader_1(unsigned char *linha) 
	{
	unsigned char index, i=0;
	
	ClrWdt();

	ByteCount = CharToHex(*linha++) << 4;
	ByteCount |= CharToHex(*linha++);
	Address = (unsigned int)CharToHex(*linha++) << 12;
	Address |= (unsigned int)CharToHex(*linha++) << 8;
	Address |= (unsigned int)CharToHex(*linha++) << 4;
	Address |= (unsigned int)CharToHex(*linha++);
	RecordType = CharToHex(*linha++) << 4;
	RecordType |= CharToHex(*linha++);
	
	index = ByteCount;
	for(i=0;i<16;i++)
		DataHex[i]=0xff;
	i=0;

	while (index--) 
		{
		DataHex[i] = CharToHex(*linha++) << 4;
		DataHex[i] |= CharToHex(*linha++);
		i++;
		}
	}
////////////////////////////////////////////////////////////////////////////////
void MontaProg344_1(void)
	{
	volatile unsigned int datateste=0;
	unsigned char i=0;

	while(Endereco16F != Address) 
		{
		Endereco16F += 2;
		AddrProg++;
		if((AddrProg&0x07ff)==0x0000) //indice igual a 0x0800
			{
			ProgWord344_1();
//			for(datateste=0;datateste<2048;datateste++)
//				WordProg[datateste]=0x3fff;
//			datateste=0;
			}
		}
	Endereco16F += (unsigned int)ByteCount;

	while(ByteCount) 
		{
		datateste=(unsigned int)DataHex[i+1];
        //datateste=((DataHex[i+1]<<8)|(unsigned int)DataHex[i]);
		datateste=((datateste<<8)|(unsigned int)DataHex[i]);
        //datateste =((unsigned int)DataHex[i]<<8)|(unsigned int)DataHex[i+1];
      
		WordProg[(AddrProg&0x07ff)]=datateste;
        //WordProg[(AddrProg)]=datateste;
		ByteCount -= 2;
		i+=2;
		AddrProg++;
//if(AddrProg>=0x670)//0x07e0)
//{
//NoP();
//NoP();
//NoP();
//NoP();
//NoP();
//NoP();
//}
		if((AddrProg&0x07ff)==0x0000) //indice igual a 0x0800
			{
			ProgWord344_1();
//			for(datateste=0;datateste<2048;datateste++)
//				WordProg[datateste]=0x3fff;
//			datateste=0;
			}
		}
	}
////////////////////////////////////////////////////////////////////////////////
void ProgWord344_1(void)
{
	unsigned char wordCount,BlockCount=64;
	unsigned int indice=0,maxdata;
    ////uint16_t seta_pc=0;
	Programado=true;
    ////p16c_set_pc(0x0000);//
	maxdata=AddrProg-1;
	if(maxdata>0x7ff)
		maxdata=maxdata-0x7ff;
	while((indice<=maxdata)&&BlockCount)
	{
		wordCount=32;
		while(wordCount)
		{
			if(WordProg[indice]!=0x3fff)
                p16c_load_nvm (0,WordProg[indice]);
				//SendCommand_344(LOAD_DATA_PROG_MEM_344,WordProg[indice]);	// envia word
			wordCount--;
			if(wordCount)
                isp_inc_pointer();
				//SendCommand_344(INCREMENT_ADDRESS_344,0);				// incrementa PC
                
			indice++;
		}
		//SendCommand_344(BEGIN_PROGRAMMING_344,0);						// grava as trinta e duas words
       ///// p16c_set_pc(seta_pc);
        p16c_begin_prog(0);
        ////seta_pc=seta_pc+32;
        isp_inc_pointer();
		//SendCommand_344(INCREMENT_ADDRESS_344,0);						// incrementa PC
		BlockCount--;
	}
}
////////////////////////////////////////////////////////////////////////////////
unsigned char VerifyProgMem344_1(void)
	{
	unsigned char i=0,ix=0;
	volatile unsigned int datateste, AddrFinal, datarec;

	StatusGr=0x03;			// Verificando gravação

	//// britto SendCommand(RESET_ADDRESS,0);				// reset PC
    p16c_set_pc(0x0000);
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
				MontaHeader_1(BufferLine);
				if(RecordType==0x00)
					{
					if(Address != 0x400E)
						{
						while(Endereco16F != Address) 
							{
							Endereco16F += 2;
							//SendCommand_344(INCREMENT_ADDRESS_344,0);				// incrementa PC
                            isp_inc_pointer();
							}
							
						Endereco16F += (unsigned int)ByteCount;
						
						while(ByteCount) 
							{
							datateste=(unsigned int)DataHex[ix+1];
							datateste=((datateste<<8)|(unsigned int)DataHex[ix]);
							datarec = p16c_read_data_nvm(0);//SendCommand_344(READ_DATA_PROG_MEM_344,0);
                            /////p16c_isp_read_pgm (&datarec, &datateste, 1);
							if(datateste!=datarec)	//
								{
								StatusGr=0xf3;			// Erro na gravação
								return(1);
								}
							//SendCommand_344(INCREMENT_ADDRESS_344,0);				// incrementa PC
                            isp_inc_pointer();
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
////////////////////////////////////////////////////////////////////////////////
void ProgConfigMem344_1(void)
{
	volatile unsigned int datateste, datarec;
	//// britto SendCommand(LOAD_CONFIGURATION,0);			// PC > 0x8000
//    isp_inc_pointer();
//    isp_inc_pointer();
//    isp_inc_pointer();
//    isp_inc_pointer();
//    isp_inc_pointer();
//    isp_inc_pointer();
//    isp_inc_pointer();
    p16c_set_pc(0x8007);
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8001
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8002
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8003
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8004
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8005
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8006
//	SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8007
	datateste=(unsigned int)DataHex[1];
	datateste=((datateste<<8)|(unsigned int)DataHex[0]);
	datateste=datateste&0x3fff;
	//SendCommand_344(LOAD_DATA_PROG_MEM_344,datateste);	// primeira word
    p16c_load_nvm (0 ,datateste);
	//SendCommand_344(BEGIN_PROGRAMMING_344,0);			// grava word de configuração 1
    p16c_begin_prog(0);
	delay_50us(20);//10);
	datarec=p16c_read_data_nvm(0);//SendCommand_344(READ_DATA_PROG_MEM_344,0);
   
	if(datateste!=datarec)
		StatusGr=0xf4;							// Erro de gravação
    isp_inc_pointer();
	//SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8008
	datateste=(unsigned int)DataHex[3];					/****** ????? ******/
	datateste=((datateste<<8)|(unsigned int)DataHex[2]);/****** ????? ******/
	datateste=datateste&0x3fff;
	datateste=datateste|0x08fc;
    p16c_load_nvm (0 , datateste);
	//SendCommand_344(LOAD_DATA_PROG_MEM_344,datateste);	// segunda word
	//SendCommand_344(BEGIN_PROGRAMMING_344,0);			// grava word de configuração 2
    p16c_begin_prog(0);
	delay_50us(20);//10);
	datarec= p16c_read_data_nvm(0);//SendCommand_344(READ_DATA_PROG_MEM_344,0);
	if(datateste!=datarec)
		StatusGr=0xf4;							// Erro de gravação
////	else
////		StatusGr=0x04;							// Gravação OK
    
    isp_inc_pointer();
	//SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x8009
	datateste=(unsigned int)DataHex[5];					/****** ????? ******/
	datateste=((datateste<<8)|(unsigned int)DataHex[4]);/****** ????? ******/
	datateste=datateste&0x3fff;
	datateste=datateste|0x08fc;
    p16c_load_nvm (0 , datateste);
	//SendCommand_344(LOAD_DATA_PROG_MEM_344,datateste);	// segunda word
	//SendCommand_344(BEGIN_PROGRAMMING_344,0);			// grava word de configuração 2
    p16c_begin_prog(0);
	delay_50us(20);//10);
	datarec= p16c_read_data_nvm(0);//SendCommand_344(READ_DATA_PROG_MEM_344,0);
	if(datateste!=datarec)
		StatusGr=0xf4;							// 
    
    isp_inc_pointer();
	//SendCommand_344(INCREMENT_ADDRESS_344,0);			// incrementa PC > 0x800A
	datateste=(unsigned int)DataHex[7];					/****** ????? ******/
	datateste=((datateste<<8)|(unsigned int)DataHex[6]);/****** ????? ******/
	datateste=datateste&0x3fff;
	////datateste=datateste|0x08fc; britto 10022022
    p16c_load_nvm (0 , datateste);
	//SendCommand_344(LOAD_DATA_PROG_MEM_344,datateste);	// segunda word
	//SendCommand_344(BEGIN_PROGRAMMING_344,0);			// grava word de configuração 2
    p16c_begin_prog(0);
	delay_50us(20);//10);
	datarec= p16c_read_data_nvm(0);//SendCommand_344(READ_DATA_PROG_MEM_344,0);
	if(datateste!=datarec)
    {
        StatusGr=0xf4;	}
    else {
        StatusGr=0x04;
        }
    
   
}
////////////////////////////////////////////////////////////////////////////////
void ProgData344_1(void)
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
		//// britto SendCommand(LOAD_DATA_DATA_MEM,datateste);	// envia word
		//SendCommand_344(BEGIN_PROGRAMMING_344,0);			// grava byte na EEPROM
        p16c_load_nvm (0 , datateste);
         p16c_begin_prog(0);
		///// brittodatarec=SendCommand(READ_DATA_DATA_MEM,0);	
		if(datateste!=datarec)	//
		{
			StatusGr=0xf9;			// Erro na gravação
			return(1);
		}
//		//SendCommand_344(INCREMENT_ADDRESS_344,0);					// incrementa PC
        isp_inc_pointer();
	}
}
////////////////////////////////////////////////////////////////////////////////
void ExitProgMode344_1(void) 
	{
	PGC=false;
	PGD=false;
	delay_50us(10);
	VPP=OFF;
	Vpp_GND_OFF();
	delay_50us(10);
       
//ISP_MCLR_1
//_delay_ms(30);
//ISP_MCLR_0
//_delay_ms(30);
//ISP_MCLR_1
	}

////////////////////////////////////////////////////////////////////////////////
void grava_pic16f15344(void)
{
    unsigned int addr,data_rec;
	unsigned char ret=0;
    unsigned int teste_data;
    
    unsigned char i=0,a,b,c,d,ee,ff,gg,hh,AddrExtend=0;
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
	delay_50us(500);	//400);
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
    EnterProgMode344_xx();
    
 
    //data_rec = p16c_get_ID();
 
    p16c_bulk_erase();
    
   //// p16c_isp_read_pgm (&data_rec, 0x10, 1);
    		for(addr=0;addr<=MaxMemory;addr++)
			{
			//p16c_isp_read_pgm (&data_rec, 0, 1);
            p16c_isp_read_pgm (&data_rec, addr, 1);
	
            if(data_rec!=0x3fff)
				{
				StatusGr=0xf1;			// Erro no apagamento
				return(1);//1
				}
			
			}
    

    StatusGr=0xf4;

    IEC0bits.T1IE=0;
////teste escrita na flash do target    
    uint16_t p = 0;
    uint8_t size=10;
    uint16_t dado[10]={0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a};
    
    p16c_set_pc(0x0000);
 ////  p16c_isp_write_pgm(dado,p,10);
    for(p=0;p<size;p++)
    {
        p16c_load_nvm(1,dado[p]); 
      //  isp_inc_pointer(); 
    }
   
    p16c_set_pc(0x0000);
    p16c_begin_prog(0);
    
   
//    delay_50us(100);
//    p16c_set_pc(0x0000);
//    for(addr=0;addr<=size;addr++)
//			{
//			p16c_isp_read_pgm (&teste_data, addr, 1);
//            if(teste_data!=0x0000)
//            {
//                StatusGr=0xf1;			// Erro no apagamento
//				return(1);//1
//            }
//	}
    
    ExitProgMode344_1();
	delay_50us(10);
	VDD_GR=false;
    
    while(1);//////////
    		
       //// SendCommand_344(LOAD_PC_344,0);
    if(!ret)
	{
        p16c_set_pc(0x0000);
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
					MontaHeader_1(BufferLine);
					if(RecordType==0x00&&!AddrExtend)
					{
						MontaProg344_1();
					}
					else if(RecordType==0x04&&!AddrExtend)
					{
						if(!Programado)
						{
							ProgWord344_1();
							if(Address==0)
							{
								for(testex=0;testex<2048;testex++)
									WordProg[testex]=0x3fff;
							}
						}
						AddrExtend=DataHex[1];
					}
					else
                        if(AddrExtend && RecordType==0x00&&Address>=0xe000&&Address<=0xe1ff) 	
                        {
                            ProgData344_1();
                        }
					else 
                        if(AddrExtend&&RecordType==0x00&&Address==0x000e)
					{
						Endereco=EnderecoBase;
						delay_50us(10);
						a=DataHex[0];
						b=DataHex[1];
						c=DataHex[2];
						d=DataHex[3];
                        ee=DataHex[4];
						ff=DataHex[5];
						gg=DataHex[6];
						hh=DataHex[7];
					   ret=VerifyProgMem344_1();
						if(!ret&&!AbortaGr)
							{
							DataHex[0]=a;
							DataHex[1]=b;
							DataHex[2]=c;
							DataHex[3]=d;
                            DataHex[4]=ee;
							DataHex[5]=ff;
							DataHex[6]=gg;
							DataHex[7]=hh;
							ProgConfigMem344_1();
							}
						ExitProgMode344_1();
						delay_50us(10);
						VDD_GR=false;
						ret=1;
					}
				}
			}
		}while(RecordType!=0x01&&!ret&&!AbortaGr);
    }
//	AbortaGr=false;
//	ExitProgMode344_1();
//	Programado=false;
//	PGD_DIR=false;			//hightZ      
//	VDD_GR=OFF;
    
}