#include "LCD_I2C.h"

//PCF	LCD	
//P0 	RS		
//P1 	RW  
//P2 	E		
//P3	LED		
//P4 	D4  
//P5 	D5 	
//P6 	D6	
//P7	D7

extern I2C_HandleTypeDef hi2c1;
uint8_t buf[1]={0};
uint8_t PortData=0;


__STATIC_INLINE void DelayuUs(__IO uint32_t micros)
{
	micros *=(SystemCoreClock / 1000000) / 5;
	while (micros--);
}


void Write_I2C(unsigned char data)
{
	*buf=data;
	HAL_I2C_Master_Transmit(&hi2c1,(uint16_t )addr,buf,1,1000);
}

void Write_4bit(unsigned char data)
{
	//PortData=0;
	EN_SET();	
	DelayuUs(50);
	data<<=4;
	Write_I2C(PortData|data);
	EN_RESET();
	
	DelayuUs(50);
}

void Write_Byte(unsigned char data,int status)
{
	if(status==1) RS_SET();
	else RS_RESET();
	uint8_t DH=0; //Data High
	DH=data>>4;
	Write_4bit(DH);
	Write_4bit(data);
}

void LCD_init()
{
	HAL_Delay(15);
	Write_4bit(0x03);	
	HAL_Delay(4);
	Write_4bit(0x03);
	DelayuUs(100);
	
	Write_4bit(0x03);
	HAL_Delay(1);
	
	Write_4bit(0x02);
	HAL_Delay(1);
	
	//Clear LCD
	Write_Byte(0x01,0);
	HAL_Delay(2);
	
	//Function Set: DL=0-4bit, N=1-2 line, F=5x10-5x8 dots
	Write_Byte(0x28,0); //4bit, 2 line, 5x8 dots
	DelayuUs(40);
	
	
	
	//Display ON/OFF cursor: D: display, C: cursor, B: blink cursor
	Write_Byte(0x0C,0); // not Cursor
	DelayuUs(40);
	
	//Entry Mode Set
	Write_Byte(0x06,0); //Insert new character in the right of old character. 
	DelayuUs(40);	
	
	LED_SET();
}

//Set DDRAM address

void LCD_gotoxy(unsigned char  x,unsigned char y)
{
	if(y>=20) y=19;
	
	if (x==0) Write_Byte(0x80 + y,0);
	else if(x==1) Write_Byte(0xC0+y,0);
	else if(x==2) Write_Byte(0x80+0x14+y,0);
	else  Write_Byte(0xC0+0x14+y,0);
}

void LCD_putc(char c)
{
	Write_Byte(c,1);
}

void LCD_puts(char *str)
{
	int i=0;
	while(str[i])
	{
		LCD_putc(str[i]);
		i++;
	}
	
}

void LCD_clear()
{
	//Clear LCD
	Write_Byte(0x01,0);
	HAL_Delay(2);
	
	//Function Set: DL=0-4bit, N=1-2 line, F=5x10-5x8 dots
	Write_Byte(0x28,0); 
	DelayuUs(40);
	
	//Entry Mode Set
	Write_Byte(0x06,0);
	DelayuUs(40);
}




