# LCD_I2C-for-STM32f407

Device: LCD 2004, Module PCF8574AT and STM32F407
Address of PCF8574AT: 0x7E (Fig. 10 in Datashhet of PCF8574AT)

Module PCF8574AT and LCD:
- P0 connect to	RS		
- P1 connect to	RW  
- P2 connect to	E		
- P3 connect to	LED		
- P4 connect to	D4  
- P5 connect to	D5 	
- P6 connect to	D6	
- P7 connect to	D7

STM32F407 and Module PCF8574AT:
- PB6(SCL_I2C of MCU) connect to SCL
- PB7(SDA_I2C of MCU) connect to SDA

Note: Use 2 PIN I2C (SDA,SCL) of STM32f407 to connect with Module PCF8574AT.

Reference: 
- Datasheet of PCF8574AT and TC2004A-01. 
- http://www.hocavr.com/index.php/app/textlcd 
- Support from my friend https://github.com/thaitanloi365
