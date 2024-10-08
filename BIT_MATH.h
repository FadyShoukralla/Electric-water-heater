/*
 * BIT_MATH.h
 *
 * Created: 6/29/2024 6:10:20 PM
 *  Author: mrfed
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(x,n)     x=x|(1<<n)

#define TOGGLE_BIT(x,n)  x=x^(1<<n)

#define CLEAR_BIT(x,n)   x=x&(~(1<<n))

#define GET_BIT(x,n)   ((x&(1<<n))>>n)

#endif /* BIT_MATH_H_ */