#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "lcd.h"
#include "main_menu.h"
#include "button.h"
#include "PWM_soft.h"
#include "I2C.h"
#include "ADC_Jstick.h"


int main(void){
    MENU MENU_, *ptr_MENU;
    ptr_MENU = &MENU_;
    PWM PWM_1 = {"1:", 0, {0,0}, false, false};
    PWM PWM_2 = {"2:", 0, {1,0}, false, false};
    PWM PWM_3 = {"3:", 0, {0,5}, false, false};
    PWM PWM_4 = {"4:", 0, {1,5}, false, false};
    PWM PWM_5 = {"5:", 0, {0,10}, false, false};
    PWM PWM_6 = {"6:", 0, {1,10}, false, false};
    MENU_.PWM_1 = &PWM_1;
    MENU_.PWM_2 = &PWM_2;
    MENU_.PWM_3 = &PWM_3;
    MENU_.PWM_4 = &PWM_4;
    MENU_.PWM_5 = &PWM_5;
    MENU_.PWM_6 = &PWM_6;

    lcd_init();
    button_init();
    MENU_init();
    init_PWMsoft();
    
    sei();

    while(1){        
        lcd_cls();
        Update_MENU(ptr_MENU);
        Update_PWM(ptr_MENU);
        _delay_ms(10); 
    }


    ADC_init();
    //Joystick_Button_init();
    I2C_init();

  
    while(false){  

        lcd_cls();

        ADC_Read();

        
        lcd_locate(0, 10);
        lcd_int(PT1_vx_val);
        lcd_locate(1, 10);
        lcd_int(PT1_vy_val);
        
        lcd_locate(0, 4);
        lcd_int(PT2_vx_val);
        lcd_locate(1, 4);
        lcd_int(PT2_vy_val);


        if ( JOYSTICK_B1 || JOYSTICK_B2)  {
            lcd_locate(0, 0);
            lcd_str("HHE");
        }
        else{
            lcd_locate(0, 0);
            lcd_str("a");
        }



        _delay_ms(10);    
        
         
    }
}