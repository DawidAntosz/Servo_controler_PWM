#ifndef PWM_SOFT_H
#define PWM_SOFT_H

#include "main_menu.h"

#define MAP_FUNCTION(x, in_min, in_max, out_min, out_max) (x-in_min)*(out_max-out_min)/(in_max-in_min)+out_min;


//================== DEFINE PORT =================//
#define PORTB_PIN	(1 << PB1 | 1 << PB2 | 1 << PB3)
#define PORTD_PIN	(1 << PD3 | 1 << PD5 | 1 << PD6)

//================== STATE PORT =================//
#define PIN_STATE_B	STATE_B
#define PIN_STATE_D	STATE_D

//================== CLEAR PORT =================//
#define CLEAR_PORT1     (PIN_STATE_B &= ~(1 << PB3))
#define CLEAR_PORT2 	(PIN_STATE_B &= ~(1 << PB2))
#define CLEAR_PORT3 	(PIN_STATE_B &= ~(1 << PB1))
#define CLEAR_PORT4 	(PIN_STATE_D &= ~(1 << PD3))
#define CLEAR_PORT5 	(PIN_STATE_D &= ~(1 << PD5))
#define CLEAR_PORT6 	(PIN_STATE_D &= ~(1 << PD6))

//================== VARIABLE ==================//
static volatile uint16_t VALUE_tab[6];
static volatile uint16_t VALUE_new[6];

//================== FUNCTION =================//
void init_PWMsoft(void);

void Update_PWM(MENU *);


#endif