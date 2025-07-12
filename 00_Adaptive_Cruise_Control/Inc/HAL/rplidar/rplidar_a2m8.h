/*
 * rplidar_a2m8.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Amr Mohammed Hassan
 */
#ifndef RPLIDAR_A2M8_H
#define RPLIDAR_A2M8_H

#define LIDAR_START_FLAG 0xA5
#define LIDAR_NEXT_FLAG 0x5A

// Macros for descriptor check

#define ANS_SYNC_BYTE1		0xA5
#define ANS_SYNC_BYTE2		0x5A

// Macros for Send Mode
#define LIDAR_SEND_SINGLE_RESPONSE 0x0
#define LIDAR_SEND_MULTIPLE_RESPONSE 0x1

//Macros for command (CMD) operations
#define LIDAR_STOP 0x25
#define LIDAR_RESET 0x40
#define LIDAR_SCAN 0x20
#define LIDAR_EXPRESS_SCAN 0x82
#define LIDAR_FORCE_SCAN 0x21
#define LIDAR_GET_INFO 0x50
#define LIDAR_GET_HEALTH 0x52
#define LIDAR_GET_SAMPLERATE 0x59
#define LIDAR_GET_CONF 0x84
#define LIDAR_CMD_HQ_MOTOR_SPEED_CTRL  0xA8


// Size of Data Received
#define LIDAR_SIZE_GET_SCAN 5 // bytes
#define LIDAR_SIZE_GET_FORCE_SCAN 5
#define LIDAR_SIZE_GET_INFO 20
#define LIDAR_SIZE_GET_HEALTH 3
#define LIDAR_SIZE_GET_SAMPLERATE 4

// Lidar Conf Command
#define LIDAR_CONF_SCAN_MODE_COUNT 0x70
#define LIDAR_CONF_SCAN_MODE_US_PER_SAMPLE 0x71
#define LIDAR_CONF_SCAN_MODE_MAX_DISTANCE 0x74
#define LIDAR_CONF_SCAN_MODE_ANS_TYPE 0x75
#define LIDAR_CONF_SCAN_MODE_TYPICAL 0x7C
#define LIDAR_CONF_SCAN_MODE_NAME 0x7F

// Nodes Reading
#define LIDAR_MAX_WRONG_NODES 20

// macros for GET_HEALTH Response packet
#define RPLIDAR_STATUS_GOOD			0
#define RPLIDAR_STATUS_WARNING		1
#define RPLIDAR_STATUS_ERROR		2

#define QUALITY_THRESHOLD 20

// macros for motor pwm
#define MAX_MOTOR_PWM 39
#define DEFAULT_MOTOR_PWM 60

//macros for motor rpm
#define      MAX_MOTOR_RPM        900
#define      DEFAULT_MOTOR_RPM    600

//macros for Motor_Pwm pin
#define MOTOR_GPIO_PORT PORTA
#define MOTOR_GPIO_PIN PIN9
typedef enum
{
  LIDAR_OK       = 0x00U,
  LIDAR_TIMEOUT    = 0x01U,
  LIDAR_NO_GOOD_ANS     = 0x02U,
  LIDAR_NO_GOOD_NODE  = 0x03U
}lidar_StatusTypeDef;
typedef struct
{
    u8    Quality;
    u16   Angle;
    u16   Distance;
}lidar_response_measurement_node_t;
typedef struct __lidar_rec_Handle
{
	u8 buff[30]; /* to store the lidar responses */
	/* data  */
	u8 descriptor[7];
	u8 start_scan_flag;
	u8 quality;
	u16 angle;
	f32 distance;
}lidar_HandleTypeDef;

typedef struct{
	u8 descriptor[7];
	u8 Status;
	u16 Error_Code;
}lidar_health_response_t;

typedef struct{
	u8 descriptor[7];
	u8 Model;
	u8 Firmware_Minor;
	u8 Firmware_Major;
	u8 Hardware;
	u8 Serial_Number[16];
}lidar_info_response_t;

typedef struct{
	u8 descriptor[7];
	u16 Time_Standart;
	u16 Time_Express;
}lidar_samplerate_response_t;

typedef struct
{
    u16  rpm_value;
} rplidar_payload_motor_rpm_t;

void lidar_stop();
void lidar_reset();
lidar_StatusTypeDef lidar_start_scan(lidar_HandleTypeDef* lidar);
lidar_StatusTypeDef lidar_get_point(lidar_HandleTypeDef* lidar);
lidar_StatusTypeDef lidar_get_health(lidar_HandleTypeDef* lidar, lidar_health_response_t* health);
lidar_StatusTypeDef lidar_get_info(lidar_HandleTypeDef* lidar, lidar_info_response_t* info);
lidar_StatusTypeDef lidar_get_samplerate(lidar_HandleTypeDef* lidar, lidar_samplerate_response_t* samplerate);
void setMotorPWM (u8 pwm);
void setMotorRpm (u16 rpm);
void startMotor(u8 pwm);
void stopMotor();



#endif /* RPLIDAR_A2M8_H */
