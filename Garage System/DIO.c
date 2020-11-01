
#include "DIO.h"
void Dio_WritePinDir(uint8 PORT, uint8 PIN_no,DIO_Direction dir)
{
	switch(PORT)
	{
	case 'A':
	case 'a':
		if(dir == OUT)
		{
			SET_BIT(DDR_A,PIN_no);
		}
		else
		{
			CLR_BIT(DDR_A,PIN_no);
		}
		break;

	case 'B':
	case 'b':
		if(dir == OUT)
		{
			SET_BIT(DDR_B,PIN_no);
		}
		else
		{
			CLR_BIT(DDR_B,PIN_no);
		}
		break;

	case 'C':
	case 'c':
		if(dir == OUT)
		{
			SET_BIT(DDR_C,PIN_no);
		}
		else
		{
			CLR_BIT(DDR_C,PIN_no);
		}
		break;
		
	case 'D':
	case 'd':
		if(dir == OUT)
		{
			SET_BIT(DDR_D,PIN_no);
		}
		else
		{
			CLR_BIT(DDR_D,PIN_no);
		}
		break;
		
	default:
		/*error*/
		break;
	
	}
	
}

STD_levelType Dio_ReadPin(uint8 PORT, uint8 PIN_no )
{
	STD_levelType ret_level=-1;
	switch(PORT)
	{
	case 'A':
	case 'a':
		ret_level=GET_BIT(PIN_A,PIN_no);
		break;

	case 'B':
	case 'b':
		ret_level=GET_BIT(PIN_B,PIN_no);
		break;

	case 'C':
	case 'c':
		ret_level=GET_BIT(PIN_C,PIN_no);
		break;

	case 'D':
	case 'd':
		ret_level=GET_BIT(PIN_D,PIN_no);
		break;

	}
	return ret_level;
}

void Dio_WritePin(uint8 PORT, uint8 PIN_no,STD_levelType Level)
{
	switch(PORT)
	{
	case 'A':
	case 'a':
		if(Level==STD_high)
		{
			SET_BIT(PORT_A,PIN_no);
		}
		else
		{
			CLR_BIT(PORT_A,PIN_no);
		}
		break;
	case 'B':
	case 'b':
		if(Level==STD_high)
		{
			SET_BIT(PORT_B,PIN_no);
		}
		else
		{
			CLR_BIT(PORT_B,PIN_no);
		}
		break;
	case 'C':
	case 'c':
		if(Level==STD_high)
		{
			SET_BIT(PORT_C,PIN_no);
		}
		else
		{
			CLR_BIT(PORT_C,PIN_no);
		}
		break;
	case 'D':
	case 'd':
		if(Level==STD_high)
		{
			SET_BIT(PORT_D,PIN_no);
		}
		else
		{
			CLR_BIT(PORT_D,PIN_no);
		}
		break;
	}

}

void Dio_WritePortDir(uint8 PORT,DIO_Direction dir)
{
	switch(PORT)
	{
	case 'A':
	case 'a':
		if(dir == OUT)
		{
			DDR_A = 0xFF;
		}
		else
		{
			DDR_A = 0x00;
		}
	break;
	case 'B':
	case 'b':
		if(dir == OUT)
		{
			DDR_B = 0xFF;
		}
		else
		{
			DDR_B = 0x00;
		}
	break;

	case 'C':
	case 'c':
		if(dir == OUT)
		{
			DDR_C = 0xFF;
		}
		else
		{
			DDR_C = 0x00;
		}
	break;

	case 'D':
	case 'd':
		if(dir == OUT)
		{
			DDR_D = 0xFF;
		}
		else
		{
			DDR_D = 0x00;
		}
	break;
	}
}

uint8 Dio_ReadPort(uint8 PORT )
{
	uint8 ret;
	switch(PORT)
	{
	case 'A':
	case 'a':
		ret = PIN_A;
		break;

	case 'B':
	case 'b':
		ret = PIN_B;
		break;

	case 'C':
	case 'c':
		ret = PIN_C;
		break;
		
	case 'D':
	case 'd':
		ret = PIN_D;
		break;
		
	default:
		/*error*/
		break;
	}

	return ret;
}


void Dio_WritePortLevel(uint8 PORT, STD_levelType Level)
{
	switch(PORT)
	{
	case 'A':
	case 'a':
		if(Level == STD_high)
		{
			PORT_A = 0xFF;
		}
		else
		{
			PORT_A = 0x00;
		}
	break;
	case 'B':
	case 'b':
		if(Level == STD_high)
		{
			PORT_B = 0xFF;
		}
		else
		{
			PORT_B = 0x00;
		}
	break;

	case 'C':
	case 'c':
		if(Level == STD_high)
		{
			PORT_C = 0xFF;
		}
		else
		{
			PORT_C = 0x00;
		}
	break;

	case 'D':
	case 'd':
		if(Level == STD_high)
		{
			PORT_D = 0xFF;
		}
		else
		{
			PORT_D = 0x00;
		}
	break;
	}
}

void Dio_WritePortVal(uint8 PORT, uint8 data)
{
	switch(PORT)
		{
		case 'A':
		case 'a':
			PORT_A= data ;
		break;

		case 'B':
		case 'b':
			PORT_B = data ;
		break;

		case 'C':
		case 'c':
			PORT_C = data;
		break;

		case 'D':
		case 'd':
			PORT_D = data;
		break;
		}
}

void Dio_WriteHighNibbleVal(uint8 port, uint8 val)
{
	switch(port)
	{
	case 'A':
	case 'a':
		PORT_A = (PORT_A & 0x0F)|(val & 0xF0);
	break;

	case 'B':
	case 'b':
		PORT_B = (PORT_B & 0x0F)|(val & 0xF0);
	break;

	case 'C':
	case 'c':
		PORT_C = (PORT_C & 0x0F)|(val & 0xF0);
	break;

	case 'D':
	case 'd':
		PORT_D = (PORT_D & 0x0F)|(val & 0xF0);
	break;
	}
}

void Dio_WriteLowNibbleVal(uint8 port, uint8 val)
{
	switch(port)
	{
	case 'A':
	case 'a':
		PORT_A = (PORT_A & 0xF0)|(val & 0x0F);
	break;

	case 'B':
	case 'b':
		PORT_B = (PORT_B & 0xF0)|(val & 0x0F);
	break;

	case 'C':
	case 'c':
		PORT_C = (PORT_C & 0xF0)|(val & 0x0F);
	break;

	case 'D':
	case 'd':
		PORT_D = (PORT_D & 0xF0)|(val & 0x0F);
	break;
	}
}

void Dio_WriteLowNibbleDir(uint8 PORT, DIO_Direction dir) {
	switch (PORT) {
	case 'A':
	case 'a':
		if (dir == OUT)
		{
			DDR_A |= 0x0f;
		}
		else
		{
			DDR_A &= 0xf0;
		}
		break;

	case 'B':
	case 'b':
		if (dir == OUT) {
			DDR_B |= 0x0f;
		} else {
			DDR_B &= 0xf0;
		}
		break;

	case 'C':
	case 'c':
		if (dir == OUT) {
			DDR_C |= 0x0f;
		} else {
			DDR_C &= 0xf0;
		}
		break;

	case 'D':
	case 'd':
		if (dir == OUT) {
			DDR_D |= 0x0f;
		} else {
			DDR_D &= 0xf0;
		}
		break;

	default:
		/*error*/
		break;
	}

}

void Dio_WriteHighNibbleDir(uint8 PORT, DIO_Direction dir)
{
	switch (PORT)
	{
	case 'A':
	case 'a':
		if (dir == OUT)
		{
			DDR_A |= 0xf0;
		}
		else
		{
			DDR_A &= 0x0f;
		}
		break;

	case 'B':
	case 'b':
		if (dir == OUT) {
			DDR_B |= 0xf0;
		} else {
			DDR_B &= 0x0f;
		}
		break;

	case 'C':
	case 'c':
		if (dir == OUT) {
			DDR_C |= 0xf0;
		} else {
			DDR_C &= 0x0f;
		}
		break;

	case 'D':
	case 'd':
		if (dir == OUT) {
			DDR_D |= 0xf0;
		} else {
			DDR_D &= 0x0f;
		}
		break;

	default:
		/*error*/
		break;
	}

}

