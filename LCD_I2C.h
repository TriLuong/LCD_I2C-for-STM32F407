#ifndef __PCF8574AT_
#define __PCF8574AT_

#include "stm32f4xx_hal.h"

#define addr 0x7E 

#define EN_SET() Write_I2C(PortData|=0x04)
#define EN_RESET() Write_I2C(PortData&=~0x04)

#define RS_SET() Write_I2C(PortData|=0x01)
#define RS_RESET() Write_I2C(PortData&=~0x01)

#define RW_SET() Write_I2C(PortData|=0x02)
#define RW_RESET() Write_I2C(PortData&=~0x02)

#define LED_SET() Write_I2C(PortData|=0x08)
#define LED_RESET() Write_I2C(PortData&=~0x08)

//Address 0x38 , 0x7E(Write Mode)
//PCF	LCD	
//P0 	RS	 	
//P1 	RW  
//P2 	E		
//P3			
//P4 	D4  
//P5 	D5 	
//P6 	D6	
//P7	D7	

void LCD_init();
void LCD_gotoxy(unsigned char  x, unsigned char y);
void LCD_putc(char c);
void LCD_puts(char *str);
void LCD_clear();

#endif