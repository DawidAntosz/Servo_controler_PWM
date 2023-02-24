#include <avr/io.h>
#include <avr/interrupt.h>
#include "button.h"
#include "ADC_Jstick.h"

void button_init(){

    // === BUTTON INIT === //

    PORTD |= (1<<PD0)|(1<<PD1); // Button pin to logic 1
    DDRC  |= (0<<PC5)|(0<<PC4);
    PORTC |= (1<<PC5)|(1<<PC4); // Joystick SW pin to logic 1

    // === TIMER INIT === //
    TCNT0 = 0;
    TCCR0B |= (1<<CS00) | (1<<CS02);
    TIMSK0 = (1<<TOIE0);
}

ISR(TIMER0_OVF_vect){

// =======================================================BUTTON

    if(Button_1 & !Button_2){
        time1 += 1;
        time2 = 0;
        time3 = 0;
    }
    if(!Button_1 & Button_2){
        time1 = 0;
        time2 += 1;
        time3 = 0;
    }
    if(Button_1 & Button_2){
        time1 = 0;
        time2 = 0;
        time3 += 1;
    }

// ======================================================JOYSTICK
 /*
    if(Joystick_1 & !Joystick_2){
        J1_time += 1;
        J2_time = 0;
        J1_J2_time = 0;
    }
    if(!Joystick_1 & Joystick_2){
        J1_time = 0;
        J2_time += 1;
        J1_J2_time = 0;
    }
    if(Joystick_1 & Joystick_2){
        J1_time = 0;
        J2_time = 0;
        J1_J2_time += 1;
    }
*/
}