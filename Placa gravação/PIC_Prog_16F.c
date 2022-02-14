#include "p24fj128ga006.h"
#include "define_gr.h"
#include "global_gr.h"
#include "PIC_Prog_16F.h"

char CharToHex(unsigned char x) 
	{
	if (x <= '9') 
		return x - '0';
	else 
		{
		if (x <= 'F') 
			return x - '7';
		else 
			return x - 'W';
		}
	}

void MontaHeader(unsigned char *linha) 
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

void ShiftCommand(unsigned char cmd) 
	{
	unsigned int delay=0;
	
	ClrWdt();
	
	switch(cmd) 
		{
		case LOAD_CONFIGURATION:	// b000000
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			DataProg=false;
			break;
		case LOAD_DATA_PROG_MEM:	// b000010
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			DataProg=false;
			break;
		case READ_DATA_PROG_MEM:	// b000100
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
	TRISG=TrisGInp;
			PGD_DIR=false;		//input
			PGC = 0;
//PGD_DIR=false;		//input
			NoP();
			break;
		case INCREMENT_ADDRESS:		// b000110
//LED_LD2=true;
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
//LED_LD2=false;
			break;
		case RESET_ADDRESS:		// b010110
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			break;
		case LOAD_DATA_DATA_MEM:	// b000011
			PGC = 1;
			PGD =1;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			DataProg=true;
			break;
		case READ_DATA_DATA_MEM:	// b000101
			PGC = 1;
			PGD =1;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
/*			PGD =0;		// bit 5
			Nop();
			PGC = 0;
			break;*/
			PGD =0;		// bit 5
			NoP();
	TRISG=TrisGInp;
			PGD_DIR=false;		//input
			PGC = 0;
//PGD_DIR=false;		//input
			NoP();
			break;
		case BEGIN_PROGRAMMING:		// b001000
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			if(DataProg)
				{
				delay = DelayTprogData;
				DataProg=false;
				}
			else
				delay = DelayTprogMem;
			break;
		case END_PROGRAMMING:		// b001110
			PGC = 1;
			PGD =0;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			DelayCycles(TDIS);
			break;
		case BULK_ERASE_PROG_MEM:	// b001001
			PGC = 1;
			PGD =1;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			delay = DelayTera;
			break;
		case BULK_ERASE_DATA_MEM:	// b001011
			PGC = 1;
			PGD =1;		// bit 0
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 1
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 2
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =1;		// bit 3
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 4
			NoP();
			PGC = 0;
			PGC = 1;
			PGD =0;		// bit 5
			NoP();
			PGC = 0;
			delay = DelayTera;
			break;
		default:		// Essa condição não deve ocorrer
			return;
			break;
		}
	if(delay)
		delay_50us(delay);
	}

unsigned int SendCommand(unsigned char cmd, unsigned int word) 
	{
//	unsigned char cycles = 14;		// Armazena o número de ciclos que o loop de envio dos comandos deve ter
	unsigned int ret = 0;			// Deve ser de 16 bits
	unsigned int retx;

	PGC = 0;
	
	ShiftCommand(cmd);
	
	ClrWdt();
	
	switch(cmd) 
		{
		case LOAD_DATA_DATA_MEM:
		case LOAD_DATA_PROG_MEM:
		case LOAD_CONFIGURATION:
			PGD = 0;					//start bit
			PGC = 1;
			NoP();
			PGC = 0;
			NoP();
			retx=(word & 0x0001);	//bit 0
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0002);	//bit 1
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0004);	//bit 2
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0008);	//bit 3
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0010);	//bit 4
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0020);	//bit 5
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0040);	//bit 6
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0080);	//bit 7
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0100);	//bit 8
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0200);	//bit 9
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0400);	//bit 10
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x0800);	//bit 11
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x1000);	//bit 12
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;
			retx=(word & 0x2000);	//bit 13
			PGC = 1;
			if(retx)
				PGD =1;
			else
				{
				PGD =0;
				NoP();
				}
			PGC = 0;			//stop bit
			PGD = 0;
			PGC = 1;
			NoP();
			PGC = 0;
			break;
		case READ_DATA_DATA_MEM:
		case READ_DATA_PROG_MEM:
			PGC = 1;			//start bit
			NoP();
			PGC = 0;
			NoP();
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0001;	// bit 0
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0002;	// bit 1
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0004;	// bit 2
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0008;	// bit 3
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0010;	// bit 4
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0020;	// bit 5
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0040;	// bit 6
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0080;	// bit 7
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0100;	// bit 8
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0200;	// bit 9
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0400;	// bit 10
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x0800;	// bit 11
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x1000;	// bit 12
			PGC = 1;
			NoP();
			PGC = 0;
			if(PGD_IN) 
				ret |= 0x2000;	// bit 13
			NoP();
			PGC = 1;			//stop bit
			NoP();
//			Nop();
			PGC = 0;
			PGD_DIR=true;		//output
	TRISG=TrisGInit;
//***PGD =1;
//***PGD =0;
//delay_50us(2);
			break;
		default:
			break;
		}
//	DelayCycles(DelayThld0); /************************/
	return ret;
	}

void DelayCycles(unsigned char cycles)
	{
	while(--cycles);
	}
	
