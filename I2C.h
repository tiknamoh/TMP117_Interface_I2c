/**********************************************************************************************
 File			: I2C.h																			
 MCU			: LPC2148  ARM7																	
 Description	: Functions related to the I2C			  										
***********************************************************************************************/

#ifndef I2C_H
#define I2C_H
/* ********I2C functions *********/
  void I2C_INIT(void);
  void I2C_START(void);
  void I2C_WRITE(unsigned char data);
  unsigned char I2C_READ_ACK( void );
  unsigned char I2C_READ_NACK( void );
  void I2C_STOP( void );

/* ********I2C freq Calculation *********/
#define	FPCLK					3000000				//Clock 30 Mhz
#define	I2CBFREQ				30000				//I2C data rate 300Khz and 50% duty cycle 

/********* I2C Registers**********/
#define I2C0_CONF_SET_R			I2C0CONSET			//I2C Set Configuration Reg
#define I2C0_CONF_CLR_R			I2C0CONCLR			//I2C clr Configuration Reg  
#define I2C0_STAT_R				I2C0STAT			//I2C Stauts  Reg  
#define I2C0_DATA				I2C0DAT				//I2C Data  Reg   
#define I2C0_SLADDR				I2C0ADR				//I2C Slave Address Reg   
#define I2C0_DC_H				I2C0SCLH			//I2C Duty Cycle Higher Byte  
#define I2C0_DC_L				I2C0SCLL			//I2C Duty Cycle Lower Byte  

/********* I2C Config Reg Pins *********/
#define STA						5					//Start Flag
#define STO						4					//Stop flag
#define AA						2					//Assert Acknowlegment Flag
#define SI						3					//Interupt Flag
#define I2cEN					6					// I2C Enable flag

/* ********Pin Connect Block *********/
#define PIN_CONF_0				PINSEL0        
#define PIN_CONF_1				PINSEL1
#define PIN_CONF_2				PINSEL2       

#define I2C0_PINEN				0x00000050			//i2c Pins Mode Slection
#define I2CEN					0X40				//Enable I2C		(1<<I2cEN)
#define I2CEN_ACK				0X44				//(1<<)
#define I2C_START_C				0x20				// I2c Start  (1<<STA)
#define I2C_INT_FG				0x08				//SI  flag
#define I2C_STP					0x50				//I2C Stop   (1<<STO)


#endif
  /* ********end *********/ 
