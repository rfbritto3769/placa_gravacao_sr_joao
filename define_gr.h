
#ifndef _DEFINE_H
	#define _DEFINE_H
	
	#define	board_type	'G'
	#define OUTPUT	0
	#define INPUT	1
	#define OFF		0x00
	#define ON		0x01
	#define FALSE	0x00
	#define TRUE	0x01
	#define false	0x00
	#define true	0x01
	
	#define Programa_1  0x0000000
	#define Programa_2  0x0080000
	#define Programa_3  0x0100000
	#define Programa_4  0x0180000
//	#define Programa_5  0x0200000
	#define Programa_5  0x0280000
	#define Programa_7  0x0300000
	
	#define EndFinal_1	0x007fe00
	#define EndFinal_2	0x00ffe00
	#define EndFinal_3	0x017fe00
	#define EndFinal_4	0x01ffe00
//	#define EndFinal_5	0x027fe00
	#define EndFinal_5	0x02ffe00
	
#define Vdd_OFF(){	\
	VDD_05=OFF;\
	VDD_03=OFF;\
	NoP();}

#define Vdd_3V(){	\
	VDD_05=OFF;\
	VDD_03=ON;\
	NoP();}

#define Vdd_5V(){	\
	VDD_03=OFF;\
	VDD_05=ON;\
	NoP();}

#define Vpp_GND_ON(){	\
	VPP_GND=OFF;\
	NoP();}

#define Vpp_GND_OFF(){	\
	VPP_GND=ON;\
	NoP();}

	#define Vpp_OFF(){	\
	VPP_05=OFF;\
	VPP_09=OFF;\
	VPP_13=OFF;\
	VPP_03=OFF;\
	NoP();}

#define Vpp_3V(){	\
	VPP_05=OFF;\
	VPP_09=OFF;\
	VPP_13=OFF;\
	VPP_03=ON;\
	NoP();}

#define Vpp_5V(){	\
	VPP_03=OFF;\
	VPP_09=OFF;\
	VPP_13=OFF;\
	VPP_05=ON;\
	NoP();}

#define Vpp_9V(){	\
	VPP_03=OFF;\
	VPP_05=OFF;\
	VPP_13=OFF;\
	VPP_09=ON;\
	NoP();}

#define Vpp_13V(){	\
	VPP_03=OFF;\
	VPP_05=OFF;\
	VPP_09=OFF;\
	VPP_13=ON;\
	NoP();}

#define BitTestSC() {__asm__ volatile ("btsc PORTG, #7");}

	/**************************************************************
	  ----------------------- Portas ------------------------------
	 **************************************************************/
	
	/************************ Porta B *****************************/
	#define	VPP_03			_LATB2				// O
	#define	VPP_05			_LATB3				// O
	#define	VPP_09			_LATB4				// O
	#define	VPP_13			_LATB5				// O
	#define	VPP				_LATB6				// O
	#define	VPP_GND			_LATB7				// O
	#define	VDD_03			_LATB8				// O
	#define	VDD_05			_LATB9				// O
	#define	VDD_GR			_LATB10				// O
//	#define	AD_VDD			_RB11				// I
//	#define	AD_VPP			_RB12				// I
//	#define	AD_VPP			_RB13				// I
	#define	PGD_DIR			_LATB14				// O
//	#define	AN15			_RB15				// I
	
	#define	MCLR			VPP					// O
	#define	TrisBInit		0XB800

	/************************ Porta C *****************************/
	#define	LED_LD1			_LATC13				// O
	#define	LED_LD2			_LATC14				// O

	#define	TrisCInit		0x9FFF

	/************************ Porta D *****************************/
	#define	MemoryBUSY		_LATD0				// I
	#define	MemoryRD		_LATD1				// O
	#define	MemoryCS		_LATD2				// O
	#define	MemoryCLE		_LATD3				// O
	#define	MemoryALE		_LATD4				// O
	#define	MemoryWE		_LATD5				// O
	#define	ADDR_GR_01		_RD6				// I
	#define	ADDR_GR_02		_RD7				// I
	#define	ADDR_GR_03		_RD8				// I
	#define	CHAVE_S1		_RD9				// I
//	#define					_RD10				// I
//	#define					_RD11				// I

	#define MemoryControle	PORTD

	#define	TrisDInit		0xFFC1

	/************************ Porta E *****************************/
	#define	D0				_RE0				// I/O
	#define	D1				_RE1				// I/O
	#define	D2				_RE2				// I/O
	#define	D3				_RE3				// I/O
	#define	D4				_RE4				// I/O
	#define	D5				_RE5				// I/O
	#define	D6				_RE6				// I/O
	#define	D7				_RE7				// I/O
	#define MemoryIO		PORTE

	#define	TrisEDataIn		0xFFFF
	#define	TrisEDataOut	0xFF00

	/************************ Porta F *****************************/
//	#define					_RF0				// I
//	#define					_RF1				// I
	#define	RX1				_RF2				// I
	#define	TX1				_LATF3				// O
	#define	RS232_IN		_RF4				// I
	#define	RS232_OUT		_LATF5				// O
	#define	RS485_DIR		_LATF6				// O

//	#define	TrisFPgdIn	0xFF95	
//	#define	TrisFPgdOut	0xFF94
	#define	TrisFInit	0xFF97

	/************************ Porta G *****************************/
	#define	OE_U2			_LATG2				// O
	#define	OE_U5			_LATG3				// O
	#define	PGC				_LATG6				// O
	#define	PGD_IN			_RG7				// I
	#define	PGD				_LATG8				// O
//	#define					_RG9				// I

	#define	TrisGInit		0xFEB3
	#define	TrisGInp		0xFFB3

#endif
