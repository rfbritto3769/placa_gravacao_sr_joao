/********************************************************************/
/*  																*/
/* Nome do arquivo: Gravador USB.c									*/
/* 																	*/
/* Versão:	1.0 													*/
/*            Intelbras S/A.										*/
/*                                                           		*/
/* Autor:	João Antonio dos Santos Filho.          				*/
/*                                                                  */
/* Função:  Inicialização das UART 									*/
/*          		                                             	*/
/* Historico:                                                       */
/* 16/04/2013 - Primeira versão com interface USB                   */
/*                                                                  */
/********************************************************************/
#define x
#include "libpic30.h"
#include "p24fj128ga006.h"
////#include "adc.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"

//#define in_main


_CONFIG2(	IESO_ON &
			FNOSC_PRIPLL &
//			FCKSM_CSECMD &
			FCKSM_CSECME &
			OSCIOFNC_OFF &
			POSCMOD_HS
		);

_CONFIG1(	JTAGEN_OFF &
			GCP_OFF &		//rever deve ser ON
			GWRP_OFF &
			BKBUG_ON & 		// rever
			ICS_PGx1 &		// EMUC/EMUD share PGC1/PGD1
			FWDTEN_OFF &
			FWDTEN_OFF &
//			WINDIS_OFF & 
			FWPSA_PR128 &
			WDTPS_PS1024
//			WDTPS_PS2048
		);
			

void __attribute__((__interrupt__,auto_psv)) _ADC1Interrupt( void )
	{
//	LED_LD2=~LED_LD2;
	
	ADCValueVdd=ADC1BUF0;		// AN0-canal 11 Vdd
	ADCValueVpp=ADC1BUF1;		// AN1-canal 12 Vpp
	ADCValueV=ADC1BUF2;			// AN4-canal 15 Fonte interna
	
	AD1CON1bits.ASAM = 1;		// inicia nova conversão do ADC

	IFS0bits.AD1IF = 0;			// reset ADC1 flag
	}

void __attribute__((__interrupt__,auto_psv)) _T1Interrupt( void )
	{
    TMR1=0x0000;
    char indice;

	if(!recieved_a_message&&!message_to_send)
		recieve_message();
	if(message_to_send)
		send_message();
	if(!recieved_a_message_U2&&!message_to_send_U2)
		recieve_message_U2();
	if(message_to_send_U2)
		send_message_U2();

	if(recieved_a_message==1)
	{
		if(command_recieved==0x01)
		{
			command_recieved=0;
			bus_tx_buffer[0]=StatusGr;		// Status do gravador
			bus_tx_buffer[1]='\0';
			num_bytes=1;					// número de bytes do pacote
			message_to_send=2;
			tx_delay=20;
			recieved_a_message=0;
			if(StatusGr==0x04||StatusGr>=0xf0)
				StatusGr=0x00;	
		}
		if((command_recieved & 0xf0) == 0xa0)			// envia versão
		{
			indice = (command_recieved & 0x0f)-1;
			command_recieved=0;
			bus_tx_buffer[0]=VersaoSW[indice][0];	// Versao
			bus_tx_buffer[1]=VersaoSW[indice][1];	// Versao
			bus_tx_buffer[2]=VersaoSW[indice][2];	// Versao
			bus_tx_buffer[3]='\0';
			num_bytes=3;					// número de bytes do pacote
			message_to_send=2;
			tx_delay=20;
			recieved_a_message=0;
		}
		else if(command_recieved==0xf1)		//Aborta Gravação
		{
			num_bytes=0;
			message_to_send=1;
			tx_delay=20;
			recieved_a_message=0;
			AbortaGr=true;
		}
		else if(command_recieved==0xf0)
		{
			num_bytes=0;
			message_to_send=1;
			tx_delay=20;
			recieved_a_message=0;
		}
	}

	if(time_delay!=0)
		--time_delay;

	LoopFlash--;

  	if(--mileseg_temp==0)		// 1 milesegundos
  		{
		mileseg_temp=20;

		if(--teste_count==0)
			{
			teste_count=250;
		    LED_LD1=~LED_LD1;
			if(StatusGr&0xf0)
			    LED_LD2=~LED_LD2;
			}

	  	if(--seconds_temp==0)	// 1 segundo
	  		{
		  	seconds_temp=1000;
		  	if(time_adc==0)
		  		time_adc=0xff;
		  	}
  		}
//}  		
    IFS0bits.T1IF = 0;		// reset T1IF flag	NSTDIS
	}


/**********************************************************************
 * -------------------------- main function ---------------------------
 *
 * Setup the different alarms and start the kernel.
 *
 **********************************************************************/
int main(void)
{
	unsigned char temp;
	CLKDIV=0;

	TRISB=TrisBInit;
	TRISC=TrisCInit;
	TRISD=TrisDInit;
	TRISE=TrisEDataIn;
	TRISF=TrisFInit;
	TRISG=TrisGInit;

	LATB=0x0000;
	LATC=0x0000;
	LATD=0x0000;
	LATE=0x0000;
	LATF=0x0000;
	LATG=0x0008;

    PR1=0x0062;
    INTCON1bits.NSTDIS=1;	//1 = Interrupt nesting is disabled
    IPC0bits.T1IP0=1;		//Timer1 Interrupt Priority bits
    IPC0bits.T1IP1=1;		//111 = Interrupt is priority 7 (highest priority interrupt)
    IPC0bits.T1IP2=1;
    IEC0bits.T1IE=1;		//Timer1 Interrupt Enable
	T1CONbits.TCKPS0=1;		//Clock Prescale 
	T1CONbits.TCKPS1=0;		//01 = 1:8
	T1CONbits.TON=1;		//Starts 16-bit Timer1
	OSCCONbits.SOSCEN=1;
	U1STAbits.OERR=0;

	ClrWdt();
	RS485_DIR=false;
	AddrGR=((PORTD >> 6)&0x07);

	MemoryCS=true;
	MemoryCLE=false;
	MemoryALE=false;
	MemoryRD=true;
	MemoryWE=true;
	
/***********************************************************************/
/* --------------------Inicialização ADC ------------------------------*/
	AD1PCFG = 0x67ff;			// Configure A/D port AN11, AN12 e AN15 input pin is analog
	AD1CSSL = 0x9800;			// seleciona os canais acima para MUX de conversão
	AD1CON2 = 0;				// VR+=AVdd, VR-=AVss, Interrupções a cada amostra, sempre usar MUX A
	AD1CON2bits.SMPI = 2;		// interrupções após a terceira amostra
	AD1CON2bits.CSCNA = 1;		// habilita varredura dos canais selecionados em AD1CSSL
	AD1CON3 = 0x0611;			// system clock/256,sample time timer 3
	AD1CON1bits.SSRC = 0b111;	// contador interno finaliza amostragem e começa conversão
	
	IFS0bits.AD1IF = 0;			// zera flag A/D
	IEC0bits.AD1IE = 1;			// habilita interrupção do A/D
	IPC3bits.AD1IP = 6;			// nivel de prioridade interrupção 5  (highest priority interrupt)
	AD1CON1bits.ADON = 1;		// A/D ligado
	AD1CON1bits.ASAM = 1;

/***********************************************************************/
//////////// UART1 RS-485 /////////////////////////////////////////////

	U1MODE = 0X0000;				// UART habilitada, idle state rx=1, BRGH=0(low speed), sem paridade, 1 stop bit
	U1BRG = 16;	 					// baud rate de 57600 com bit BRGH=0
	U1MODEbits.UARTEN=TRUE;			// habilita a uart
	U1STAbits.UTXEN = FALSE;		// desabilita  transmissão
	U1STAbits.RIDLE = TRUE;			// habilita  recepção

//////////// UART2 BARRAMENTO RS-232 /////////////////////////////////////////////

	U2MODE = 0X0000;				// UART habilitada, idle state rx=1, BRGH=0(low speed), sem paridade, 1 stop bit
	U2BRG = 207;	 				// baud rate de 4800 com bit BRGH=0
	U2MODEbits.UARTEN=TRUE;			// habilita a uart
	U2STAbits.UTXEN = FALSE;		// desabilita  transmissão
	U2STAbits.RIDLE = TRUE;			// habilita  recepção

	U2STAbits.OERR=0;
/////////////////////////////////////////////////////////////////////////

   
    
  	seconds_temp=1000;
	mileseg_temp=20;
	process_message=0;

	teste_count=250;

	recieved_a_message=0;
	command_recieved=0;
	count_byte_rx_U2=0;
	recieved_a_message_U2=0;
	message_to_send_U2=0;
	Vdd_OFF();
	Vpp_OFF();
	Vpp_GND_OFF();
	SetVdd5v=true;
	SetVdd3v=false;
	
	Endereco=0;
	CheckSum=0;
	ReceiverState=0;
	MemoryCS=false;
	tx_state_U2=0;
	status_flag=0;
//	Vdd_5V();			//Seta alimentação para 5V
	AddrGR=((PORTD >> 6)&0x07);
	Processador=0;

	cw1 = 0x7FFF;
	cw2 = 0xFFFF;
//	cw2x= 0xF7FF;
	cw3 = 0xFFFF;
	cw4 = 0xFFFF;

	for(temp=0;temp<=3;temp++)
	{
		if(temp==0)
			AddrFlash=EndFinal_1;
		else if(temp==1)
			AddrFlash=EndFinal_2;
		else if(temp==2)
			AddrFlash=EndFinal_3;
		else if(temp==3)
			AddrFlash=EndFinal_4;
	
		MemoryReadSector(AddrFlash, BufferTesteFlash);
	
		VersaoSW[temp][0]=BufferTesteFlash[10];
		VersaoSW[temp][1]=BufferTesteFlash[11];
		VersaoSW[temp][2]=BufferTesteFlash[12];
	}
	
	while(1)
	{
		ClrWdt();

		AddrGR=((PORTD >> 6)&0x07);
		
		ChaveState();
		if(flag_key)
		{
			if(StatusGr&0xf0)
			{
				StatusGr=0x00;
				LED_LD2=false;
				delay_50us(500);
			}
			else
			{
				Processador=0x07;
				bus_rx_buffer[0]=1;
				SetVdd3v=false;
				SetVdd5v=false;
				InitGr(0x02);
				SetVdd3v=false;
				SetVdd5v=false;
			}
			flag_key=false;
		}
		if(recieved_a_message_U2==1)
		{
			LED_LD2=~LED_LD2;
			ProcessaArquivo();
			count_byte_tx_U2=0;
			message_to_send_U2=1;
			CheckSum=0;
			Index=false;
			recieved_a_message_U2=0;
			if(StatusGr==0x1a)
			{
				StatusGr=0x2a;
				Programa24fjExecutiveFlash();
				StatusGr=0x00;
				LED_LD2=false;
			}
		}
		if(recieved_a_message==1)
		{
			ClrWdt();
			num_bytes=0;
			message_to_send=1;
			tx_delay=20;
			recieved_a_message=0;
			if(command_recieved==0xf0);
			else if(command_recieved==0xf2)		//Seta processador
			{
				Processador=bus_rx_buffer[0];
			}
			else if(command_recieved==0xf3)		//Inicia gravação
			{
				InitGr(bus_rx_buffer[0]);
			}
			else
			{
				addr_value=(AddrGR|0xf0);		//Erro
			}
		}
	}
}

void delay_50us(unsigned int loop)
{
	time_delay=loop;
	while(time_delay)
		ClrWdt();
}

void ChaveState(void)
{
	if(!CHAVE_S1)
	{
		if(!ChaveAcionada&&++temp_debug==100)
		{
			ChaveAcionada=true;
			flag_key=true;
		}
	}
	else
	{
		temp_debug=0;
		ChaveAcionada=false;
	}
}
	
void InitGr(unsigned char addr)
{
	LED_LD2=true;
	FlagExecutive=false;
	if(addr==0x01)
	{
		EnderecoBase=Programa_1;
		NumProg=0;
		EndFinal=EndFinal_1;
	}	
	else if(addr==0x02)
	{
		EnderecoBase=Programa_2;
		NumProg=1;
		EndFinal=EndFinal_2;
	}	
	else if(addr==0x03)
	{
		EnderecoBase=Programa_3;
		NumProg=2;
		EndFinal=EndFinal_3;
	}	
	else if(addr==0x04)
	{
		EnderecoBase=Programa_4;
		NumProg=3;
		EndFinal=EndFinal_4;
	}	
/************************************************************************************/
	switch(Processador) 
	{
		case PIC_16F506:
            flag_344=0;
			MaxMemory=MaxMemory506;
			DelayTera = TERA_506;
			DelayThld0 = THLD0_506;
			DelayTprogMem = TPROG_MEM_506;
            //adapt_224=0;
			Programa506();
			break;

		case PIC_16F677:
            flag_344=0;
			MaxMemory=MaxMemory677;
			DelayTera = TERA_677;
			DelayThld0 = THLD0_677;
			DelayTprogMem = TPROG_MEM_677;
			DelayTprogData = TPROG_DATA_677;
          //  adapt_224=0;
			Programa677();
			break;

		case PIC_16F685:
            flag_344=0;
			MaxMemory=MaxMemory685;
			DelayTera = TERA_677;
			DelayThld0 = THLD0_677;
			DelayTprogMem = TPROG_MEM_677;
			DelayTprogData = TPROG_DATA_677;
          //  adapt_224=0;
			Programa677();
			break;

		case PIC_16F1828:
            flag_344=0;
			SetVdd3v=false;
			SetVdd5v=true;
			MaxMemory=MaxMemory1828;
			DelayTera = TERA_1828;
			DelayTprogMem = TPROG_MEM_1828;
			DelayTprogData = TPROG_DATA_1828;
			DelayThld0 = THLD0_1828;
           // adapt_224=0;
			Programa1828();
			break;
            
        case PIC_16F15224:
            flag_344=1;
			SetVdd3v=false;
			SetVdd5v=true;
			MaxMemory=MaxMemory344;
			DelayTera = TERA_344;
			DelayTprogMem = TPROG_MEM_344;
			DelayTprogData = TPROG_DATA_344;
			DelayThld0 = THLD0_344;
          //  adapt_224=1;
            grava_pic16f15344();
			////Programa344();
            break;
            
        case PIC_16F15344:
            flag_344=1;
			SetVdd3v=false;
			SetVdd5v=true;
			MaxMemory=MaxMemory344;
			DelayTera = TERA_344;
			DelayTprogMem = TPROG_MEM_344;
			DelayTprogData = TPROG_DATA_344;
			DelayThld0 = THLD0_344;
         //   adapt_224=0;
            grava_pic16f15344();
			////Programa344();
			break;
            
                    
        case PIC_16F15345:
            flag_344=1;
			SetVdd3v=false;
			SetVdd5v=true;
			MaxMemory=MaxMemory345;
			DelayTera = TERA_344;
			DelayTprogMem = TPROG_MEM_344;
			DelayTprogData = TPROG_DATA_344;
			DelayThld0 = THLD0_344;
          //  adapt_224=0;
            grava_pic16f15344();
			////Programa344();
			break;

		case PIC_24FJ16:
			conf_address1 = 0x002BFE;
			conf_address2 = 0x002BFC;
		case PIC_24FJ32:
			if(!conf_address1) 
			{
				conf_address1 = 0x0057FE;
				conf_address2 = 0x0057FC;
			}
		case PIC_24FJ48:
			if(!conf_address1) 
			{
				conf_address1 = 0x0083FE;
				conf_address2 = 0x0083FC;
			}
		case PIC_24FJ64:
			if(!conf_address1) 
			{
				conf_address1 = 0x00ABFE;
				conf_address2 = 0x00ABFC;
			}
		case PIC_24FJ96:
			if(!conf_address1)
			{
				conf_address1 = 0x00FFFE;
				conf_address2 = 0x00FFFC;
			}
		case PIC_24FJ128GA006:
			if(!conf_address1) 
			{
				conf_address1 = 0x0157FE;
				conf_address2 = 0x0157FC;
			}
			conf_address3 = 0x0000000;
			MemoryReadSector(EnderecoBase,MemoryBuffer);		// le 512 byte da memoria
			if(MemoryBuffer[0]==':')
			{
			    Programa24FJ();
			}
			else
			{
			    ProgExecutive24FJ();
			}
			break;

		case PIC_16LF1828:
            flag_344=0;
			SetVdd3v=true;
			SetVdd5v=false;
			MaxMemory=MaxMemory1828;
			DelayTera = TERA_1828;
			DelayTprogMem = TPROG_MEM_1828;
			DelayTprogData = TPROG_DATA_1828;
			DelayThld0 = THLD0_1828;
         //   adapt_224=0;
			Programa1828();
			break;

		case PIC_24FJ128GA106:
			conf_address1 = 0x0157FE;
			conf_address2 = 0x0157FC;
			conf_address3 = 0x0157FA;
			MemoryReadSector(EnderecoBase,MemoryBuffer);		// le 512 byte da memoria
			if(MemoryBuffer[0]==':')
			{
			    Programa24FJ();
			}
			else
			{
			    ProgExecutive24FJ();
			}
			break;

		case PIC_24FJ64GA104:
			conf_address1 = 0x00ABFE;
			conf_address2 = 0x00ABFC;
			conf_address3 = 0x00ABFA;
			conf_address4 = 0x00ABF8;
			MemoryReadSector(EnderecoBase,MemoryBuffer);		// le 512 byte da memoria
			if(MemoryBuffer[0]==':')
			{
			    Programa24FJ();
			}
			else
			{
			    ProgExecutive24FJ();
			}
			break;

 		default:
			StatusGr=0xf5;
			break;
	}

	Vpp_OFF();
	LED_LD2=false;
	Processador=0;
	conf_address1 = 0x00;
	conf_address2 = 0x00;
	conf_address3 = 0x00;
	conf_address4 = 0x00;
	LATB=0x0000;
	LATC=0x0000;
	LATD=0x0000;
	LATE=0x0000;
	LATF=0x0000;
	LATG=0x0008;
	Vpp_GND_OFF();
	MemoryCS=true;
	MemoryCLE=false;
	MemoryALE=false;
	MemoryRD=true;
	MemoryWE=true;
}

