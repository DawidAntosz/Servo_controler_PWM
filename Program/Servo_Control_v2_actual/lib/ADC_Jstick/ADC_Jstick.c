#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "ADC_Jstick.h"

void ADC_init(void){

    ADMUX|=(1<<REFS0);    
    ADCSRA|=(1<<ADEN)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}

void Joystick_Button_init(void){
    PORTC |= (1<<PC5)|(1<<PC4);
    
    //#define JOYSTICK_B1 !(PINC & (1<<PC4))
    //#define JOYSTICK_B2 !(PINC & (1<<PC5))
}

void ADC_Read(){
           
    ADMUX = (ADMUX & 0xf8)|0b00000000;
    ADCSRA|=(1<<ADSC);
    while((ADCSRA)&(1<<ADSC));
    PT1_vx_val = ADC;
    ADCSRA|=(1<<ADIF);

    ADMUX = (ADMUX & 0xf8)|0b00000001;
    ADCSRA|=(1<<ADSC);
    while((ADCSRA)&(1<<ADSC));
    PT1_vy_val = ADC;
    ADCSRA|=(1<<ADIF);

    ADMUX = (ADMUX & 0xf8)|0b00000010;
    ADCSRA|=(1<<ADSC);
    while((ADCSRA)&(1<<ADSC));
    PT2_vx_val = ADC;
    ADCSRA|=(1<<ADIF);

    ADMUX = (ADMUX & 0xf8)|0b00000011;
    ADCSRA|=(1<<ADSC);
    while((ADCSRA)&(1<<ADSC));
    PT2_vy_val = ADC;
    ADCSRA|=(1<<ADIF);

}