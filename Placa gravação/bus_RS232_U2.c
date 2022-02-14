#include "define_gr.h"
#include "global_gr.h"
#include "p24fj128ga006.h"

void recieve_message_U2(void)
{
	rx_timeout_U2++;
	if((U2STAbits.URXDA)&&(!U2STAbits.OERR))
	{
		rx_timeout_U2=0;
		do
		{
			if(count_byte_rx_U2==0)
			{	
				buffer_U2[count_byte_rx_U2]=U2RXREG;
				if(buffer_U2[0]==':'||buffer_U2[0]==';'||buffer_U2[0]=='A')
					count_byte_rx_U2++;
				else
					count_byte_rx_U2=50;;
			}
			else if(count_byte_rx_U2==1)
			{
				buffer_U2[count_byte_rx_U2]=U2RXREG;
				count_byte_rx_U2++;
			}
			else if(count_byte_rx_U2==2)
			{
				buffer_U2[count_byte_rx_U2]=U2RXREG;
				count_byte_rx_U2++;
				if(buffer_U2[0]==':')
					{
					count_byte_line_U2=(CharToHex(buffer_U2[1]) << 4);
					count_byte_line_U2|=(CharToHex(buffer_U2[2]));
					}
			}
			else
			{	
				buffer_U2[count_byte_rx_U2]=U2RXREG;
				count_byte_rx_U2++;
			}
			if((count_byte_rx_U2>=10)&&(((count_byte_line_U2*2)+10)==(count_byte_rx_U2-1)))
			{
				recieved_a_message_U2=1;
			}
		}while(U2STAbits.URXDA&&(recieved_a_message_U2==0)&&(count_byte_rx_U2<43));
	}
	if(U2STAbits.OERR)
		U2STAbits.OERR=0;

	if(rx_timeout_U2>5000)	//40)
	{
		count_byte_rx_U2=0;
		BUS_CRC_rx_U2=0;
	}
}

void send_message_U2(void)
{
	if(tx_delay_U2>0)
		tx_delay_U2--;
	if(tx_delay_U2==0)
	{
		switch(tx_state_U2)
		{	
			//Limpa a vari�vel que ir� receber os dados do buffer de recep��o
			case 0:
				//Garante que o bit de overrum da recep��o esteja em zero para n�o travar a comunica��o
				U2STAbits.OERR=0;
				//Limpa o buffer caso exista algum lixo na recep��o			
				if(U2STAbits.URXDA)	temp=U2RXREG;		// somente para limpar buffer de recep��o
				else
				{
					U2STAbits.RIDLE = FALSE;		// desabilita  recep��o
					U2STAbits.UTXEN = TRUE;			// habilita  transmiss�o
					tx_state_U2++;
					count_byte_tx_U2 = 0;
				}
			break;
			case 1:
				if(num_bytes_U2>0)					// se n�mero de bytes >0 transmite dados contidos em bus_tx_buffer_U2 e calcula CRC
				{
					if(!U2STAbits.UTXBF)		// aguarda por posi��o livre no buffer de transmiss�o
					{
						U2TXREG=bus_tx_buffer_U2[count_byte_tx_U2];
						count_byte_tx_U2++;
					}
				}
				if(count_byte_tx_U2>=num_bytes_U2)
					tx_state_U2++;
			break;
			case 2:
				if(U2STAbits.TRMT)				// aguarda at� que todos os dados tenham sido transmitidos
				{
					//Garante que o bit de overrum da recep��o esteja em zero para n�o travar a comunica��o
					U2STAbits.OERR=0;
					//Limpa o buffer caso exista algum lixo na recep��o			
					if(U2STAbits.URXDA)	temp=U2RXREG;		// somente para limpar buffer de recep��o
					else
					{
						U2STAbits.UTXEN = FALSE;		// desabilita  transmiss�o
						U2STAbits.RIDLE = TRUE;			// habilita  recep��o
						tx_state_U2++;
					}	
				}
			break;
			case 3:
				count_byte_tx_U2=0;
				BUS_CRC_tx_U2=0;
				tx_state_U2=0;
				count_byte_rx_U2=0;
				message_to_send_U2=0;
			break;
		}
	}	
}

