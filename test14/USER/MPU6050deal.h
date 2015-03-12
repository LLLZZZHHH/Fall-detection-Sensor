#ifndef __MPU6050deal_H
#define __MPU6050deal_H

#ifdef __cplusplus
 extern "C" {
#endif
//AFS_SEL Full Scale Range LSB Sensitivity
//0 ��2g 16384 LSB/mg
//1	��4g 8192 LSB/mg
//2	��8g 4096 LSB/mg
//3 ��16g 2048 LSB/mg
#define Acc2gLSB 16348
#define Acc4gLSB 8192
#define Acc8gLSB 4096
#define ACC16gLSB 2048
#define AccGravity 9.8
//FS_SEL Full Scale Range LSB Sensitivity
//0   �� 250 ��/s	 131 LSB/��/s
//1	  �� 500 ��/s			 65.5 LSB/��/s
//2   �� 1000 ��/s		 32.8 LSB/��/s
//3   �� 2000 ��/s		 16.4 LSB/��/s
#define Gyro250LSB 131
#define Gyro500LSB 65.5
#define Gyro1000LSB 32.8
#define Gyro2000LSB	16.4

// This Library is base on mpu6050.h and to fullfill my need to make this 
//initial get data function
uint16_t GetData(uint8_t regAddr1, uint8_t regAddr2);

// MPU6050 Get Raw data inlcude Accelerator and Gryoscope and Temperature
void MPU6050_GetRawAccelTemperGyro(s16* AccelGyro);
// get the dealed data 
// @param processed is a 7 arary typed of int16_t Acc X Y Z and then Temp Gyro X Y Z
void MPU6050_DealDataAccTempGryo(float * processed);

// SMPLRT_DIV register
uint8_t getRate(void);
void setRate(uint8_t rate);


// I2C_MST_CTRL register
uint8_t getMasterClockSpeed(void);
void setMasterClockSpeed(uint8_t speed);
#endif
