#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "PWM_soft.h"


void init_PWMsoft(void){

	//========================= TIMER SETTING =========================//
	TCCR1B = (1<<CS10)|(1<<WGM12);
	TIMSK1 = (1<<OCIE1A);
	TIFR1 = (1<<OCF1A);
	OCR1A = 1249;
	
	//========================= PORT SETTING =========================//
	DDRB |= (1 << DDB1)|(1 << DDB2)|( 1 << DDB3); // PWM port PORT B
    DDRD |= (1 << DDD3)|(1 << DDD5)|( 1 << DDD6); // PWM port PORT D
	
	//======================= INIT START VALUE ========================//
	for(auto uint8_t i = 0; i < 6; i++){
		VALUE_tab[i] = 0;
		VALUE_new[i] = 0;
	}
}

void Update_PWM(MENU * MENU_){
    uint8_t tab_PWM[6] = {0,0,0,0,0,0};

	if (MENU_->PWM_1->active) tab_PWM[0] = MENU_->PWM_1->value;
    if (MENU_->PWM_2->active) tab_PWM[1] = MENU_->PWM_2->value;
    if (MENU_->PWM_3->active) tab_PWM[2] = MENU_->PWM_3->value;
    if (MENU_->PWM_4->active) tab_PWM[3] = MENU_->PWM_4->value;
    if (MENU_->PWM_5->active) tab_PWM[4] = MENU_->PWM_5->value;
    if (MENU_->PWM_6->active) tab_PWM[5] = MENU_->PWM_6->value;

	for(uint8_t i=0; i<6; i++){
		uint8_t value = MAP_FUNCTION(tab_PWM[i],0,180,0,26);
		VALUE_new[i] = value;
	}
}


//=============================== ISR ===============================//

ISR(TIMER1_COMPA_vect){ 
	
	static uint8_t counter = 0xFF;

	static uint8_t STATE_B = PORTB_PIN;
	static uint8_t STATE_D = PORTD_PIN;

	PORTB = (PORTB & (~(PORTB_PIN))) | STATE_B;
	PORTD = (PORTD & (~(PORTD_PIN))) | STATE_D;

	counter ++;

	if(counter == 0){
		
		for(auto uint8_t i = 0; i < 6; i++){
			VALUE_tab[i] = VALUE_new[i];
		}
		STATE_B = PORTB_PIN;
		STATE_D = PORTD_PIN;
	}
	
	if(VALUE_tab[0] == counter) CLEAR_PORT1;
	if(VALUE_tab[1] == counter) CLEAR_PORT2;
	if(VALUE_tab[2] == counter) CLEAR_PORT3;
	if(VALUE_tab[3] == counter) CLEAR_PORT4;
	if(VALUE_tab[4] == counter) CLEAR_PORT5;
	if(VALUE_tab[5] == counter) CLEAR_PORT6;

}
