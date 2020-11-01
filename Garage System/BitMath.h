/*
 * BitMath.h
 *
 *  Created on: Sep 20, 2019
 *      Author: breks
 */

#ifndef UTIL_BITMATH_H_
#define UTIL_BITMATH_H_

#define SET_BIT(u8Var,Pin)		u8Var |= (1<<Pin)
#define CLR_BIT(u8Var,Pin)		u8Var &=~(1<<Pin)
#define TOGGLE_BIT(u8Var,Pin)	u8Var ^= (1<<Pin)
#define GET_BIT(u8Var,Pin)		(u8Var >> Pin) & 0x01

#endif /* UTIL_BITMATH_H_ */
