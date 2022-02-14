#ifndef __PIC_PROG_H
	#define __PIC_PROG_H

	#define INPUT	1
	#define OUTPUT	0

// Maxima memoria e Palavra de configuração
// PIC16F677
	#define MaxMemory506		0x03ff
	#define AddrConfWord506		0x07ff
	#define MaxMemory677		0x07ff
	#define AddrConfWord677		0x2007
	#define MaxMemory685		0x0fff
	#define AddrConfWord685		0x2007
	#define MaxMemory1828		0x0fff
	#define AddrConfWord1828	0x8007
    #define MaxMemory344		0x0fff
    #define MaxMemory345		0x1fff
	#define AddrConfWord344 	0x8007

// Comandos de programação para os PIC16F506, PIC16F677 e PIC18F1828 ---- cada comando possui 6 bits
	#define	LOAD_CONFIGURATION	0x00
	#define	LOAD_DATA_PROG_MEM	0x02
	#define	LOAD_DATA_DATA_MEM	0x03
	#define	READ_DATA_PROG_MEM	0x04
	#define	READ_DATA_DATA_MEM	0x05
	#define	INCREMENT_ADDRESS	0x06
	#define	RESET_ADDRESS		0x16	//PIC16F1828
	#define	BEGIN_PROGRAMMING	0x08
	#define	END_PROGRAMMING		0x0E
	#define	BULK_ERASE_PROG_MEM	0x09
	#define	BULK_ERASE_DATA_MEM	0x0B


// Comandos de programação para o PIC16F15344

    #define LOAD_PC_344             0x80
	#define	LOAD_DATA_PROG_MEM_344	0x00 // PC não é alterado
	#define	READ_DATA_PROG_MEM_344	0xFC
	#define	INCREMENT_ADDRESS_344	0xF8
	#define	BEGIN_PROGRAMMING_344	0xE0
	#define	BULK_ERASE_PROG_MEM_344	0x18
	#define	END_PROGRAMMING_344		0x82


// Defines usados com a família PIC24FJ
// Entrando no modo de programação ICSP (ver figura 3-4 da especificação de programação 24FJ para mais detalhes).
// Obs.: O código para entrar no modo de programação deve ser enviado começando com o bit mais significativo
	#define	PRGM_ENTRY_CODE		0x4D434851
	#define	PRGM_ENTRY_CODE_EN	0x4D434850

// Comandos da CPU do PIC24FJ (CPU Control Codes)
	#define	SIX			0x00
	#define REGOUT		0x01

// Instruções assembly do PIC24FJ
	#define NOP			0x000000
	#define GOTO_200	0x040200



//Tempo de execução de instrução = 60 ns

// Os tempos que forem iguais tanto para o PIC16F506 quanto para o PIC 16F677 são definidos abaixo.
// Os tempos que forem diferentes serão definidos tomando-se o pior caso (maior tempo). Ou melhor ainda,
// ao se escolher um PIC para gravar, alterar seus valores de acordo.
	#define TCKL				3		// 100ns >> 2 ciclos = 120 ns > Largura do clock em Low //2
	#define TCKH				3		// 100ns >> 2 ciclos = 120 ns > Largura do clock em High//2
	#define	TDLY				2		// 1us	 >> 17 ciclos = 1,02us > Espera entre Comando e Data//1
	#define	TPROG_MEM_506		40		// 2ms	 >> 40 interrupção = 2ms // Tempo de programação                                                                                                                                                           ms // Tempo de programação
	#define	TPROG_MEM_677		70		// 3ms	 >> 60 interrupção = 3ms // Tempo de programação
	#define	TPROG_MEM_1828		50		// 2,5ms >> 50 interrupção = 2,5ms // Tempo de programação
    #define	TPROG_MEM_344		50		// 2,5ms >> 50 interrupção = 2,5ms // Tempo de programação
	#define	TPROG_DATA_677		120		// 6ms	 >> 120 interrupção = 6ms // Tempo de programação
	#define	TPROG_DATA_1828		120		// 5ms	 >> 100 interrupção = 5ms // Tempo de programação
    #define	TPROG_DATA_344		150		// 5ms	 >> 100 interrupção = 5ms // Tempo de programação
	#define TDIS				100		// 100us >> 170 ciclos = 102us > Espera entre program to compare
	#define	TERA_506			200		// 10ms	 >> 200 interrupção = 10ms // Tempo de apagamento
	#define	TERA_677			140		// 7ms	 >> 140 interrupção = 7ms // Tempo de apagamento
	#define	TERA_1828			100		// 5ms	 >> 100 interrupção = 5ms // Tempo de apagamento
    #define	TERA_344			200		// 5ms	 >> 100 interrupção = 5ms // Tempo de apagamento
	#define	TDLY3				2		// 80ns >> 2 ciclos = 120 ns > Tempo entre clock e data out valida
	#define TPPDP				84		// 5us >> 84 ciclos = 5,04 us > Tempo após VPP change
	#define	THLD0_506			84		// 5us >> 84 ciclos = 5,04 us > Tempo após VPP change
	#define	THLD0_677			31		// 2us >> 84 ciclos = 2 us > Tempo após VPP change
	#define	THLD0_1828			31		// 2us >> 84 ciclos = 2 us > Tempo após VPP change
    #define	THLD0_344			33		// 2us >> 84 ciclos = 2 us > Tempo após VPP change

// Tempos do PIC24FJ
	#define	P19					40		// 1ms	 >> 20 interrupção = 1ms
	#define	P7					500 	// 10ms	 >> 500 interrupção = 25ms // Tempo apos MCLR

//	char char_to_hex( unsigned char );
//	void monta_header(/*HEX_HEADER *,*/ unsigned char *);
//	unsigned char get_Line(/*HEX_HEADER **/);

	typedef enum 
	{
		PIC_16F506 = 1,		//1
		PIC_16F677,			//2
		PIC_16F685,			//3
		PIC_16F1828,		//4
		PIC_24FJ16,			//5
		PIC_24FJ32,			//6
		PIC_24FJ48,			//7
		PIC_24FJ64,			//8
		PIC_24FJ96,			//9
		PIC_24FJ128GA006,	//A
		PIC_16LF1828,		//B
		PIC_24FJ128GA106,	//C
		PIC_24FJ64GA104,	//D
        PIC_16F15344,       //E
        PIC_16F15345,       //F   
        PIC_16F15224,       //0x10        
	}SETUP_Modos;


#endif /* __PIC_PROG_H */
