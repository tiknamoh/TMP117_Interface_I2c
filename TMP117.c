#include<lpc214x.h>
#include"TMP117.h"
#include"I2C.h"
#include"TYPE.h"

/*********************** TMP117  Addresses **************************/
 const int TMP117_Address =		0x48;		// Device Address   
 const int Temp_Reg =			0x00;		// Temperature register
 const int Config_Reg =			0x01;		// Configuration register
 const int High_Lim_Reg =		0x02;		// High limit register
 const int EEPROM_Unlock_Reg =	0x04;		// EEPROM unlock register
 const int Device_ID_Reg =		0x0F;		// Device ID register
/*********************** Initialization *****************************/
void TMP117_init(void)
{
  I2C_INIT();
}
/********************* Read Temperature Sensor Function**************/
float64 TMP117_read()
{
  uint16 data[2]; 
  uint8 cdat;
  I2C_START();
  I2C_WRITE(TMP117_Address);
  I2C_WRITE(Temp_Reg);
  I2C_START();
  I2C_WRITE(TMP117_Address &0xff);
  data[0]=I2C_READ_ACK();
  data[1]=I2C_READ_ACK();
  I2C_STOP();
  cdat = ((data[0] << 8) | data[1]);
  return cdat*TMP117_RESOLUTION ; 
}
/************************************** End*************************/
