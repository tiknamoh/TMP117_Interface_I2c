/**********************************************************************************************
 File			: I2C.h
 MCU	  		: LPC2148  ARM7
 Description: Functions related to the I2C			  
***********************************************************************************************/
#include<lpc214x.h>
#include"I2C.h"
#include"TYPE.h"
/*********************** I2c Intialization **************************/
void I2C_INIT(void)
{
	PIN_CONF_0 = PIN_CONF_0 | I2C0_PINEN;
	I2C0_CONF_SET_R = I2CEN;
	I2C0_DC_L =  FPCLK /(2*I2CBFREQ);
	I2C0_DC_H  = FPCLK /(2*I2CBFREQ);
}
  /*********************** I2c Start Function  **************************/
void I2C_START(void)
{
	I2C0_CONF_SET_R  = I2C_START_C;
	while ( (I2C0_CONF_SET_R & I2C_INT_FG) == 0 );
	I2C0_CONF_CLR_R =(1<<STA)|(1<<SI);
}
/*********************** I2c Write Function  **************************/
void I2C_WRITE( uint8 data )
{
	I2C0_DATA = data;
	I2C0_CONF_SET_R = I2CEN ;
	while( (I2C0_CONF_SET_R & I2C_INT_FG) == 0 ); 
	I2C0_CONF_CLR_R  = I2C_INT_FG;
}
 /*********************** I2c Read With Acknoledgment Function	********************/
uint8 I2C_READ_ACK( void )
{
	I2C0_CONF_SET_R = I2CEN_ACK ;
	while( (I2C0_CONF_SET_R & I2C_INT_FG) == 0 );
	I2C0_CONF_CLR_R= (1<<AA)|(1<<SI);
	return I2C0_DATA;
}
 /******************** I2c Read Without Acknoledgment Function  *******************/
unsigned char I2C_READ_NACK( void )
{
	I2C0_CONF_SET_R = I2CEN ;
	while( (I2C0_CONF_SET_R & I2C_INT_FG) == 0 );
	I2C0_CONF_CLR_R= I2C_INT_FG;
	return I2C0_DATA; 
}
 /*********************** I2c Stop **************************/
void I2C_STOP( void )
{
	I2C0_CONF_SET_R = I2C_STP; 
}
 /*********************** End **************************/
