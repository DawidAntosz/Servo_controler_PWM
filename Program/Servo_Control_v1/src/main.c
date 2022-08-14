#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include "lcd.h"

#define Button_1 !(PIND & (1<<PD0))
#define Button_2 !(PIND & (1<<PD1))

uint8_t Button_pressed(uint8_t B1, uint8_t B2);

volatile uint8_t pwm1, pwm2, pwm3, pwm4, pwm5, pwm6;

typedef struct {
    char *name;
    int value;
    int posit[2];
    bool active;
    bool current;
}PWM;

struct MENU{
    PWM *PWM_1;
    PWM *PWM_2;
    PWM *PWM_3;
    PWM *PWM_4;
    PWM *PWM_5;
    PWM *PWM_6;

} MENU, *ptr_MENU = &MENU;

void init_MENU(struct MENU *MENU);


int main(void){
    PORTD |= (1<<PD0)|(1<<PD1); // Button pin to logic 1

    DDRB |= (1 << DDB1)|(1 << DDB2)|( 1 << DDB3); // Define PWM port PORT B
    DDRD |= (1 << DDD3)|(1 << DDD5)|( 1 << DDD6); // Define PWM port PORT D

    //===========================================================TIMER0
    TCNT0 = 0x00;

    TCCR0A |= (1<<COM0A1);
    TCCR0A |= (1<<COM0B1);
    
    TCCR0A |= (1<<WGM00)|(1<<WGM01);
    
    TCCR0B |= (1<<CS02)|(1<<CS00);

    OCR0A = 125;
    OCR0B = 200;

    //===========================================================TIMER1
    TCNT1 = 0x00;
    TCCR1A |= (1<<COM1A1);
    TCCR1A |= (1<<COM1B1);

    TCCR1A |= (1<<WGM11);            //
    TCCR1B |= (1<<WGM13)|(1<<WGM12); // - MODE

    TCCR1B |= (1<<CS11)|(1<<CS10);   // - PRESCALER

    ICR1 = 2499; // - 50 Hz

    OCR1A = 125;
    OCR1B = 255;

    //===========================================================TIMER2
    TCNT2 = 0x00;
    TCCR2A |= (1<<COM2A1);
    TCCR2A |= (1<<COM2B1);

    TCCR2A |= (1<<WGM21)|(1<<WGM20);            // Mode fast pwm 

    TCCR2B |= (1<<CS21)|(1<<CS22);   // - PRESCALER

    OCR2A = 125;
    OCR2B = 200;

    //=================================================================

    lcd_init(); // init display

    PWM PWM_1 PROGMEM = {"1:", 11, {0,0}, false, false, false};
    PWM PWM_2 PROGMEM = {"2:", 0, {1,0}, false, false, false};
    PWM PWM_3 PROGMEM = {"3:", 0, {0,5}, false, false, false};
    PWM PWM_4 PROGMEM = {"4:", 0, {1,5}, false, false, false};
    PWM PWM_5 PROGMEM = {"5:", 0, {0,10}, false, false, false};
    PWM PWM_6 PROGMEM = {"6:", 0, {1,10}, false, false, false};
    MENU.PWM_1 = &PWM_1;
    MENU.PWM_2 = &PWM_2;
    MENU.PWM_3 = &PWM_3;
    MENU.PWM_4 = &PWM_4;
    MENU.PWM_5 = &PWM_5;
    MENU.PWM_6 = &PWM_6;

    sei();

    while(1){
        init_MENU(ptr_MENU);
        
        //==============================TEST_MENU
        MENU.PWM_1->active = true;
        MENU.PWM_1->current = true;
        //=======================================

    
    _delay_ms(50); 
    }

}


void init_MENU(struct MENU *MENU){
    lcd_cls();

    //-----------------PWM_1-----------------------------------------
    lcd_locate(MENU->PWM_1->posit[0], MENU->PWM_1->posit[1]);
    lcd_str(MENU->PWM_1->name);

    if(MENU->PWM_1->active){
        lcd_int(MENU->PWM_1->value);
    } else {
        lcd_str("-");
    }
    if(MENU->PWM_1->current){
        lcd_str("=");
    }
    
    //-----------------PWM_2-----------------------------------------
    lcd_locate(MENU->PWM_2->posit[0], MENU->PWM_2->posit[1]);
    lcd_str(MENU->PWM_2->name);

    if(MENU->PWM_2->active){
        lcd_int(MENU->PWM_2->value);
    } else {
        lcd_str("-");
    }

    //-----------------PWM_3-----------------------------------------
    lcd_locate(MENU->PWM_3->posit[0], MENU->PWM_3->posit[1]);
    lcd_str(MENU->PWM_3->name);

    if(MENU->PWM_3->active){
        lcd_int(MENU->PWM_3->value);
    } else {
        lcd_str("-");
    }

    //-----------------PWM_4-----------------------------------------
    lcd_locate(MENU -> PWM_4 -> posit[0], MENU -> PWM_4 -> posit[1]);
    lcd_str(MENU -> PWM_4 -> name);

    if(MENU->PWM_4->active){
        lcd_int(MENU->PWM_4->value);
    } else {
        lcd_str("-");
    }

    //-----------------PWM_5-----------------------------------------
    lcd_locate(MENU->PWM_5->posit[0], MENU->PWM_5->posit[1]);
    lcd_str(MENU->PWM_5->name);

    if(MENU->PWM_5->active){
        lcd_int(MENU->PWM_5->value);
    } else {
        lcd_str("-");
    }

    //-----------------PWM_6-----------------------------------------
    lcd_locate(MENU->PWM_6->posit[0], MENU->PWM_6->posit[1]);
    lcd_str(MENU->PWM_6->name);

    if(MENU->PWM_6->active){
        lcd_int(MENU->PWM_6->value);
    } else {
        lcd_str("-");
    }
}



