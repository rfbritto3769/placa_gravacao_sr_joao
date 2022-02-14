#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"
#include "string.h"




#define ResetPC()	ExitResetVector()

//extern volatile far char msd_buffer[512];
unsigned long *blocoDeInstrucoes = &BufferTeste[0];
/*
// palavras de configuração (valores default)
unsigned int cw1 = 0x7FFF;	//0x7FF0;(este comentário é só para testar)
unsigned int cw2 = 0xFFFF;	//0xFAFF;(este comentário é só para testar)
unsigned int cw2x= 0xF7FF;	//0xFAFF;(este comentário é só para testar)
unsigned int cw3 = 0xFFFF;	//0xFAFF;(este comentário é só para testar)
*/
unsigned char c_asm_char;

//extern HEX_HEADER hex_line;

// Tempos que devem ser respeitados durante a gravação do PIC
// P1 = 100ns
// P1A = 40ns
// P1B = 40ns
// P4 = 40ns
// P4A = 40ns
// P5 = 20ns
// P6 = 100ns
// P7 = 25ms
// P8 = 12us
// P9 = 40us
// P10 = 400ns
// P11 = 400s
// P16 = 0s
// P17 = 100ns
// P18 = 40ns
// P19 = 1ms


// Ao se ligar o PIC a ser gravado, a primeira instrução a ser executada pelo mesmo deve ser um NoP() de 9 bits de extensão, seguido de uma
// palavra de instrução nula (0x000000)
void SendSIX_startup(void) 
{
	PGD = 0;

	// Envia o comando SIX startup
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;	//clock 1
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;	//clock 2
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;	//clock 3
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;	//clock 4
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;	//clock 5
	NoP();
	PGD = 0;
	PGC = 0;
	SendSIX_Command(NOP);
}

void SendSIX_Command(unsigned long data) 
{
	PGD = 0;

	// Envia o comando SIX - b'0000'
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;
	NoP();
	PGC = 0;
	NoP();
	PGD = 0;
	PGC = 1;
	NoP();
	PGD = 0;
	PGC = 0;
/********************************************/

	// Envia intrução "data"
/********************************************/
	if(data & 0x000001)	//bit 0
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000002)	//bit 1
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000004)	//bit 2
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000008)	//bit 3
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000010)	//bit 4
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000020)	//bit 5
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000040)	//bit 6
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000080)	//bit 7
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000100)	//bit 8
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000200)	//bit 9
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000400)	//bit 10
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x000800)	//bit 11
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x001000)	//bit 12
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x002000)	//bit 13
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x004000)	//bit 14
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x008000)	//bit 15
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x010000)	//bit 16
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x020000)	//bit 17
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x040000)	//bit 18
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x080000)	//bit 19
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x100000)	//bit 20
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x200000)	//bit 21
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x400000)	//bit 22
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	if(data & 0x800000)	//bit 23
	{
		PGC = 0;
		PGD = 1;
	}
	else
	{
		PGC = 0;
		PGD = 0;
	}
	NoP();
	PGC = 1;
	NoP();
	PGD = 0;
	PGC = 0;
}	

unsigned int SendREGOUT_Command(void) 
{
	int DataRet = 0;	// O tamanho dessa variável deve ser de 16 bits. É o tamanho do registrador VISI.
	
	PGD = 0;
	
	// Envia comando REGOUT - b'0001'
	PGC = 0;
	PGD = 1;
NoP();
	PGC = 1;	//clock 1
NoP();
	PGD = 0;
	PGC = 0;
NoP();
	PGC = 1;	//clock 2
NoP();
	PGD = 0;
	PGC = 0;
NoP();
	PGC = 1;	//clock 3
NoP();
	PGD = 0;
	PGC = 0;
NoP();
	PGC = 1;	//clock 4
NoP();
	PGD = 0;
	PGC = 0;
	
	// Envia 8 pulsos de clock
	NoP();
NoP();
	PGC = 1;	//clock 1
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 2
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 3
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 4
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 5
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 6
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 7
NoP();
	PGC = 0;
NoP();
	PGC = 1;	//clock 8
NoP();
	PGC = 0;

	// Lê dado da memória de programa
	PGD_DIR=false;		//input
	TRISG=TrisGInp;
	PGC = 1;
	NoP();
	NoP();
	NoP();
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0001;	// bit 0

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0002;	// bit 1

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0004;	// bit 2

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0008;	// bit 3

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0010;	// bit 4

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0020;	// bit 5

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0040;	// bit 6

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0080;	// bit 7

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0100;	// bit 8

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0200;	// bit 9

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0400;	// bit 10

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x0800;	// bit 11

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x1000;	// bit 12

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x2000;	// bit 13

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x4000;	// bit 14

	PGC = 0;
	NoP();
	PGC = 1;
	if(PGD_IN)
//	BitTestSC();
		DataRet |= 0x8000;	// bit 15

	PGC = 0;

	PGD_DIR=true;		//output
	TRISG=TrisGInit;

	return DataRet;
}

void SendKeySequence(void) 
{
	unsigned long mask = 0x80000000, PrgmEntryCode;
	unsigned char contador = 32;

	if(FlagExecutive)
		PrgmEntryCode=PRGM_ENTRY_CODE_EN;
	else
		PrgmEntryCode=PRGM_ENTRY_CODE;
	
	PGD = 0;
	
	while(contador--)
	{
		PGC = 0;
		if(PrgmEntryCode & mask)
			PGD = 1;
		else 
			PGD = 0;
		mask=mask >> 1;
		PGC = 1;
	}
	PGD = 0;
	PGC = 0;
}

// Realiza a temporização e o envio de sinais necessários para se entrar no modo de programação ICSP
unsigned char EnterICSP_Mode(void) 
{
	VPP=OFF;
	Vpp_GND_ON();		//desconecta VPP de GND
	VDD_GR=ON;			//liga alimentação
	delay_50us(200);	//400);
//	if((ADCValueVdd<=150)||(ADCValueVdd>=300))
	if((ADCValueVdd<=125)||(ADCValueVdd>=300))
	{
		VDD_GR=OFF;		//desliga alimentação
		StatusGr=0xf6;	// Erro na tensão de alimentação (VDD)
		return(1);
	}
	delay_50us(400);
	Vpp_GND_OFF();		//desconecta VPP de GND
	VPP = ON;
	delay_50us(20);
	if((ADCValueVpp<=120)||(ADCValueVpp>=300))
	{
		VPP=OFF;
		Vpp_GND_ON();
		StatusGr=0xf7;			// Erro na tensão de gravação (VPP)
		return(1);
	}
	VPP = OFF;
	Vpp_GND_ON();			//conecta VPP de GND
	delay_50us(60);
	SendKeySequence();
	delay_50us(P19);
	Vpp_GND_OFF();		//desconecta VPP de GND
	VPP = ON;
	delay_50us(80);
	return(0);
}

// Sai do modo de programação ICSP
void ExitICSP_Mode(void) 
{
	PGC = 0;
	PGD = 0;
	delay_50us(11);
	VPP=OFF;
	Vpp_GND_ON();			//conecta VPP de GND
	delay_50us(11);
	VDD_GR=OFF;		//desliga alimentação
	delay_50us(20);
	Vpp_GND_OFF();		//desconecta VPP de GND
}

void ExitResetVector(void)
{
	SendSIX_Command(GOTO_200);
	SendSIX_Command(NOP);
}

// Verifica o estado do bit WR do registrador NVMCON e espera até que seu nível lógico seja 0 (zero)
void AguardaWR1(void)
{
	unsigned int visi;	// deve ser uma variável de 16bits
	
	do 
	{
		SendSIX_Command(GOTO_200);
		SendSIX_Command(NOP);
		SendSIX_Command(0x803B02);
		SendSIX_Command(0x883C22);
		SendSIX_Command(NOP);
		visi = SendREGOUT_Command();
		SendSIX_Command(NOP);
	} while(visi & 0x8000);
}

void ChipErase(void)
{
	// Step 1: Exit the Reset Vector
	SendSIX_Command(NOP);
	SendSIX_Command(GOTO_200);
	SendSIX_Command(NOP);
	
	// Step 2: Set the NVMCON to erase all program memory
	SendSIX_Command(0x2404FA);
	SendSIX_Command(0x883B0A);
	
	// Step 3: Set TBLPAG and perform dummy table write
	SendSIX_Command(0x200000);
	SendSIX_Command(0x880190);
	SendSIX_Command(0x200000);
	SendSIX_Command(0xBB0800);
	SendSIX_Command(NOP);
	SendSIX_Command(NOP);
	
	// Step 4: Initiate the erase cycle
	SendSIX_Command(0xA8E761);
	SendSIX_Command(NOP);
	SendSIX_Command(NOP);
	
	// Step 5: Poll WR bit until it is cleared by the hardware
	AguardaWR1();
}


void PackInstructions(volatile unsigned long *package, unsigned long *instructions) 
{
	unsigned long mov_w = 0x200000;
	unsigned char counter;
	
	package[0] = instructions[0] & 0x00FFFF;
	package[1] = instructions[1] & 0xFF0000;
	package[1] >>= 8;
	package[1] |= ( (instructions[0] & 0xFF0000) >> 16 );
	package[2] = instructions[1] & 0x00FFFF;
	package[3] = instructions[2] & 0x00FFFF;
	package[4] = instructions[3] & 0xFF0000;
	package[4] >>= 8;
	package[4] |= ( (instructions[2] & 0xFF0000) >> 16 );
	package[5] = instructions[3] & 0x00FFFF;
	
/*********************************/
WordProg[ContPacked]=(unsigned int)(package[0]&0x00FFFF);
ContPacked++;
WordProg[ContPacked]=(unsigned int)(package[1]&0x00FFFF);
ContPacked++;
WordProg[ContPacked]=(unsigned int)(package[2]&0x00FFFF);
ContPacked++;
WordProg[ContPacked]=(unsigned int)(package[3]&0x00FFFF);
ContPacked++;
WordProg[ContPacked]=(unsigned int)(package[4]&0x00FFFF);
ContPacked++;
WordProg[ContPacked]=(unsigned int)(package[5]&0x00FFFF);
ContPacked++;
/*********************************/

	if(!FlagExecutive)
	{
		for(counter = 0; counter < 6; counter++, mov_w++)
		{
			package[counter] <<= 4;
			package[counter] |= mov_w;
		}
	}
}

// Escreve na memória de programa do PIC um bloco com 64 instruções
void BlockProgramCycle(unsigned long *instr, unsigned int endereco_dest)
{
	// *instr deve apontar para um bloco de instruções com 96 words, ou seja, 64 instruções de 24 bits.
	
//	volatile unsigned long packed_instructions[6];	// corresponde às instruções MOV com os registradores W0, W1, W2, W3, W4 e W5.
	volatile unsigned long address_high = 0, address_low = 0;	// O tipo dessas variáveis deve ser de 24 bits
	unsigned char counter = 16, index = 0,xyz=0;
		
	// Step 1: Exit the Reset Vector
	ExitResetVector();
	
	// Step 2: Set the NVMCON to program 64 instructions words
	if(!FlagProg)
	{
		SendSIX_Command(0x24001A);
		SendSIX_Command(0x883B0A);
	}
	else
	{
		SendSIX_Command(0x240010);
		SendSIX_Command(0x883B00);
	}
	
	// Step 3: Initialize the Write Pointer(W7) for TBLWT instruction
	if(!FlagProg)
		address_high = 0x200000;	// o byte mais significativo do endereco de destino é sempre 0x00.
	else
		address_high = 0x200800;

/*********************************/
AddressTeste1=endereco_dest;
/*********************************/
	address_high = TesteDebug & 0xff0000;
	address_high = address_high >> 12;
	address_high |= 0x200000;

	address_low = TesteDebug & 0x00ffff;
	address_low <<= 4;
	address_low |= 0x200007;
	SendSIX_Command(address_high);
	SendSIX_Command(0x880190);
	SendSIX_Command(address_low);
	ContPacked=0;

	while(counter--) 
	{
		// Step 4: Load W0:W5 with the next 4 instruction words to program
		PackInstructions(packed_instructions, &instr[index]);
		SendSIX_Command(packed_instructions[0]);
		SendSIX_Command(packed_instructions[1]);
		SendSIX_Command(packed_instructions[2]);
		SendSIX_Command(packed_instructions[3]);
		SendSIX_Command(packed_instructions[4]);
		SendSIX_Command(packed_instructions[5]);
		
		//Step 5: Set the Read Pointer (W6) and load the (next set of) write latches
		SendSIX_Command(0xEB0300);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBB0BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBBDBB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBBEBB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBB1BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBB0BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBBDBB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBBEBB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBB1BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		
		index += 4;
	}// Step 6: while loop above
	
	// Step 7: Initiate the write cycle
	SendSIX_Command(0xA8E761);
	SendSIX_Command(NOP);
	SendSIX_Command(NOP);
	
	// Step 8: Poll WR bit until it is cleared by the hardware
	AguardaWR1();
	
	// Step 9: Reset device internal PC
	ResetPC();
}

// Esta função "desempacota" os dados lidos da memória de programa, transforma-os em instruções que o PIC pode entender e verifica
// se essas instruções foram programadas na memória de programa do PIC corretamente.
// Apenas as instruções diferentes de 0xFFFFFF são verificadas (após a sua gravação), pois é impossível verificar um bloco
// completo de 64 instruções se este não estiver armazenado no arquivo HEX continuamente. Uma vez que um bloco esteja "quebrado"
// no arquivo HEX, ele será programado mais de uma vez na memória do PIC. As instruções de um bloco que ainda não foram encontradas
// no arquivo HEX (essas instruções poderão estar localizadas mais adiante dentro do arquivo HEX) serão substituídas por 0xFFFFFF,
// e o bloco será programado. Quando o restante desse mesmo bloco for localizado no arquivo hex, as insrtuções obtidas anteriormente
// serão substituídas por 0xFFFFFF e, então, o bloco será programado. (Obs.: as instruções do bloco programadas previamente não
// serão perdidas, pois a memória é FLASH, ou seja, escrever 0xFFFFFF não altera o seu conteúdo). Ao verificar uma instrução
// previamente programa, a função esperaria ler 0xFFFFFF. Entretanto, o valor lido será igual à instrução programada anteriormente.
// Por esse motivo não é possível comparar insrtuções do tipo 0xFFFFFF. Assume-se que o apagamento da memória é realizado com sucesso,
// e a escrita de instruções do tipo 0xFFFFFF também.
unsigned char UnpackInstructions(unsigned int *buf1, unsigned long *buf2) 
{
	volatile unsigned long unpacked_instr[2];
/*	volatile unsigned int buf1_x[2],buf2_y[2];
	buf1_x[0]=buf1[0];
	buf1_x[1]=buf1[1];
	
	buf2_y[0]=buf2[0];
	buf2_y[1]=buf2[1];*/
	
	if(buf2[0] != 0x00FFFFFF)
	{
		unpacked_instr[0] = (unsigned long)(buf1[1] & 0x00FF);
		unpacked_instr[0] <<= 16;
		unpacked_instr[0] |= (unsigned long)buf1[0];
		
		if(unpacked_instr[0] != buf2[0])
			return 1;
	}
	
	if(buf2[1] != 0x00FFFFFF)
	{
		unpacked_instr[1] = (unsigned long)(buf1[1] & 0xFF00);
		unpacked_instr[1] <<= 8;
		unpacked_instr[1] |= (unsigned long)buf1[2];

		if(unpacked_instr[1] != buf2[1])
			 return 1;
	}
	return 0;
}

// Lê uma região da memória de programa do PIC a ser gravado correspondente a um bloco de 64 instruções de 24 bits
unsigned char ReadBlockFromProgMem(unsigned int endereco_dest)
{
	volatile unsigned long address_high = 0, address_low = 0;	// O tipo dessas variáveis deve ser de 24 bits
	volatile unsigned char counter = 0;
	unsigned int packed_instructionsx[3];
	unsigned char ret = 0;
	
	// Step 1: Exit Reset Vector
	ExitResetVector();
	
	// Step 2: Initialize TBLPAG  and the Read Pointer (W6) for TBLRD instruction
	address_high = 0x200000;	// o byte mais significativo do endereco de destino é sempre 0x00.
/*********************************************************/
	address_high = TesteDebug & 0xff0000;
	address_high = address_high >> 12;
	address_high |= 0x200000;

	address_low = TesteDebug & 0x00ffff;
	address_low <<= 4;
	address_low |= 0x200006;
/*********************************************************/

/*if(Endereco24F > 0xffff)
	address_high = 0x200010;
//AddressTeste2=endereco_dest;
	address_low = (unsigned long)endereco_dest;
	address_low <<= 4;
	address_low |= 0x200006;*/
	SendSIX_Command(address_high);
	SendSIX_Command(0x880190);
	SendSIX_Command(address_low);
	
	// Step 3: Initialize the Write Pointer (W7) to point to the VISI register
	SendSIX_Command(0x207847);
	SendSIX_Command(NOP);

for(CountRead=0;CountRead<100;CountRead++)
	BufferTemporario[CountRead]=0xffff;

	CountRead=0;

//	while(!ret && counter < 32)
	while(counter < 32)
	{
		// Step 4: Read and clock out the contents of the next two locations of code memory, through the VISI register, using
		// the REGOUT command
		SendSIX_Command(0xBA0B96);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		packed_instructionsx[0] = SendREGOUT_Command();
		SendSIX_Command(NOP);
		SendSIX_Command(0xBADBB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		SendSIX_Command(0xBAD3D6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		packed_instructionsx[1] = SendREGOUT_Command();
		SendSIX_Command(NOP);
		SendSIX_Command(0xBA0BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		packed_instructionsx[2] = SendREGOUT_Command();
		SendSIX_Command(NOP);
		
//BufferTemporario[CountRead+0]=packed_instructionsx[0];
/************************************************/
/*if(WordProg[CountRead]==0xffff)
	packed_instructionsx[1]|=0x00ff;;
if(WordProg[CountRead+2]==0xffff)
	packed_instructionsx[1]|=0xff00;*/
/************************************************/
//CountRead++;
//BufferTemporario[CountRead+1]=packed_instructionsx[1];
//CountRead++;
//BufferTemporario[CountRead+2]=packed_instructionsx[2];
//CountRead++;
/*********************************/
		if((AddressTeste1==0)&&(AddressTeste2==0))
			Flag_Addr=true;

		if(Flag_Addr)
		{
			BufferTemporario[CountRead]=packed_instructionsx[0];
			if((WordProg[CountRead] != 0xffff)&&(BufferTemporario[CountRead] != WordProg[CountRead]))
			{
				NoP();
				NoP();
				NoP();
				NoP();
			//			ret = 1;
			}
			CountRead++;
			BufferTemporario[CountRead]=packed_instructionsx[1];
			if((WordProg[CountRead]!=0xffff)&&(BufferTemporario[CountRead]!=WordProg[CountRead]))
			{
				NoP();
				NoP();
				NoP();
				NoP();
			//			ret = 1;
			}
			CountRead++;
			BufferTemporario[CountRead]=packed_instructionsx[2];
			if((WordProg[CountRead]!=0xffff)&&(BufferTemporario[CountRead]!=WordProg[CountRead]))
			{
				NoP();
				NoP();
				NoP();
				NoP();
			//			ret = 1;
			}
			CountRead++;
		}
/*********************************/

		ResetPC();
		counter++;
	}// Step 5: while loop above
	
	// Step 6: Reset device internal PC
	return ret;
}

//Le configuração
unsigned char LeConfigurationMemory24FJ(void)
{
	unsigned long mov_address, TBLPAG_reg;
	unsigned char index = 2;
	unsigned int read_word[4], word[4];
	
	if(Processador==PIC_24FJ64GA104)
	{
		word[0] = cw1;
		word[1] = cw2;
		word[2] = cw3;
		word[3] = cw4;
		
		mov_address = conf_address4 & 0x00FFFF;
		mov_address <<= 4;
		mov_address |= 0x200007;
		
		TBLPAG_reg = conf_address4 & 0xFF0000;
		TBLPAG_reg >>= 12;
		TBLPAG_reg |= 0x200000;
		
		index = 4;
	}
	else if(Processador==PIC_24FJ128GA106)
	{
		word[0] = cw1;
		word[1] = cw2;
		word[2] = cw3;
		
		mov_address = conf_address3 & 0x00FFFF;
		mov_address <<= 4;
		mov_address |= 0x200007;
		
		TBLPAG_reg = conf_address3 & 0xFF0000;
		TBLPAG_reg >>= 12;
		TBLPAG_reg |= 0x200000;
		
		index = 3;
	}
	else
	{
		word[0] = cw1;
		word[1] = cw2;
		
		mov_address = conf_address2 & 0x00FFFF;
		mov_address <<= 4;
		mov_address |= 0x200007;
		
		TBLPAG_reg = conf_address2 & 0xFF0000;
		TBLPAG_reg >>= 12;
		TBLPAG_reg |= 0x200000;
		
		index = 2;
	}
	// Reading Configuration Words
	
	mov_address &= 0xFFFFF0;	// A especificação de programação está errada, por isso foi necessário alterar o 
	mov_address |= 0x000006;	// valor de mov_address. Esse valor deve corresponder a um MOV => W6 (e não W7)
		
	ResetPC();
	// Step 1: Exit Reset vector
	ExitResetVector();
	
	// Step 2: Initialize TBLPAG, the Read Pointer (W6) and the Write Pointer (W7) for TBLRD instruction
	//SendSIX_Command(0x200000);
	SendSIX_Command(TBLPAG_reg);
	SendSIX_Command(0x880190);
	SendSIX_Command(mov_address);
	SendSIX_Command(0x207847);
	SendSIX_Command(NOP);
	
	while(index-- > 0) 
	{
		// Step 3: Read the Configuration register and write it to the VISI register (located at 784h) , and clock out the
		// VISI register using the REGOUT command
		SendSIX_Command(0xBA0BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		read_word[index] = SendREGOUT_Command();
		SendSIX_Command(NOP);
	}// Step 4: Repeat Step 3 again to read Configuration Word 1 ---- while loop above
	
	// Step 5: Reset device internal PC
	ResetPC();
	
	// Compara a palavra lida com a programada
	if(Processador==PIC_24FJ64GA104)
	{
		if((read_word[0] != 0x00)||(read_word[1] != 0x00)||(read_word[2] != 0x00)||(read_word[3] != 0x00))
			return 1;
	}
	else if(Processador==PIC_24FJ128GA106)
	{
		if((read_word[0] != 0x00)||(read_word[1] != 0x00)||(read_word[2] != 0x00))
			return 1;
	}
	else
	{
		if((read_word[0] != 0x00)||(read_word[1] != 0x00))
			return 1;
	}
			
	return 0;
}

// Programa e verifica as palavras de configuração do PIC a ser gravado
unsigned char ProgramConfigurationMemory24FJ(void/*HEX_HEADER header*/) 
	{
	unsigned long mov_word, mov_address, TBLPAG_reg;
	unsigned char index = 2;
	unsigned int read_word[4], word[4];
	
	if(Processador==PIC_24FJ64GA104)
	{
		word[0] = cw1;
		word[1] = cw2;
		word[2] = cw3;
		word[3] = cw4;
		
		mov_address = conf_address4 & 0x00FFFF;
		mov_address <<= 4;
		mov_address |= 0x200007;
		
		TBLPAG_reg = conf_address4 & 0xFF0000;
		TBLPAG_reg >>= 12;
		TBLPAG_reg |= 0x200000;
		
		index = 4;
	}
	else if(Processador==PIC_24FJ128GA106)
	{
		word[0] = cw1;
		word[1] = cw2;
		word[2] = cw3;
		
		mov_address = conf_address3 & 0x00FFFF;
		mov_address <<= 4;
		mov_address |= 0x200007;
		
		TBLPAG_reg = conf_address3 & 0xFF0000;
		TBLPAG_reg >>= 12;
		TBLPAG_reg |= 0x200000;
		
		index = 3;
	}
	else
	{
		word[0] = cw1;
		word[1] = cw2;
		
		mov_address = conf_address2 & 0x00FFFF;
		mov_address <<= 4;
		mov_address |= 0x200007;
		
		TBLPAG_reg = conf_address2 & 0xFF0000;
		TBLPAG_reg >>= 12;
		TBLPAG_reg |= 0x200000;
		
		index = 2;
	}
	
	// Writing Configuration Words
	
	// Step 1: Exit the Reset vector
	ExitResetVector();
	
	// Step 2: Initialize the Write Pointer (W7) for the TBLWT instruction
	SendSIX_Command(mov_address);
	
	// Step 3: Set the NVMCOM register to program CW2
	SendSIX_Command(0x24003A);
	SendSIX_Command(0x883B0A);
	
	// Step 4: Initialize the TBLPAG register
	//SendSIX_Command(0x200000);
	SendSIX_Command(TBLPAG_reg);
	SendSIX_Command(0x880190);
	
	while(index-- > 0) 
	{
		// Step 5: Load the Configuration register data to W6
		mov_word = (unsigned long)word[index];
		mov_word <<= 4;
		mov_word |= 0x200006;
		SendSIX_Command(mov_word);
		
		// Step 6: Write the configuration register data to the write latch and increment the Write Pointer
		SendSIX_Command(NOP);
		SendSIX_Command(0xBB1B86);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		
		// Step 7: Initiate the write cycle
		SendSIX_Command(0xA8E761);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		
		// Step 8: Repeat this step to poll the WR bit (bit 15 of NVMCON) until it is cleared by the hardware
		AguardaWR1();
		
		// Step 9: Reset device internal PC
		ResetPC();
	}// Step 10: Repeat steps 5-9 to write CW1 (while loop above)
	
	
	// Reading Configuration Words
	
	mov_address &= 0xFFFFF0;	// A especificação de programação está errada, por isso foi necessário alterar o 
	mov_address |= 0x000006;	// valor de mov_address. Esse valor deve corresponder a um MOV => W6 (e não W7)
	
	if(Processador==PIC_24FJ64GA104)
	{
		index = 4;
	}	
	else if(Processador==PIC_24FJ128GA106)
	{
		index = 3;
	}
	else
	{
		index = 2;
	}
	
	// Step 1: Exit Reset vector
	ExitResetVector();
	
	// Step 2: Initialize TBLPAG, the Read Pointer (W6) and the Write Pointer (W7) for TBLRD instruction
	//SendSIX_Command(0x200000);
	SendSIX_Command(TBLPAG_reg);
	SendSIX_Command(0x880190);
	SendSIX_Command(mov_address);
	SendSIX_Command(0x207847);
	SendSIX_Command(NOP);
	
	while(index-- > 0) 
	{
		// Step 3: Read the Configuration register and write it to the VISI register (located at 784h) , and clock out the
		// VISI register using the REGOUT command
		SendSIX_Command(0xBA0BB6);
		SendSIX_Command(NOP);
		SendSIX_Command(NOP);
		read_word[index] = SendREGOUT_Command();
		SendSIX_Command(NOP);
	}// Step 4: Repeat Step 3 again to read Configuration Word 1 ---- while loop above
	
	// Step 5: Reset device internal PC
	ResetPC();

	// Compara a palavra lida com a programada
	if(Processador==PIC_24FJ64GA104)
	{
		if(read_word[0] != word[0]) 
		{
			return 1;
		} 
		else if(read_word[1] != word[1]) 
		{
			return 1;
		}
		else if(read_word[2] != word[2]) 
		{
			return 1;
		}
		else if(read_word[3] != word[3]) 
		{
			return 1;
		}
	}
	else if(Processador==PIC_24FJ128GA106)
	{
		if(read_word[0] != word[0]) 
		{
			return 1;
		} 
		else if(read_word[1] != word[1]) 
		{
			return 1;
		}
		else if(read_word[2] != word[2]) 
		{
			return 1;
		}
	}
	else
	{
		if(read_word[0] != word[0]) 
		{
			return 1;
		} 
		else if(read_word[1] != word[1]) 
		{
			return 1;
		}
	}
	return 0;
}

unsigned char SendBlock24FJ(unsigned long *block, unsigned int end_dest)
{
	unsigned char ret;
	if(FlagExecutive)
		ret=BlockProgramFlash(block, end_dest);
	else
	{
		BlockProgramCycle(block, end_dest);
		ret=ReadBlockFromProgMem(end_dest);
//		return 1;
	}
	ContError++;
	return(ret);
}

void InicializaBloco(void)
{
	unsigned char i = 0;
	
	while(i < 64)
		blocoDeInstrucoes[i++] = 0xFFFFFF;	
}

	
unsigned char MontaBloco64(void)
{
	// O maior PIC (24FJ128) possui 688 blocos de instruções. Por isso essa variável é int.
	static unsigned int blocoAtual_mem_prog = 0;//86;	//262(PIC24FJ48); // Seu valor inicial corresponde ao penúltimo bloco do PIC24FJ16.
	// blocoAtual_mem_prog é o bloco no qual se está trabalhando
	unsigned int bloco_mem_prog;	// Informa em qual bloco os dados da nova linha do arquivo HEX devem ser armazenados.
	unsigned char posicao_dentro_bloco; // Informa a posição, dentro do bloco, das instruções da nova linha do arquivo HEX.
	unsigned char numero_instrucoes; // Informa o número de instruções contidas numa linha do arquivo HEX.
	static unsigned long aux;
	unsigned char ret = 0;
	volatile unsigned int aa,bb;

	if(!RecordType) 
	{
//		Endereco24F = (Endereco24F & 0xFF0000) | (unsigned long)Address;
		Endereco24F = (unsigned long)Address;
		Endereco24F |= aux;
		Endereco24F /= 2;
	
		if(Endereco24F == conf_address1)
		{
			memcpy(&cw1, DataHex, (int)2);
			return ret;
		}
		if(Endereco24F == conf_address2)
		{
			memcpy(&cw2, DataHex, (int)2);
			return ret;
		}
		if((conf_address3 != 0x000000) && (Endereco24F == conf_address3))
		{
			memcpy(&cw3, DataHex, (int)2);
			return ret;
		}
		if((conf_address4 != 0x000000) && (Endereco24F == conf_address4))
		{
			memcpy(&cw4, DataHex, (int)2);
			return ret;
		}
//Endereco24F |= aux;
		
		// O endereço das instruções na memória de programa do PIC é dado em words. Por isso deve-se dividir o endereço obtido da linha
		// do arquivo HEX (dado em bytes) por 2. Uma vez que 64 words corresponde a uma varredura de 128 bytes, é necessário dividir o
		// endereço mais uma vez por 128. Daí o denominador 256 no comando abaixo.
		//bloco_mem_prog = hex_line.address/256;
		bloco_mem_prog = (unsigned int)(Endereco24F/128);
		
		//posicao_dentro_bloco = (unsigned char)(hex_line.address/4%128 & 0x3F);
		posicao_dentro_bloco = (unsigned char)(Endereco24F/2%128 & 0x3F);
		
		// Cada instrução é formada por 4 bytes, sendo que o byte mais significativo é sempre 0x00.
		numero_instrucoes = ByteCount/4;
		TesteDebug = ((unsigned long)(blocoAtual_mem_prog))*128;
		if(FlagExecutiveProg)
			TesteDebug |= 0x00800000;

		if( bloco_mem_prog != blocoAtual_mem_prog )
		{
			// envia o bloco (fazer uma máscara no número do bloco antes de enviar para que esse número não seja inválido)
			// (cont.) ---- fazer um ponteiro do tipo unsigned short long apontar para o bloco
//	if(FlagExecutive)
//		ret=BlockProgramFlash(blocoDeInstrucoes, blocoAtual_mem_prog*128);
			if( SendBlock24FJ(blocoDeInstrucoes, blocoAtual_mem_prog*128) ) 
				ret = 0xa1;
			InicializaBloco();	// reinicia o bloco com 0xFFFFFF
//			ret=0;
		}
		blocoAtual_mem_prog = bloco_mem_prog;
		if( numero_instrucoes > (64 - posicao_dentro_bloco) )
		{
			memcpy(&blocoDeInstrucoes[posicao_dentro_bloco], DataHex, (int)(64 - posicao_dentro_bloco)*4);
			// envia o bloco ---- fazer um ponteiro do tipo unsigned short long apontar para o bloco
			if( SendBlock24FJ(blocoDeInstrucoes, blocoAtual_mem_prog*128) )
				ret = 0xb1;
			InicializaBloco();	// reinicia o bloco com 0xFFFFFF
			blocoAtual_mem_prog++;
			memcpy( &blocoDeInstrucoes[0], &DataHex[(64 - posicao_dentro_bloco)*4], (int)(ByteCount - (64 - posicao_dentro_bloco)*4) );
		}
		else 
		{
			memcpy(&blocoDeInstrucoes[posicao_dentro_bloco], DataHex, (int)ByteCount);
		}
		
		return ret;
	}
	
	switch(RecordType) 
	{
		case 0x04:
			aa = DataHex[0];
			aux = (unsigned long) aa<<8;
			bb = DataHex[1];
			aux |= (unsigned long) bb;
			aux <<= 16;
			Endereco24F &= 0x00FFFFFF;//0x0000FFFF;
			Endereco24F |= aux;
			AuxTest=aux;
			break;
		case 0x01:
			if(SendBlock24FJ(blocoDeInstrucoes, blocoAtual_mem_prog*128))
				return 0xc1;
			else
				return 0xaa;
			break;
		default:
			return ret;
			break;
	}
	return ret;
}

void Programa24FJ(void)
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

	NoP();
	NoP();
	NoP();
	
	ret=EnterICSP_Mode();
	if(!ret)
	{
		SendSIX_startup();
		LeConfigurationMemory24FJ();
		ret=0;
		Flag_Addr=false;
		ChipErase();
		delay_50us(400);

		InicializaBloco();
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
							StatusGr=0x03;			// Gravação da configuração
							if(!ProgramConfigurationMemory24FJ())
								StatusGr=0x04;		//Gravação OK
							else
								StatusGr=0xf4;
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
	}

	AbortaGr=false;
	ExitICSP_Mode();
	PGD_DIR=false;			//hightZ
	OE_U2=false;			//hightZ
	OE_U5=false;			//hightZ
	RecordType=0x00;
}

