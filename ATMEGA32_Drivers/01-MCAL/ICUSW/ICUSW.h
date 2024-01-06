/*
 * ICUSW.h
 *
 * Created: 10/27/2023 12:41:45 PM
 *  Author: Ahmed Wael
 */


#ifndef ICUSW_H_
#define ICUSW_H_
/*NOTE: THIS DRIVER USE TIMER0, DONT USE TIMER0 WHILE USING THIS DRIVER*/
/*
MINIMUM FREQUENCY: 1khz
MAXIMUM FREQUENCY: 50khz
*/

void ICUSW_voidEnable();
void ICUSW_voidDisable();

void ICUSW_voidGetICUSW(u32* Add_u8PeriodTimeus, u16* Add_u8OnTimeus, u8*Add_u16DutyCucle);







#endif /* ICUSW_H_ */