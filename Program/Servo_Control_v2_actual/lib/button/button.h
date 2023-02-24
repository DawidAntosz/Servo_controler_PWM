#ifndef BUTTON_H
#define BUTTON_H

#define Button_1 !(PIND & (1<<PD0))
#define Button_2 !(PIND & (1<<PD1))

#define JOYSTICK_B1 !(PINC & (1<<PC4))
#define JOYSTICK_B2 !(PINC & (1<<PC5))

/************************************
//  =====  GLOBAL VARIABLES  ===== //
************************************/
volatile uint8_t time1, time2, time3;

/**************************************
//  =====  FUNCTION PROTOTYPE  ===== //
**************************************/

void button_init(void);

#endif