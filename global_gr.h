//Arquivo de definições de variaveis
#ifdef	x
	#define Global
#else
	#define Global extern
#endif
	
#define NoP()       __asm("nop");
#define ClrWdt()    __asm("CLRWDT");
#define Sleep()     __asm("PWRSAV #0")

Global volatile char bus_rx_buffer[120];
Global volatile char bus_tx_buffer[120];
Global char buffer[50];
Global char BUS_CRC_tx;
Global char BUS_CRC_rx;
	
Global unsigned long TesteDebug;

/****************************************************************************/
Global volatile char bus_tx_buffer_U2[50];
//Global char bus_rx_buffer_U2[512];
Global volatile char buffer_U2[50];
Global char BUS_CRC_tx_U2;
Global char BUS_CRC_rx_U2;
Global unsigned char board_type_recieved_U2;
Global unsigned char board_type_U2;
Global unsigned char addr_recieved_U2;
Global unsigned char command_recieved_U2;
Global unsigned char count_byte_rx_U2;
Global unsigned char count_byte_line_U2;
Global unsigned char count_byte_tx_U2;
Global unsigned char num_bytes_U2;
Global unsigned int rx_timeout_U2;
Global unsigned char recieved_a_message_U2;
Global unsigned char tx_state_U2;
Global unsigned char process_message_U2;
Global unsigned char message_to_send_U2;
Global volatile unsigned char CheckSum;
Global volatile unsigned char CheckSum_x;
Global volatile unsigned char CheckSum_y;
Global unsigned char TempHex;
Global unsigned int tx_delay_U2;
Global unsigned char ReceiverState;

/****************************************************************************/

Global unsigned char board_type_recieved;
Global unsigned char addr_value;
Global unsigned char addr_recieved;
Global unsigned char send_msg_state;
Global unsigned char command_recieved;

Global unsigned char rx_count;
Global volatile unsigned char count_byte_tx;
Global unsigned char num_bytes;

Global unsigned char BUS_ACK;
Global unsigned char full_recieved;
Global unsigned char broadcast;
Global unsigned char rx_timeout;
Global unsigned char count_byte_rx;
Global unsigned char recieved_a_message;
Global unsigned char tx_state;
Global unsigned char process_message;
Global unsigned char message_to_send;
Global unsigned char time_adc;
Global unsigned char temp;
Global unsigned char NumProg;

Global unsigned int mseg_temp;
Global unsigned int mseg_temp_x;
Global unsigned int mileseg_temp;
Global unsigned int seconds_temp;
Global unsigned int ADCValue;
Global volatile unsigned int time_delay;
Global unsigned int tx_delay;

Global unsigned int ADCValue;
Global unsigned long ADCValue_1;

Global unsigned char temp_debug; //usar somente para DEBUG

Global union
	{ 
	unsigned char as_char;
	struct
		{
		unsigned	_com			: 1;	//
//		unsigned	_data_prog		: 1;	//
		unsigned	_flagaddr		: 1;	//
		unsigned	_SetVdd3v		: 1;	//
		unsigned	_SetVdd5v		: 1;	//
		unsigned	_prog			: 1;	//
		unsigned	_Executive		: 1;	//
		unsigned	_ExecutiveProg	: 1;	//
		unsigned					: 1;	//
		};
	}_flags_2;
#define status_flag_2		_flags_2.as_char
#define flag_key			_flags_2._com
#define Flag_Addr			_flags_2._flagaddr
#define SetVdd3v			_flags_2._SetVdd3v
#define SetVdd5v			_flags_2._SetVdd5v
#define Programado			_flags_2._prog
#define FlagExecutive		_flags_2._Executive
#define FlagExecutiveProg	_flags_2._ExecutiveProg

Global union
	{ 
	unsigned char as_char;
	struct
		{
		unsigned	_com			: 1;	//
		unsigned	_com_x			: 1;	//
		unsigned	_data_prog		: 1;	//
		unsigned	_AbortaGr		: 1;	//
		unsigned	_index			: 1;	//
		unsigned	_erro			: 1;	//
		unsigned	_chave			: 1;	//
		unsigned	_flag_prog		: 1;	//
		};
	}_flags;
#define status_flag		_flags.as_char
#define flag_com		_flags._com
#define flag_com_x		_flags._com_x
#define DataProg		_flags._data_prog
#define AbortaGr		_flags._AbortaGr
#define Index			_flags._index
#define Erro			_flags._erro
#define ChaveAcionada	_flags._chave
#define FlagProg		_flags._flag_prog

// Estrutura que contém uma linha obtida de um arquivo .hex (menos o caractere ':' e o checksum)
// Ex.: | : | byte_count (1 byte) | address (2 bytes) | record_type (1 byte) | data (variável) | checksum (1 byte) |


/*Global union 
	{
	unsigned char ByteCount;
	unsigned int Address;
	unsigned char RecordType;
	unsigned char Data[16];
	}HexLine;*/
	

Global volatile unsigned char ByteCount;
Global volatile unsigned int Address;
Global volatile unsigned char RecordType;
Global volatile unsigned char DataHex[16];
	
Global unsigned char DelayTera;			// Tempo de apagamento
Global unsigned char DelayTprogMem;		// Tempo de programação (prog memory)
Global unsigned char DelayTprogData;	// Tempo de programação (data memory)
Global unsigned char DelayThld0;		// Tempo após VPP change
Global unsigned int DelayProg;
Global unsigned int ContError;

Global unsigned char flag_344;

void recieve_message(void);
void send_message(void);
void start_ADC(void);

void delay_50us(unsigned int);
void delay_ms(unsigned int);
void ShiftCommand(unsigned char);
void wait(unsigned int);
unsigned int SendCommand(unsigned char, unsigned int);

void MemorySendBlock(unsigned char*,int);
void MemoryGetBlock(unsigned char*,int);
void MemorySendCmd(char);
void MemorySendAddr(unsigned long);
void recieve_message_U2(void);
void send_message_U2(void);
void ProcessaArquivo(void);
void ChaveState(void);
void InitGr(unsigned char);
void DelayCycles(unsigned char);
void ExitProgMode506(void);
void Programa506(void);
void MontaProg506(void);
void MontaProg1828(void);
void ProgData1828(void);
void ExitProgMode677(void);
void Programa677(void);
void ProgFourWord677(void);
void ProgConfigMem677(void);
void ExitProgMode1828(void);
void Programa1828(void);
void Prog32Word1828(void);
void ProgConfigMem1828(void);
void MontaHeader(unsigned char*);
void SendSIX_Command(unsigned long);
void SendKeySequence(void); 
void ExitResetVector(void);
void AguardaWR1(void);
void ChipErase(void);
void PackInstructions(volatile unsigned long*, unsigned long*); 
void BlockProgramCycle(unsigned long*, unsigned int);
void InicializaBloco(void);
void Programa24FJ(void);
void SendSIX_startup(void); 
void ExitICSP_Mode(void);
void ProgExecutiveProg(void);
void Programa24fjExecutiveProg(void);
void VerifyExecutive(void);
void ProgWord1828(void);
void TesteMemory(unsigned char);

void Programa24fjExecutiveFlash(void);
void SendExecutiveData(unsigned int);
unsigned int ReadExecutiveData(void);
unsigned char BlockProgramCycleExecutive();
unsigned char BlockProgramFlash(unsigned long*, unsigned int );

short MemoryBusyPin(void);
short MemoryReadSector(unsigned long,unsigned char*);
short MemoryReadN(unsigned long,unsigned char*,int);
short MemoryLog(void);
short MemoryWriteSector(unsigned long,unsigned char*);
short MemoryReadLabel(unsigned long,unsigned char*);
short MemoryWriteLabel(unsigned long,unsigned char*);
short MemoryEraseBlock(unsigned long);

char CharToHex(unsigned char);
char GravaBuffer(void);
unsigned char MontaBloco64(void);
unsigned char UnpackInstructions(unsigned int*, unsigned long*);
unsigned char ReadBlockFromProgMem(unsigned int);
unsigned char ProgramConfigurationMemory24FJ(void);
unsigned char SendBlock24FJ(unsigned long*, unsigned int);
unsigned char ProgOneWord506(void);
unsigned char VerifyProgMem677(void);
unsigned char VerifyProgMem1828(void);
unsigned char LeConfigurationMemory24FJ(void);
unsigned char LeAppID(void);
unsigned char EnterProgMode506(void);
unsigned char EnterProgMode677(void);
unsigned char EnterProgMode1828(void);
unsigned char BulkEraseProgData506(void);
unsigned char BulkEraseProgData677(void);
unsigned char BulkEraseProgData1828(void);
unsigned char EnterICSP_Mode(void);
unsigned char ProgramaBloco(unsigned int, unsigned int, unsigned int);
unsigned char ProgramaConfigBit(unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int SendREGOUT_Command(void); 


unsigned char BulkEraseProgData344(void);
unsigned char EnterProgMode344(void);
void ExitProgMode344(void);
void Programa344(void);
void ProgData344(void);
void MontaProg344(void);
void ProgWord344(void);
unsigned char VerifyProgMem344(void);
void ProgConfigMem344(void);

Global unsigned int Temp;

Global unsigned char adapt_224;


Global volatile unsigned int *Instrucoes16F;
Global volatile unsigned char BufferLine[512];
Global volatile unsigned char BufferTeste[512];
Global volatile unsigned char BufferTesteFlash[512];
Global volatile unsigned char MemoryBuffer[513];//1024];
Global volatile unsigned long packed_instructions[6];	// corresponde às instruções MOV com os registradores W0, W1, W2, W3, W4 e W5.
Global volatile unsigned char VersaoSW[4][3];
Global volatile unsigned char StatusGr;
Global unsigned char Processador;
Global unsigned char AddrGR;
Global unsigned char LoopFlash;

Global unsigned int CountBlock;
Global unsigned int teste_count;
Global unsigned int IndexBuffer;
Global unsigned int MaxMemory;

Global unsigned long LastAddr;
Global unsigned long AddrFlash;
Global unsigned long EnderecoFlash;
Global unsigned long Endereco;
Global unsigned long Endereco16F;
Global unsigned long Endereco24F;
Global unsigned long EnderecoBase;
Global unsigned long DestEnder;
Global unsigned long EndFinal;

Global unsigned long conf_address1;
Global unsigned long conf_address2;
Global unsigned long conf_address3;
Global unsigned long conf_address4;

Global unsigned int ADCValueVpp;
Global unsigned int ADCValueVdd;
Global unsigned int ADCValueV;
/*
union
	{ 
	unsigned long as_int;
	struct
		{
		unsigned char _AddHi;
		unsigned char _AddLow;
		};	
	}_Packed;
#define codigo_rf		_Packed.as_long
#define	codigo_rf_B0	_Packed._B0
*/
Global unsigned int WordProg[2048];
Global unsigned int AddrProg;
Global unsigned int ConfWord;
Global unsigned int ContByteProg;
Global unsigned int AddrData;

/****************************************************/
Global volatile unsigned int BufferTemporario[100];
Global volatile unsigned long BufferError[10];
Global volatile unsigned int AddressTeste1;
Global volatile unsigned int AddressTeste2;
Global unsigned char ContPacked;
Global unsigned char CountRead;
Global unsigned char CountWord;

Global unsigned int cw1;
Global unsigned int cw2;
//Global unsigned int cw2x;
Global unsigned int cw3;
Global unsigned int cw4;

Global volatile unsigned long AuxTest;



void isp_inc_pointer (void);
void isp_send (unsigned int data, unsigned char n);
unsigned int isp_read_16 (void);
unsigned char enter_progmode (void);
unsigned char exit_progmode (void);
void isp_read_pgm (unsigned int * data, unsigned char n);
void isp_write_pgm (unsigned int * data, unsigned char n);
void isp_mass_erase (void);
void isp_reset_pointer (void);
void isp_send_8_msb (unsigned char data);
unsigned int isp_read_8_msb (void);
unsigned int isp_read_16_msb (void);
unsigned char p16c_enter_progmode (void);
void p16c_set_pc (unsigned long pc);
void p16c_bulk_erase (void);
void p16c_load_nvm (unsigned char inc, unsigned int data);
unsigned int p16c_read_data_nvm (unsigned char inc);
void p16c_begin_prog (unsigned char cfg_bit);
void p16c_isp_write_cfg (unsigned int data, unsigned int addr);

void grava_pic16f15344(void);
unsigned char EnterProgMode344_xx(void);