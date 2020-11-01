/*
 * LCD.c
 *
 *  Created on: Sep 20, 2019
 *      Author: breks
 */


#include "lcd.h"

void LCD_init()
{
	/******* Configure LCD pin Direction Data & control Ports  *********/
	Dio_WritePinDir(LCD_Port,4,OUT);
	Dio_WritePinDir(LCD_Port,5,OUT);
	Dio_WritePinDir(LCD_Port,6,OUT);
	Dio_WritePinDir(LCD_Port,7,OUT);

	Dio_WritePinDir(LCD_ControlPort,LCD_EN,OUT);
	Dio_WritePinDir(LCD_ControlPort,LCD_RS,OUT);
	Dio_WritePinDir(LCD_ControlPort,LCD_RW,OUT);

	_delay_ms(15);
	LCD_SendCommand(0x33);						// To initialize LCD in 4 bit mode you need to send  3---3---3---2
	LCD_SendCommand(0x32);

	LCD_SendCommand(LCD_FUNCTION_4BIT_2LINES);	// Function set 4 bit 2 lines  5*7 bot
	LCD_SendCommand(LCD_DISP_ON);				// Display ON
	LCD_SendCommand(LCD_CLEAR_SCREEN);			// clear
	LCD_SendCommand(LCD_ENTRY_INC_);			// Entry mode and the display increment to the right
}

void LCD_clearScreen ()
{
	LCD_SendCommand(LCD_CLEAR_SCREEN); // clear the screen
}


void LCD_kick ()
{
	// Enable by falling edge
	Dio_WritePin(LCD_ControlPort,LCD_EN,STD_high);
	_delay_ms(1);
	Dio_WritePin(LCD_ControlPort,LCD_EN,STD_low);
}


void LCD_SendCommand(uint8 command)
{
	Dio_WritePin(LCD_ControlPort,LCD_RS,STD_low);			//Register select=0 to send command
	Dio_WritePin(LCD_ControlPort,LCD_RW,STD_low);			// Write

	Dio_WriteHighNibbleVal(LCD_Port,command);				// Send the higher 4 bit

	LCD_kick();												// Enable to let data enter the LCD

	Dio_WriteHighNibbleVal(LCD_Port,(command<<4));			// Send the Lower 4 bit

	LCD_kick();

	_delay_ms(5);
}

void LCD_SendCharacter(uint8 character)
{
	Dio_WritePin(LCD_ControlPort,LCD_RS,STD_high);		// Register select = 1 to send data
	Dio_WritePin(LCD_ControlPort,LCD_RW,STD_low);		// write

	Dio_WriteHighNibbleVal(LCD_Port,character);			// higher 4 bit

	LCD_kick();

	Dio_WriteHighNibbleVal(LCD_Port,(character<<4));	// then lower 4 bit

	LCD_kick();

	_delay_us(200);
}

void LCD_SendString(uint8 *StringOfCharacters)
{
	uint8 i = 0;
	while(StringOfCharacters[i] != '\0')				// Any string is an array by default ended by char '\0'
	{
		LCD_SendCharacter(StringOfCharacters[i]);		// send char by char
		i++;
	}
}


void LCD_SendNumber (uint16 Number )
{
	// Want to display number like sending LCD_displayNumbe(999);

	char buff[16]; 							/* String to hold the ascii result */
	itoa(Number,buff,10); 					/* 10 for decimal function change int to array of asci character */
	LCD_SendString(buff);
}

void LCD_SendRealNumber (float32  Number )
{
	// want to display number like 1.999 ;

	uint8 str[16];										// to store the stirng

	uint8 *sign = (Number < 0 )? "-" : "" ;				// if number negative add negative sign
	float32 val = (Number < 0 )? -Number : Number ;		// change the number to be positive to
																/* cinsider we have y.xxx*/
	uint16 int1 = val ;									// keep the integer number and remove decimal int1=y
	float32 frac = val - int1 ;							// let the decimal value be 0.xxx frac=0.xxx
	uint16 int2 = frac*1000;							// by 1000 to change it to integer int2=xxx

	sprintf (str ,"%s%d.%03d",sign,int1,int2);			// then add the sing then int1 the . then int2 at 03

	LCD_SendString(str);

}

void LCD_GotoXY(uint8 x,uint8 y)
{
	if (x==0)
		LCD_SendCommand(LCD_BEGIN_AT_FIRST_RAW+y);
	else
		LCD_SendCommand(LCD_BEGIN_AT_SECOND_RAW+y);
}

void LCD_CreatChar(uint8 charnum,uint8 a_NewShape[] )
{
	int i;
	LCD_SendCommand(0x40+charnum*8);
	for(i=0;i<8;i++)
	{
		LCD_SendCharacter(a_NewShape[i]);
	}
	LCD_GotoXY(1,1);
}
