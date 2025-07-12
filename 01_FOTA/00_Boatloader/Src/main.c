/*********************************************************************
* File Name    	: 	main.c                                 			 *
* Author       	: 	Mahmoud Gamal                                    *
* Version      	: 	1.0.0                                            *
* Date  		: 	19/9/2023                                        *
* Description   : 	Bootloader				  			             *
**********************************************************************/

#include "COMMON/bit_math.h"
#include "COMMON/std_types.h"


#include "MCAL/rcc/rcc_interface.h"
#include "MCAL/gpio/gpio_interface.h"
#include "MCAL/usart/usart_interface.h"

#include "MCAL/mfdi/MFDI_interface.h"
#include "SERVICE/SPARSE_interface.h"


#define   NEW_UPDATE_REQUEST     0x01u
#define   READY_TO_RECEIVE       0x02u
#define   REQUEST_ACCPETED		 0x05u
#define   START_SENDING	         0x07u
#define   RECORD_RECEIVED        0x08u




u8 G_u8ReceiveBuffer[100];
u8 G_u8RecordCounter;
u8 G_u8WriteRequest=1;

ST_MUSART_cfg_t gl_uddtUartOfESP =
{
		.copy_HardwareFlowControl = MUSART_DISABLE,
		.copy_uddtDataSizeOption = MUSART_DATA_SIZE_8_BIT,
		.copy_uddtStopBitSelection = MUSART_ONE_STOP_BIT,
		.copy_uddtParityControl = MUSART_PARITY_DISABLED,
		.copy_uddtParitySelection = MUSART_EVEN_PARITY,
		.copy_uddtBuadRateOption = MUSART_BUAD_RATE_115200_bps,
		.copy_uddtSamplingModeOption = MUSART_SAMPLING_BY_16,
		.copy_uddtTransferDirection = MUSART_TX_RX,
		.copy_uddtUartClockInit.clockOutput = 0,
		.copy_uddtUartClockInit.clockPolarity = 0,
		.copy_uddtUartClockInit.clockPhase = 0,
		.copy_uddtUartClockInit.lastBitClockPulse = 0
};


typedef void(*APP_Call_t)(void);
APP_Call_t AddressToCall = NULL;

void APP_voidEntryPoint(void)
{
	/* Set the pointer to the end of vector table (startup code of Application) */
	AddressToCall = *(APP_Call_t*)0x08000004;
	//MGPIO_uddtSetPinVal(MGPIOA_PERIPHERAL, MGPIO_PIN0, 1);

	AddressToCall();

}

int main(void)
{


	u8 L_u8ReceivedStatus=0,L_u8data;
	/* Initialize RCC with SYS_CLK=16MHz and AHB frequency equals SYS_CLK/2 */
	/* enable RCC of micro_controller  */
		MRCC_Init();
		/* enable clock to PORTA  */
		MRCC_enablePeripheral(MRCC_AHP1_BUS, MRCC_GPIOA_PERIPHERAL);
		/* enable clock to USART2 */
		MRCC_enablePeripheral(MRCC_APB1_BUS, MRCC_USART2_PERIPHERAL);
		/*###################################### Configure USART2 pins for EspMcu #################################################*/
		/*initialise ALT pinA2 for UART */
		ST_MGPIO_altPinCfg_t lo_altUartPinA2 = {MGPIOA_PERIPHERAL,MGPIO_PIN2,MGPIO_ALTFN_7,
				MGPIO_OUTPUT_RESISTOR_PUSH_PULL,MGPIO_OUTPUT_SPEED_MEDIUM,MGPIO_PULL_FLOATING};
		/*initialise ALT pinA3 for UART */
		ST_MGPIO_altPinCfg_t lo_altUartPinA3 = {MGPIOA_PERIPHERAL,MGPIO_PIN3,MGPIO_ALTFN_7,
		MGPIO_OUTPUT_RESISTOR_PUSH_PULL,MGPIO_OUTPUT_SPEED_MEDIUM,MGPIO_PULL_FLOATING};
		/* set pin A2 to alternate
		* set pin A2 to be push pull
			 * set pin A2 speed to medium
			 * set pin A2 alternate 7 */
		MGPIO_uddtInitAltPin(&lo_altUartPinA2);
		/* set pin A3 to alternate
		* set pin A3 to be push pull
		* set pin A3 speed to medium
		* set pin A3 alternate 7 */
		MGPIO_uddtInitAltPin(&lo_altUartPinA3);

		/*initialise UART2 to use with EspMc */
		MUSART_uddtInit(MUART2_PERIPHERAL , &gl_uddtUartOfESP);
		/*enable UART2 to use with EspMc */
		MUSART_uddtEnable(MUART2_PERIPHERAL);
		//MGPIO_uddtSetPinMode(MGPIOA_PERIPHERAL, MGPIO_PIN0, MGPIO_MODE_OUTPUT);
		//MGPIO_uddtSetPinVal(MGPIOA_PERIPHERAL, MGPIO_PIN0, 0);

	while(1)
	{

		L_u8ReceivedStatus = MUSART_uddtReadDataRegister(MUART2_PERIPHERAL, &G_u8ReceiveBuffer[G_u8RecordCounter]);
		if(L_u8ReceivedStatus==1)
		{
			/*indicate The end Of the Record*/
			if(G_u8ReceiveBuffer[G_u8RecordCounter]=='\n')
			{
				if(G_u8WriteRequest==1)
				{
					/*Erase The Application Code*/
					MFDI_voidEraseAppArea(0);
					G_u8WriteRequest=0;
				}

				/*Parse The Record and Write it to flash*/
				PARSE_voidParseRecord(G_u8ReceiveBuffer);
				/*Send ok to tool to send the next Record */
				MUSART_uddtTransmitString(MUART2_PERIPHERAL,(uint8_t *)"OK");
				/*Reset Buffer Counter*/
				G_u8RecordCounter=0;

			}

			else
			{
				G_u8RecordCounter++;
			}
		}

		if(G_u8ReceiveBuffer[8]=='1')
		{

			APP_voidEntryPoint();


		}
	}
}

