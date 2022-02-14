#include "define_gr.h"
#include "global_gr.h"
#include "p24fj128ga006.h"

void recieve_message(void)
{
//	unsigned int count;
	rx_timeout++;
	if((U1STAbits.URXDA)&&(!U1STAbits.OERR))
	{
		rx_timeout=0;
		do
		{
			if(count_byte_rx==0)
			{	
				board_type_recieved=U1RXREG;
				BUS_CRC_rx^=board_type_recieved;
			}
			else if(count_byte_rx==1)
			{	
				addr_recieved=U1RXREG;
				BUS_CRC_rx^=addr_recieved;
			}
			else if(count_byte_rx==2)
			{	
				command_recieved=U1RXREG;
				BUS_CRC_rx^=command_recieved;
			}
			else if(count_byte_rx==3)
			{	
				rx_count=U1RXREG;
				BUS_CRC_rx^=rx_count;
			}
			else 
			{
				bus_rx_buffer[count_byte_rx-4]=U1RXREG;		// preenche buffer de recepção
				if(count_byte_rx!=(rx_count+4))
					BUS_CRC_rx^=bus_rx_buffer[count_byte_rx-4];
			}
			count_byte_rx++;									// incrementa uma posição
			if((count_byte_rx>4)&&(count_byte_rx>(rx_count+4)))
			{
				BUS_CRC_rx^=0xFF;									// se CRC =0 complementa
				//if((board_type_recieved==board_type)&&(BUS_CRC_rx==bus_rx_buffer[rx_count])&&(addr_recieved==addr_value))
			if((board_type_recieved==board_type) && (BUS_CRC_rx==bus_rx_buffer[rx_count]) && 				(addr_recieved==AddrGR))
				{
					recieved_a_message=1;
					process_message=1;
				}
				BUS_CRC_rx=0;
			}
			if(count_byte_rx>=104)
			{
				count_byte_rx=0;
				BUS_CRC_rx=0;
			}
		}while(U1STAbits.URXDA&&(recieved_a_message==0)&&(count_byte_rx<104));
	}
	if(U1STAbits.OERR)
		U1STAbits.OERR=0;

	if(rx_timeout>40)
	{
		count_byte_rx=0;
		BUS_CRC_rx=0;
	}
}

void send_message(void)
{
	static unsigned char temp;

	switch(tx_state)
	{	
		//Limpa a variável que irá receber os dados do buffer de recepção
		case 0:
			//Garante que o bit de overrum da recepção esteja em zero para não travar a comunicação
			U1STAbits.OERR=0;
			//Limpa o buffer caso exista algum lixo na recepção			
			if(U1STAbits.URXDA)	temp=U1RXREG;		// somente para limpar buffer de recepção
			else
			{
				U1STAbits.RIDLE = FALSE;		// desabilita  recepção
				RS485_DIR=TRUE;
				U1STAbits.UTXEN = TRUE;			// habilita  transmissão
				tx_state++;
//				for(count_byte_tx=0;count_byte_tx<103;count_byte_tx++)bus_rx_buffer[count_byte_tx]=0;
				count_byte_tx = 0;
			}
		break;
		case 1:
			BUS_CRC_tx=0;
			U1TXREG=board_type;				// trasnsmite tipo da placa
			BUS_CRC_tx^=board_type;			// calula CRC
			U1TXREG=AddrGR;//addr_value;				// trasnsmite endereço do escravo
			BUS_CRC_tx^=AddrGR;				// calula CRC
			U1TXREG=num_bytes;				// transmite número de bytes do pacote
			BUS_CRC_tx^=num_bytes;			// calcula CRC
			count_byte_tx=0;
			tx_state++;
		break;
		case 2:
			if(num_bytes>0)					// se número de bytes >0 transmite dados contidos em bus_tx_buffer e calcula CRC
			{
				if(!U1STAbits.UTXBF)		// aguarda por posição livre no buffer de transmissão
				{
					U1TXREG=bus_tx_buffer[count_byte_tx];
					BUS_CRC_tx^=bus_tx_buffer[count_byte_tx];
					count_byte_tx++;
				}
			}
			if(count_byte_tx>=num_bytes)
				tx_state++;
		break;
		case 3:
			if(!U1STAbits.UTXBF)			// aguarda por posição livre no buffer de transmissão
			{
//					if((num_bytes>0)||(message_to_send==2))
				{
					BUS_CRC_tx^=0xFF;			// complementa CRC
					U1TXREG=BUS_CRC_tx;		// transmite CRC
				}
			tx_state++;
			}
		break;
		case 4:
			if(U1STAbits.TRMT)				// aguarda até que todos os dados tenham sido transmitidos
			{
				//Garante que o bit de overrum da recepção esteja em zero para não travar a comunicação
				U1STAbits.OERR=0;
				//Limpa o buffer caso exista algum lixo na recepção			
				if(U1STAbits.URXDA)	temp=U1RXREG;		// somente para limpar buffer de recepção
				else
				{
					U1STAbits.UTXEN = FALSE;		// desabilita  transmissão
					RS485_DIR=FALSE;
					U1STAbits.RIDLE = TRUE;			// habilita  recepção
					tx_state++;
				}	
			}
		break;
		case 5:
			count_byte_tx=0;
			BUS_CRC_tx=0;
			tx_state=0;
			count_byte_rx=0;
			message_to_send=0;
			recieved_a_message=0;
		break;
	}
}

