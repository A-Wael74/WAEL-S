/*
 * Utils.h
 *
 * Created: 7/24/2022 10:06:18 PM
 *  Author: Ahmed Wael
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define GET_BIT(reg,bit)     ((reg>>bit)&1)
#define SET_BIT(reg,bit)     (reg |= (1<<bit))
#define CLR_BIT(reg,bit)     (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)     (reg ^= (1<<bit))
#define write_bit(reg,bit,val)    (reg = reg&~(1<<bit)|val<<bit)



#endif /* UTILS_H_ */