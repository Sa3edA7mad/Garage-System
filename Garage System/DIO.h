#ifndef _DIO_H
#define _DIO_H

#include "STD_Types.h"	
#include "BitMath.h"
#include "DIO_hw.h"


 typedef enum{
	 IN = 0,
	 OUT = 1
 }DIO_Direction;
 
/*=========================================
 * FUNCTIONS PROTOTYPES
 =========================================*/

/*  FOR writing and reading single Pin*/
void Dio_WritePinDir(uint8 PORT, uint8 PIN_no,DIO_Direction dir);
STD_levelType Dio_ReadPin(uint8 PORT, uint8 PIN_no );
void Dio_WritePin(uint8 PORT, uint8 PIN_no,STD_levelType Level);

//STD_levelType Dio_ReadPinDir(unit8 PORT, uint8 PIN_no);  		If you need to read the actual direction on the pin 

/* For writing and reading the whole port */
void Dio_WritePortDir(uint8 PORT,DIO_Direction dir);
uint8 Dio_ReadPort(uint8 PORT );
void Dio_WritePortVal(uint8 PORT, uint8 data);
void Dio_WritePortLevel(uint8 PORT, STD_levelType Level);
//STD_levelType Dio_ReadPortDir(unit8 PORT);					If you need to read the actual direction on the Port 


void Dio_WriteHighNibbleVal(uint8 port, uint8 val);
void Dio_WriteLowNibbleVal(uint8 port, uint8 val);

void Dio_WriteHighNibbleDir(uint8 PORT, DIO_Direction dir) ;
void Dio_WriteLowNibbleDir(uint8 PORT, DIO_Direction dir);
// Here you can add the same functions for higher and lower nibble 
// Also you free to add Flip Pin and Flip port 

#endif
