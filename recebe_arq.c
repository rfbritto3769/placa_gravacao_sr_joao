#include "define_gr.h"
#include "global_gr.h"
#include "p24fj128ga006.h"
#include "PIC_Prog_16F.h"

void ProcessaArquivo(void)
	{
	unsigned int IndexBufferU2;
	unsigned char count_z=1;
/************************************************************/
	do 
		{
		if(ReceiverState==0)
			{
			TempHex=(CharToHex(buffer_U2[count_z]));
			count_z++;
			CheckSum+=TempHex;
			}
		else
			{
			TempHex=(CharToHex(buffer_U2[count_z]) << 4);
			count_z++;
			TempHex|=(CharToHex(buffer_U2[count_z]));
			count_z++;
			CheckSum+=TempHex;
			}
		}while(count_z<(count_byte_rx_U2-2));
/************************************************************/
	TempHex=(CharToHex(buffer_U2[count_byte_rx_U2-2]) << 4);
	TempHex|=(CharToHex(buffer_U2[count_byte_rx_U2-1]));
	CheckSum=(~CheckSum)+1;
	if(CheckSum==TempHex)	//||ReceiverState==1)
		{
		bus_tx_buffer_U2[0]=0x0c;
		num_bytes_U2=1;
		switch(ReceiverState)
			{
			case 0 :
				StatusGr=0x1b;
				DestEnder=0xffffffff;
				if(buffer_U2[8]=='6')
					{
					EnderecoBase=Programa_1;
					NumProg=0;
					EndFinal=EndFinal_1;
					}		
				else if(buffer_U2[8]=='7')
					{
					EnderecoBase=Programa_2;
					NumProg=1;
					EndFinal=EndFinal_2;
					}		
				else if(buffer_U2[8]=='8')
					{
					EnderecoBase=Programa_3;
					NumProg=2;
					EndFinal=EndFinal_3;
					}		
				else if(buffer_U2[8]=='9')
					{
					EnderecoBase=Programa_4;
					NumProg=3;
					EndFinal=EndFinal_4;
					}		
/************************************************************/
				else if(buffer_U2[8]=='A')
					{
					DestEnder=Programa_1;
					EnderecoBase=Programa_5;
					NumProg=0;
					EndFinal=EndFinal_1;
					}
				else if(buffer_U2[8]=='B')
					{
					DestEnder=Programa_2;
					EnderecoBase=Programa_5;
					NumProg=1;
					EndFinal=EndFinal_2;
					}
				else if(buffer_U2[8]=='C')
					{
					DestEnder=Programa_3;
					EnderecoBase=Programa_5;
					NumProg=2;
					EndFinal=EndFinal_3;
					}
				else if(buffer_U2[8]=='D')
					{
					DestEnder=Programa_4;
					EnderecoBase=Programa_5;
					NumProg=3;
					EndFinal=EndFinal_4;
					}
				VersaoSW[NumProg][0]=buffer_U2[5];
				VersaoSW[NumProg][1]=buffer_U2[6];
				VersaoSW[NumProg][2]=buffer_U2[7];
				Processador=(CharToHex(buffer_U2[3]) << 4);
				Processador|=(CharToHex(buffer_U2[4]));
				if((buffer_U2[8]=='D') && (VersaoSW[NumProg][0]=='F') && (VersaoSW[NumProg][1]=='F') && (VersaoSW[NumProg][2]=='F'))
					{
					DestEnder=0xffffffff;
					EnderecoBase=Programa_7;
					NumProg=0xaa;
					}
/************************************************************/
				conf_address3 = 0x0000000;
				switch(Processador) 
					{
					case PIC_24FJ16:
						conf_address1 = 0x002BFE;
						conf_address2 = 0x002BFC;
						break;
					case PIC_24FJ32:
						conf_address1 = 0x0057FE;
						conf_address2 = 0x0057FC;
						break;
					case PIC_24FJ48:
						conf_address1 = 0x0083FE;
						conf_address2 = 0x0083FC;
						break;
					case PIC_24FJ64:
						conf_address1 = 0x00ABFE;
						conf_address2 = 0x00ABFC;
						break;
					case PIC_24FJ64GA104:
						conf_address1 = 0x00ABFE;
						conf_address2 = 0x00ABFC;
						conf_address3 = 0x00ABFA;
						conf_address4 = 0x00ABF8;
						break;
					case PIC_24FJ96:
						conf_address1 = 0x00FFFE;
						conf_address2 = 0x00FFFC;
						break;
					case PIC_24FJ128GA006:
						conf_address1 = 0x0157FE;
						conf_address2 = 0x0157FC;
						break;
					case PIC_24FJ128GA106:
						conf_address1 = 0x0157FE;
						conf_address2 = 0x0157FC;
						conf_address3 = 0x0157FA;
						break;
			 		default:
						StatusGr=0xf5;
						break;
					}
/************************************************************/					
					
				for(Temp=0;Temp<50;Temp++)
					buffer_U2[Temp]='\0';
				for(IndexBuffer=0;IndexBuffer<512;IndexBuffer++)
					MemoryBuffer[IndexBuffer]=0xff;
				Endereco=EnderecoBase;
				for(Temp=0;Temp<32;Temp++)
					{
					MemoryEraseBlock(Endereco);
					Endereco+=0x4000;
					}
				Endereco=EnderecoBase;
				ReceiverState++;
				IndexBuffer=0;
				Erro=false;
			break;
			case 1 :
				Temp=0;
				IndexBufferU2=0;
				do
					{
					MemoryBuffer[IndexBuffer]=buffer_U2[IndexBufferU2];
					IndexBufferU2++;
					if(++IndexBuffer==512)
						{
						if(GravaBuffer())
							{
							bus_tx_buffer_U2[0]=0x0b;
							num_bytes_U2=1;
							ReceiverState++;
							}
						}
					}while(buffer_U2[IndexBufferU2]!='\0');
				if(buffer_U2[8]=='1')			// Fim de arquivo
					{
					LED_LD2=false;
					MemoryBuffer[IndexBuffer]=':';
					if(GravaBuffer())
						{
						bus_tx_buffer_U2[0]=0x0b;
						num_bytes_U2=1;
						}
					ReceiverState=0;
					count_byte_rx_U2=0;
					tx_state_U2=0;
/************************************************************/
					if(DestEnder != 0xffffffff)
						{
						StatusGr=0x1a;	// processamento do programa
						LastAddr=0;	
						}
					else
						{
						AddrFlash=EndFinal;//(conf_address1*2)+DestEnder+2;
						BufferTesteFlash[10]=VersaoSW[NumProg][0];
						BufferTesteFlash[11]=VersaoSW[NumProg][1];
						BufferTesteFlash[12]=VersaoSW[NumProg][2];
						BufferTesteFlash[13]=Processador;
							
						MemoryWriteSector(AddrFlash, BufferTesteFlash);
						MemoryReadSector(AddrFlash, BufferTeste);
						}
/************************************************************/
					}
				for(Temp=0;Temp<50;Temp++)
					buffer_U2[Temp]='\0';
			break;
			case 2 :
			break;
			}
		}
	else
		{
		bus_tx_buffer_U2[0]=0x0a;
		num_bytes_U2=1;
		}
	}
	
char GravaBuffer(void)
{
	MemoryWriteSector(Endereco,MemoryBuffer);
	MemoryReadSector(Endereco,BufferTesteFlash);//BufferTeste);
	Endereco+=512;
	IndexBuffer=0;
	do
	{
		if((MemoryBuffer[IndexBuffer]!=0xff)&&(MemoryBuffer[IndexBuffer]!=BufferTesteFlash[IndexBuffer]))
		{
			return(1);
		}
		IndexBuffer++;
	}while(IndexBuffer<512);

	for(IndexBuffer=0;IndexBuffer<512;IndexBuffer++)
		MemoryBuffer[IndexBuffer]=0xff;
	IndexBuffer=0;
	return(0);
}
	
/**************************************************************************
Rotina de teste da memoria
Usada somente para teste dos algoritimos
Não utilizada normalmente
/**************************************************************************/
void TesteMemory(unsigned char IndexEnd)
	{
	unsigned char retorno;
	unsigned int indice;
	if(IndexEnd ==1 )
		EnderecoBase=Programa_1;
	else if(IndexEnd == 2)
		EnderecoBase=Programa_2;
	else if(IndexEnd == 3)
		EnderecoBase=Programa_3;
	else if(IndexEnd == 4)
		EnderecoBase=Programa_4;
	for(IndexBuffer=0;IndexBuffer<512;IndexBuffer++)
		MemoryBuffer[IndexBuffer]=0x00;//ff;
	Endereco=EnderecoBase;
	for(Temp=0;Temp<32;Temp++)
		{
		retorno=MemoryEraseBlock(Endereco);
		Endereco+=0x4000;
		}
	Endereco=EnderecoBase;
	for(Temp=0;Temp<480;Temp++)
	{
		for(IndexBuffer=0;IndexBuffer<512;IndexBuffer++)
			MemoryBuffer[IndexBuffer]=0x00;//ff;
		MemoryReadSector(Endereco,MemoryBuffer);		// le 512 byte da memoria
		for(indice=0;indice<512;indice++)
		{
			if(MemoryBuffer[indice] != 0xff)
			{
				NoP();
				NoP();
				NoP();
				NoP();
			}
		}
		Endereco += 512;
	}
	Endereco=EnderecoBase;
	for(Temp=0;Temp<480;Temp++)
	{
		for(IndexBuffer=0;IndexBuffer<512;IndexBuffer++)
			MemoryBuffer[IndexBuffer]=0xaa;
		if(GravaBuffer())
		{
			NoP();
			NoP();
			NoP();
		}
	}
}
