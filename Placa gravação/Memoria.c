#include "define_gr.h"
#include "global_gr.h"
#include "memoria.h"
#include "p24fj128ga006.h"
//#include "programador.h"

#define MemoryBusOut()		TRISE=TrisEDataOut;
#define MemoryBusIn()		TRISE=TrisEDataIn;

/******************************************************************
	MemorySendBlock()

	Escreve o bloco de dados na memoria
	("size" bytes) com um buffer apontado por Dados.
*******************************************************************/ 
void MemorySendBlock(unsigned char *Dado, int size)
{
	do
	{
		MemoryWE = 0;
		NoP();
		MemoryIO=*Dado;
		MemoryWE = 1;
		Dado++;
	} while(--size);
}

/******************************************************************
	MemoryGetByte()

	Le um byte da memoria sem ajustar direção do buffer
*******************************************************************/ 
short MemoryGetByte()
{
	short DataIn;
	MemoryRD = 0;
	NoP();
	DataIn=MemoryIO;	
	MemoryRD = 1;
  	return (DataIn);
}

/******************************************************************
	MemoryGetBlock()

	Le o bloco de dados do cartão smc ("size" bytes)
	e coloca num buffer	apontado por Dados.
*******************************************************************/ 
void MemoryGetBlock(unsigned char *Dado, int size)
{

	MemoryBusIn();

	do
	{
  		*Dado++ = MemoryGetByte();	
	} while(--size);
	MemoryBusOut();
}

/******************************************************************
	MemorySendCmd()

	Seleciona a memoria e envia um comando.
*******************************************************************/ 
void MemorySendCmd( char cmd )
{
	MemoryBusOut();
	MemoryCS=false;
	MemoryBusyPin();
	MemoryCLE = 1;
	MemoryWE = 0;
	MemoryIO=cmd;
	MemoryWE = 1;
	MemoryCLE = 0;
}                                                    

/******************************************************************
	MemorySendAddr()

	envia um endereço.
*******************************************************************/ 
void MemorySendAddr( unsigned long arg )
{
	MemoryALE = 1;							/* Address latch */
	MemoryWE = 0;
	MemoryIO=arg;							/* Address */
	MemoryWE = 1;
	MemoryWE = 0;
	MemoryIO=(arg >> 9);
	MemoryWE = 1;
	MemoryWE = 0;
	MemoryIO=(arg >> 17);
	MemoryWE = 1;
	MemoryALE = 0;
}                                                    

/******************************************************************
	MemoryBusyPin()

	Verifica se o cartão está ocupado através do pino R/B.
	Só deveria voltar quando a memória estivesse ready, mas foi
	colocado um timeout longo para não travar em caso de falha.
*******************************************************************/ 
short MemoryBusyPin( void )
{
	#define N_BUSY	5000

	static int temp;
	temp = N_BUSY;
	while((temp--) && !MemoryBUSY);
	if(MemoryBUSY)
		return( 1 );
	else
		return( 0 );
}


/******************************************************************
	MemoryReadSector()

	Le uma pagina da memoria (512 bytes) e coloca num buffer
	apontado por OutBuf.
	Retorno != 0 OK
*******************************************************************/ 
short MemoryReadSector( unsigned long Endereco, unsigned char *OutBuf )
{
	MemorySendCmd( MemoryREAD_A );				/* Envia Comando */
    MemorySendAddr( Endereco & ~0x000001ff );	/* Envia Endereço */
	MemoryBusyPin();							/* Aguarda cartão */
	MemoryGetBlock( OutBuf, MemorySECTOR );
	MemoryBusyPin();							/* Aguarda cartão  */
	return MemoryLog();							/* Erro no comando */
}

/******************************************************************
	MemoryReadN()

	Lê Size bytes de uma pagina da memoria e coloca num buffer
	apontado por OutBuf.
	Deve-se garantir que Size não ultrapasse o limite da pagina.
	Retorno != 0 OK
*******************************************************************/ 
short MemoryReadN( unsigned long Endereco, unsigned char *OutBuf, int Size )
{
	if( Endereco & 0x100 )
		MemorySendCmd( MemoryREAD_B );			/* Envia Comando */
	else                                  
		MemorySendCmd( MemoryREAD_A );			/* Envia Comando */
    MemorySendAddr( Endereco );					/* Envia Endereço */
	MemoryBusyPin();							/* Aguarda cartão */
	MemoryGetBlock( OutBuf, Size );
	MemoryBusyPin();								/* Aguarda cartão  */
	return MemoryLog();							/* Erro no comando */
}

/******************************************************************
	MemoryLog()

	Retorna 0 se erro ou o STATUS da memoria
*******************************************************************/ 
short MemoryLog( void )
{
	short tmp;
	
	MemoryBusyPin();					/* Aguarda cartão */
	MemorySendCmd( MemoryREAD_STATUS );	/* Envia Comando */
	MemoryBusIn();
	tmp = MemoryGetByte();
	MemoryBusOut();
//	smc_deactivate();
    if(tmp == 0x70 )
		return tmp;						/* Operação sem erro ! */
	else
		return 0;    
}

/******************************************************************
	MemoryWriteSector()

	Escreve um setor no cartão mmc (256 words) com buffer
	apontado por OutBuf.
	Retorno != 0 OK
*******************************************************************/ 
short MemoryWriteSector( unsigned long Endereco, unsigned char *OutBuf)
{
	MemorySendCmd( MemoryREAD_A );				/* Ajusta ponteiro */
	MemorySendCmd( MemoryDATA_IN );				/* Envia Comando   */
    MemorySendAddr( Endereco & ~0x000001ff );	/* Envia Endereço  */
	MemorySendBlock( OutBuf, MemorySECTOR );
	MemorySendCmd( MemoryPROGRAM );				/* Envia Comando   */
	MemoryBusyPin();							/* Aguarda cartão  */
	return MemoryLog();							/* Erro no comando */
}


/******************************************************************
	MemoryReadLabel()

	Le uma tarja do cartão smc (8 words) e coloca num buffer
	apontado por OutBuf.
	Retorno != 0 OK
*******************************************************************/ 
short MemoryReadLabel( unsigned long Endereco, unsigned char *OutBuf )
{
	MemorySendCmd( MemoryREAD_C );				/* Envia Comando   */
    MemorySendAddr( Endereco & ~0x000001ff );	/* Envia Endereço  */
	MemoryBusyPin();							/* Aguarda cartão  */
	MemoryGetBlock( OutBuf, 16); //(MemoryPAGE - MemorySECTOR) );
	MemorySendCmd( MemoryRESET );				/* Envia Comando   */
	MemoryBusyPin();							/* Aguarda cartão */
	return MemoryLog();							/* Erro no comando */
}


/******************************************************************
	MemoryWriteLabel()

	Escreve uma tarja do cartão mmc (8 words) com buffer
	apontado por OutBuf.
	Retorno != 0 OK
*******************************************************************/ 
short MemoryWriteLabel( unsigned long Endereco, unsigned char *OutBuf)
{
	MemorySendCmd( MemoryREAD_C );				/* Ajusta ponteiro */
	MemorySendCmd( MemoryDATA_IN );				/* Envia Comando   */
    MemorySendAddr( Endereco & ~0x000001ff );	/* Envia Endereço  */
	MemorySendBlock( OutBuf, 3); //(MemoryPAGE - MemorySECTOR) );
	MemorySendCmd( MemoryPROGRAM );				/* Envia Comando   */
	MemoryBusyPin();							/* Aguarda cartão  */
	return MemoryLog();							/* Erro no comando */
}

/******************************************************************
	MemoryEraseBlock()

	Apaga um bloco de 16KBytes do cartão mmc.
	Se o cartão for menor que 16MB, apaga dois blocos de 8KBytes.
	Retorno != 0 OK
*******************************************************************/ 
short MemoryEraseBlock( unsigned long Endereco)
{
	MemorySendCmd( MemorySET_BLOCK_ERASE );		/* Envia Comando   */
	MemoryALE = 1;								/* Address latch */
	MemoryWE = 0;
	MemoryIO=(Endereco >> 9);
	MemoryWE = 1;
	MemoryWE = 0;
	MemoryIO=(Endereco >> 17);
	MemoryWE = 1;
	MemoryALE = 0;
	MemorySendCmd( MemoryBLOCK_ERASE );			/* Envia Comando   */
	MemoryBusyPin();							/* Aguarda cartão  */
	return MemoryLog();							/* Erro no comando */
}


