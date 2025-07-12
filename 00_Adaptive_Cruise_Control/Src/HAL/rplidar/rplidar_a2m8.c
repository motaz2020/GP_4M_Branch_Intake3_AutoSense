/*

 * rplidar_a2m8.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Amr Mohammed Hassan
 */
#include "STD_TYPES.h"
#include "usart_interface.h"
#include "STK_Interface.h"
#include "rplidar_a2m8.h"
#include "tmr_interface.h"
#include <string.h>
#include "GPIO_interface.h"


u8 Scan_Discriptor_Msg[] = {0xA5 , 0x5A , 0x05 , 0x00 , 0x00 , 0x40 , 0x81}; // this should by sent by the lidar after each scan_request from the host
u8 Health_Discriptor_Msg[] = {0xA5 , 0x5A , 0x03 , 0x00 , 0x00 , 0x00 , 0x06}; // this should by sent by the lidar after each health_request from the host
u8 Info_Discriptor_Msg[] = {0xA5 , 0x5A , 0x14 , 0x00  , 0x00 , 0x00 , 0x04}; // this should by sent by the lidar after each info_request from the host
u8 SampleRate_Discriptor_Msg[] = {0xA5 , 0x5A , 0x04 , 0x00 , 0x00 , 0x00 , 0x15}; // this should by sent by the lidar after each sampleRate_request from the host

static void sendLidarCommand (u8 cmd, const void *payload, u8 payloadsize)
{
    u8 pkt_header[2] = {LIDAR_START_FLAG , LIDAR_CMD_HQ_MOTOR_SPEED_CTRL};
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , pkt_header[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , pkt_header[1]); // send the set motor rpm cmd

    if ((payloadsize != 0) && (payload != NULL))
    {
        u8 checksum = 0;

        checksum ^= LIDAR_START_FLAG;
        checksum ^= cmd;
        checksum ^= payloadsize;

        for (u8 pos = 0; pos < payloadsize; ++pos)
        {
            checksum ^= ((char*)payload)[pos];
        }

        MUSART_uddtTransmitByte(MUART1_PERIPHERAL , payloadsize);
        for (u8 pos = 0; pos < payloadsize; ++pos)
        {
        	MUSART_uddtTransmitByte (MUART1_PERIPHERAL, ((char*)payload)[pos] );
        }
        MUSART_uddtTransmitByte(MUART1_PERIPHERAL , checksum);

    }

}

static lidar_StatusTypeDef lidar_check_scan_descriptor(lidar_HandleTypeDef* lidar)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 cheack_dis_flag = 1;
	/* first check the descriptor message received if it's valid or not */
	for(u8 i = 0 ; i < 7 ; i++)
	{
		if(Scan_Discriptor_Msg[i] != lidar->buff[i])
		{
			cheack_dis_flag = 0; // the descriptor message in invalid
			break;
		}
	}
	if(cheack_dis_flag == 1)
	{
		/* Store the descriptor message from the buffer  */
		for(u8 i = 0 ; i < 7 ; i++)
		{
			lidar->descriptor[i] = lidar->buff[i];
		}
		Status =  LIDAR_OK;
	}
	else
	{
		Status = LIDAR_NO_GOOD_ANS;
	}
	return Status;
}
static lidar_StatusTypeDef lidar_check_node_HQ(lidar_HandleTypeDef* lidar)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	f32 dist =  (f32) ( ( (lidar->buff[3]) | (lidar->buff[4] << 8)) / 4.0 ) ; //Actual Distance in mm
	//u8 Quality = (lidar->buff[0] >> 2 );
	//( (lidar->buff[0] ^ (lidar->buff[0] >> 1 )) & 0x01 ) == 1) //check s and s inverted and c


	if( ((lidar->buff[1] & 0x01) == 1) && (dist != 0.0) && (lidar->buff[0] == 0x3E))
	{
		Status = LIDAR_OK;
	}
	else
	{
		Status = LIDAR_NO_GOOD_NODE;
	}
	return Status;

}


static lidar_StatusTypeDef lidar_check_node(lidar_HandleTypeDef* lidar)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	if( ((lidar->buff[1] & 0x01) == 1 ) && ( ( (lidar->buff[0] ^ (lidar->buff[0] >> 1 )) & 0x01 ) == 1 )) //check s and s inverted and c
	{
		Status = LIDAR_OK; // checking on the start and inverted start bits of the first byte and also the check bit of the second byte is done write
	}
	else
	{
		Status = LIDAR_NO_GOOD_NODE;
	}
	return Status;

}

static lidar_StatusTypeDef lidar_read_node(lidar_HandleTypeDef* lidar)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 Resp = MUSART_OK; //to check the reception of the data through uart rx
	 /*  Receive the node data of Scan Request from RPLIDAR	*/
	memset(lidar->buff , 0 , sizeof(lidar->buff));
	for(u8 i = 0 ; i < 5 ; i++ )
	{
		u8 Resp = MUSART_uddtReceiveByteSynchNonBlocking(MUART1_PERIPHERAL , &lidar->buff[i] );
		if(Resp == MUSART_NOK)
		{
			break; // must receive all bytes write
		}
	}
	if(Resp == MUSART_OK)
	{
		Status = lidar_check_node_HQ(lidar);
	}
	else
	{
		Status = LIDAR_TIMEOUT;
	}
	return Status;
}



static lidar_StatusTypeDef lidar_read_health(lidar_HandleTypeDef* lidar, lidar_health_response_t* health)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 cheack_dis_flag = 1;
	/* first check the descriptor message received if it's valid or not */
	for(u8 i = 0 ; i < 7 ; i++)
	{
		if(Health_Discriptor_Msg[i] != lidar->buff[i])
		{
			cheack_dis_flag = 0; // the descriptor message in invalid
			break;
		}
	}
	if(cheack_dis_flag == 1)
	{
		/* Store the descriptor message from the buffer  */
		for(u8 i = 0 ; i < 7 ; i++)
		{
			health->descriptor[i] = lidar->buff[i];
		}
		health->Status = lidar->buff[7];
		health->Error_Code = lidar->buff[8] | (lidar->buff[9] << 8);
		Status =  LIDAR_OK;
	}
	else
	{
		Status = LIDAR_NO_GOOD_ANS;
	}
	return Status;

}

static lidar_StatusTypeDef lidar_read_info(lidar_HandleTypeDef* lidar, lidar_info_response_t* info)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 cheack_dis_flag = 1;
	/* first check the descriptor message received if it's valid or not */
	for(u8 i = 0 ; i < 7 ; i++)
	{
		if(Health_Discriptor_Msg[i] != lidar->buff[i])
		{
			cheack_dis_flag = 0; // the descriptor message in invalid
			break;
		}
	}
	if(cheack_dis_flag == 1)
	{
		/* Store the descriptor message from the buffer  */
		for(u8 i = 0 ; i < 7 ; i++)
		{
			info->descriptor[i] = lidar->buff[i];
		}
		info->Model = lidar->buff[7];
		info->Firmware_Minor = lidar->buff[8];
		info->Firmware_Major = lidar->buff[9];
		info->Hardware = lidar->buff[10];
		for(u8 i=0;i<16;i++){
			info->Serial_Number[i] = lidar->buff[11+i];
		}
		Status =  LIDAR_OK;
	}
	else
	{
		Status = LIDAR_NO_GOOD_ANS;
	}
	return Status;
}

static lidar_StatusTypeDef lidar_read_samplerate(lidar_HandleTypeDef* lidar, lidar_samplerate_response_t* samplerate)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 cheack_dis_flag = 1;
	/* first check the descriptor message received if it's valid or not */
	for(u8 i = 0 ; i < 7 ; i++)
	{
		if(SampleRate_Discriptor_Msg[i] != lidar->buff[i])
		{
			cheack_dis_flag = 0; // the descriptor message in invalid
			break;
		}
	}
	if(cheack_dis_flag == 1)
	{
		/* Store the descriptor message from the buffer  */
		for(u8 i = 0 ; i < 7 ; i++)
		{
			samplerate->descriptor[i] = lidar->buff[i];
		}
		samplerate->Time_Standart = lidar->buff[7] | (lidar->buff[8] << 8);
		samplerate->Time_Express = lidar->buff[9]  | (lidar->buff[10] << 8);

		Status =  LIDAR_OK;
	}
	else
	{
		Status = LIDAR_NO_GOOD_ANS;
	}
	return Status;
}


void lidar_stop()
{
	u8 RpLidar_Stop_Msg[2] = {LIDAR_START_FLAG , LIDAR_STOP};
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Stop_Msg[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Stop_Msg[1]); // send the stop cmd
	MSTK_voidSetBusyWait(4000); // delay for 4 ms (assuming hsi 16 mhz and  ahb_prescalar = 2 and systick clk = ahb_clk /8)
}

void lidar_reset()
{
	u8 RpLidar_Reset_Msg[2] = {LIDAR_START_FLAG , LIDAR_RESET};
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Reset_Msg[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Reset_Msg[1]); // send the reset cmd
	MSTK_voidSetBusyWait(4000); // delay for 4 ms (assuming hsi 16 mhz and  ahb_prescalar = 2 and systick clk = ahb_clk /8)
}

lidar_StatusTypeDef lidar_start_scan(lidar_HandleTypeDef* lidar)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 Resp = MUSART_OK; //to check the reception of the data through uart rx
	u8 RpLidar_Scan_Msg[2] = {LIDAR_START_FLAG , LIDAR_SCAN};
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Scan_Msg[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Scan_Msg[1]); // send the scan cmd
	 /*  Receive the Descriptor of Scan Request from RPLIDAR	*/
	memset(lidar->buff , 0 , sizeof(lidar->buff));
	for(u8 i = 0 ; i < 7 ; i++ )
	{
		Resp = MUSART_uddtReceiveByteSynchNonBlocking(MUART1_PERIPHERAL , &lidar->buff[i] );
		if(Resp == MUSART_NOK)
		{
			break; // must receive all bytes write
		}
	}
	if(Resp == MUSART_OK)
	{
		Status = lidar_check_scan_descriptor(lidar); // go and check the descriptor received
	}
	else
	{
		Status = LIDAR_TIMEOUT;
	}
	return Status;
}


lidar_StatusTypeDef lidar_get_point(lidar_HandleTypeDef* lidar)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 Wrong_Nodes = 0;
	do
	{
		Status = lidar_read_node(lidar);
		Wrong_Nodes++;
	}
	while((Status == LIDAR_NO_GOOD_NODE) && (Wrong_Nodes < LIDAR_MAX_WRONG_NODES));
	/* if the node is ok read the data */
	if(Status == LIDAR_OK)
	{
		lidar->angle =(f32)(((lidar->buff[1] >> 1) | (lidar->buff[2] << 7) ) / 60.0F); // Actual Angle in deg
		lidar->distance = (f32)((  (lidar->buff[3]) | (lidar->buff[4] << 8) ) / 4.0F) ; //Actual Distance in mm
		lidar->start_scan_flag = lidar->buff[0] & 0x01;
		lidar->quality = (lidar->buff[0] >> 2); // 6 bits for quality excluding the s and inverted s bits
	}
	return Status;
}

lidar_StatusTypeDef lidar_get_health(lidar_HandleTypeDef* lidar, lidar_health_response_t* health)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 Resp = MUSART_OK; //to check the reception of the data through uart rx
	u8 RpLidar_Health_Msg[] = { LIDAR_START_FLAG , LIDAR_GET_HEALTH };
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Health_Msg[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Health_Msg[1]); // send the health cmd
	memset(lidar->buff , 0 , sizeof(lidar->buff));

	for(u8 i = 0 ; i < 10 ; i++)
	{
		Resp = MUSART_uddtReceiveByteSynchNonBlocking(MUART1_PERIPHERAL , &lidar->buff[i] );
		if(Resp == MUSART_NOK)
		{
			break; // must receive all bytes write
		}
	}
	if(Resp == MUSART_OK)
	{
		Status = lidar_read_health(lidar , health); // go and check the descriptor received
	}
	else
	{
		Status = LIDAR_TIMEOUT;
	}
	return Status;

}




lidar_StatusTypeDef lidar_get_info(lidar_HandleTypeDef* lidar, lidar_info_response_t* info)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 Resp = MUSART_OK; //to check the reception of the data through uart rx
	u8 RpLidar_Info_Msg[] = { LIDAR_START_FLAG , LIDAR_GET_INFO };
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Info_Msg[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_Info_Msg[1]); // send the Info cmd
	memset(lidar->buff , 0 , sizeof(lidar->buff));

	for(u8 i = 0 ; i < 27 ; i++)
	{
		Resp = MUSART_uddtReceiveByteSynchNonBlocking(MUART1_PERIPHERAL , &lidar->buff[i] );
		if(Resp == MUSART_NOK)
		{
			break; // must receive all bytes write
		}
	}
	if(Resp == MUSART_OK)
	{
		Status = lidar_read_info(lidar , info); // go and check the descriptor received
	}
	else
	{
		Status = LIDAR_TIMEOUT;
	}
	return Status;
}

lidar_StatusTypeDef lidar_get_samplerate(lidar_HandleTypeDef* lidar, lidar_samplerate_response_t* samplerate)
{
	lidar_StatusTypeDef Status = LIDAR_OK;
	u8 Resp = MUSART_OK; //to check the reception of the data through uart rx
	u8 RpLidar_SampleRate_Msg[] = { LIDAR_START_FLAG , LIDAR_GET_SAMPLERATE};
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_SampleRate_Msg[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , RpLidar_SampleRate_Msg[1]); // send the Info cmd
	memset(lidar->buff , 0 , sizeof(lidar->buff));

	for(u8 i = 0 ; i < 11 ; i++)
	{
		Resp = MUSART_uddtReceiveByteSynchNonBlocking(MUART1_PERIPHERAL , &lidar->buff[i] );
		if(Resp == MUSART_NOK)
		{
			break; // must receive all bytes write
		}
	}
	if(Resp == MUSART_OK)
	{
		Status = lidar_read_samplerate(lidar , samplerate); // go and check the descriptor received
	}
	else
	{
		Status = LIDAR_TIMEOUT;
	}
	return Status;
}

void setMotorRpm (u16 rpm)
{
    rplidar_payload_motor_rpm_t motor_rpm;
    if (rpm > MAX_MOTOR_RPM)
    {
        rpm = MAX_MOTOR_RPM;
    }
    motor_rpm.rpm_value = rpm;

    sendLidarCommand (LIDAR_CMD_HQ_MOTOR_SPEED_CTRL, &motor_rpm, sizeof(motor_rpm));
   /* u8 checksum = 0;

    checksum ^= LIDAR_START_FLAG;
    checksum ^= LIDAR_CMD_HQ_MOTOR_SPEED_CTRL;
    checksum ^= 2;
    checksum ^= (u8)(rpm & 0xFF);
    checksum ^= (u8)((rpm >> 8) & 0xFF);
    u8 pkt_header[2] = {LIDAR_START_FLAG , LIDAR_CMD_HQ_MOTOR_SPEED_CTRL};
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , pkt_header[0]); //send the start flag (0xA5)
	MUSART_uddtTransmitByte(MUART1_PERIPHERAL , pkt_header[1]); // send the set motor rpm cmd
    MUSART_uddtTransmitByte(MUART1_PERIPHERAL , (u8)0x02);
    MUSART_uddtTransmitByte(MUART1_PERIPHERAL , (u8)(rpm & 0xFF));
    MUSART_uddtTransmitByte(MUART1_PERIPHERAL , (u8)((rpm >> 8) & 0xFF));
    MUSART_uddtTransmitByte(MUART1_PERIPHERAL , checksum);
    */

}

void lidar_serial_send(u8 *Byte,u16 Size)
{
	u16 i;
	for(i=0; i < Size; i++)
	{
		MUSART_uddtTransmitByte(MUART1_PERIPHERAL , Byte[i]);
	}
}
void startMotor(u8 pwm)
{
	HLIDAR_controlSpeed (pwm);
}

void stopMotor()
{
	HLIDAR_controlSpeed (0);
}

