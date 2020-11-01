/*
 * Garage System.c
 *
 * Created: 10/30/2020 5:07:28 PM
 * Author : Saeed
 */ 

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "DIO.h"
#include "LCD.h"
#include "STD_types.h"
#include "BitMath.h"


// Function prototyping  //
void Green_LED (boolean status); // Turn on/off the green led
void RED_LED (boolean status); //// Turn on/off the red led


// Global Variables //
uint8 car_num =0;
uint8 max_car_num =5;
uint8 min_car_num =0;
uint8 temp=0;

int main(void)
{
	// Initializations //
	LCD_init();
	LCD_clearScreen();
	
	// Interrupt enable //
	sei(); //Enable Global int
	SET_BIT(GICR,INT0); //Enable External INT0
	SET_BIT(GICR,INT1); //Enable External INT1
	
	// Setting Interrupt moods //
	CLR_BIT(MCUCR, ISC00);	 // Interrupt 0
	SET_BIT(MCUCR,ISC01);
	
	CLR_BIT(MCUCR, ISC10); // Interrupt 1
	SET_BIT(MCUCR,ISC11);
	
	// O/P Pins //
	Dio_WritePinDir('C',3,OUT); //Red LED output pin.
	CLR_BIT(PORTC,3); // Clearing the bit
	Dio_WritePinDir('C',4,OUT); //Green LED output pin.
	CLR_BIT(PORTC,4); // Clearing the bit
	
	// I/P Pins //
	Dio_WritePinDir('D',2,IN);
	Dio_WritePinDir('D',3,IN);
	
	
	
	 LCD_clearScreen();
	 
	

   
    while (1) 
    {
		LCD_GotoXY(0,0);
		LCD_SendString(" Garage System");
		LCD_GotoXY(1,0);
		LCD_SendString("Space: ");
		temp = max_car_num-car_num;
		LCD_SendNumber(temp);
		_delay_ms(200);
				
    }
}

void Green_LED (boolean status)  // Indicates availability for parking.
{
	if (status == ENABLE)
	{
		SET_BIT(PORTC,4);
	}
	else
	{
		CLR_BIT(PORTC,4);
	}
}
void RED_LED (boolean status) // Garage is full/
{
	if (status == ENABLE)
	{
		SET_BIT(PORTC,3);
	}
	else
	{
		CLR_BIT(PORTC,3);
	}
}

ISR(INT0_vect)  // Adds car to the garage. 
{
	
	car_num++;
	
		if(car_num == max_car_num)
		{
			RED_LED(ENABLE);
			Green_LED(0);		
		}
		else if (car_num < max_car_num) 
		{
			Green_LED(ENABLE);
			RED_LED(0);
		}
		else 
		{
			car_num--;
		}
	
}


ISR(INT1_vect) // Removes car from the garage. 
{
	
	if (car_num == min_car_num)
	{
		
		Green_LED(ENABLE);
		RED_LED(0);
	}
	else
	{
		car_num--;
		Green_LED(ENABLE);
		RED_LED(0);
	}
	
}