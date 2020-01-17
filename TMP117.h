/**********************************************************************************************
 File           : TMP117.h
 MCU      	    : LPC2148  ARM7
 Description    : Functions and Register Related to TMP117.h 
 Datasheet      ://http://www.ti.com/lit/ds/symlink/tmp117.pdf		  
***********************************************************************************************/
#ifndef TMP117_H
#define TMP117_H

#define TMP117_RESOLUTION 0.0078125f

/*********************** TMP117 Registers **************************/
// #define TMP117_Address =	0x48;		// Device Address   
// #define Temp_Reg =			0x00;		// Temperature register
//#define Config_Reg =		0x01;		// Configuration register
//#define High_Lim_Reg =		0x02;		// High limit register
//#define EEPROM_Unlock_Reg =	0x04;		// EEPROM unlock register
//#define Device_ID_Reg =		0x0F;		// Device ID register

/*********************** Function Declrations **************************/
void TMP117_init(void);
double TMP117_read(void);


#endif








