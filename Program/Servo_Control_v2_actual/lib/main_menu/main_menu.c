#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdbool.h>
#include "button.h"
#include "lcd.h"
#include "main_menu.h"
#include "ADC_Jstick.h"

void MENU_init(void){
    current_Port_Button = 0;
    SELECT_FLAG = false;
}

void Update_MENU(MENU *MENU_){

    //============================================== ENTER FLAG ===
    if (time3 > 15) {
        SELECT_FLAG = !SELECT_FLAG;
        time3 = 0;
    }

    if (SELECT_FLAG == false){
        Button_pressed();
    }
    
    //============================================================
    //===========================_MENU_===========================
        switch (current_Port_Button)
        {
        case 1:
            MENU_->PWM_1->current = true;
            if(SELECT_FLAG){
                MENU_->PWM_1->active = true;
            }
            break;
        case 2:
            MENU_->PWM_2->current = true;
            if(SELECT_FLAG){
                MENU_->PWM_2->active = true;
            }
            break;
        case 3:
            MENU_->PWM_3->current = true;
            if(SELECT_FLAG){
                MENU_->PWM_3->active = true;
            }
            break;
        case 4:
            MENU_->PWM_4->current = true;
            if(SELECT_FLAG){
                MENU_->PWM_4->active = true;
            }
            break;
        case 5:
            MENU_->PWM_5->current = true;
            if(SELECT_FLAG){
                MENU_->PWM_5->active = true;
            }
            break;
        case 6:
            MENU_->PWM_6->current = true;
            if(SELECT_FLAG){
                MENU_->PWM_6->active = true;
            }
            break;
        default:
            break;
        }
    
    //================================================================
    //================================================================
    //=======================PWM_1====================================
    lcd_locate(MENU_->PWM_1->posit[0], MENU_->PWM_1->posit[1]);
    lcd_str(MENU_->PWM_1->name);

    if(MENU_->PWM_1->current){
        lcd_locate(MENU_->PWM_1->posit[0], MENU_->PWM_1->posit[1] + 1);
        lcd_str(">");
        MENU_->PWM_1->current = false;

        if(MENU_->PWM_1->active){
            if(SELECT_FLAG){
                int new_val = Change_Value(MENU_->PWM_1->value); 
                MENU_->PWM_1->value = new_val;
            }
        }
    } 
    if(MENU_->PWM_1->active){
        lcd_int(MENU_->PWM_1->value);
    } else {
        lcd_str("-");
    }
    
    //=======================PWM_2====================================
    lcd_locate(MENU_->PWM_2->posit[0], MENU_->PWM_2->posit[1]);
    lcd_str(MENU_->PWM_2->name);

    if(MENU_->PWM_2->current){
        lcd_locate(MENU_->PWM_2->posit[0], MENU_->PWM_2->posit[1] + 1);
        lcd_str(">");
        MENU_->PWM_2->current = false;

        if(MENU_->PWM_2->active){
            if(SELECT_FLAG){
                int new_val = Change_Value(MENU_->PWM_2->value); 
                MENU_->PWM_2->value = new_val;
            }
        }
    }
    if(MENU_->PWM_2->active){
        lcd_int(MENU_->PWM_2->value);
    } else {
        lcd_str("-");
    }

    //=======================PWM_3====================================
    lcd_locate(MENU_->PWM_3->posit[0], MENU_->PWM_3->posit[1]);
    lcd_str(MENU_->PWM_3->name);

    if(MENU_->PWM_3->current){
        lcd_locate(MENU_->PWM_3->posit[0], MENU_->PWM_3->posit[1] + 1);
        lcd_str(">");
        MENU_->PWM_3->current = false;

        if(MENU_->PWM_3->active){
            if(SELECT_FLAG){
                int new_val = Change_Value(MENU_->PWM_3->value); 
                MENU_->PWM_3->value = new_val;
            }
        }
    }
    if(MENU_->PWM_3->active){
        lcd_int(MENU_->PWM_3->value);
    } else {
        lcd_str("-");
    }

    //=======================PWM_4====================================
    lcd_locate(MENU_ -> PWM_4 -> posit[0], MENU_ -> PWM_4 -> posit[1]);
    lcd_str(MENU_ -> PWM_4 -> name);

    if(MENU_->PWM_4->current){
        lcd_locate(MENU_->PWM_4->posit[0], MENU_->PWM_4->posit[1] + 1);
        lcd_str(">");
        MENU_->PWM_4->current = false;

        if(MENU_->PWM_4->active){
            if(SELECT_FLAG){
                int new_val = Change_Value(MENU_->PWM_4->value); 
                MENU_->PWM_4->value = new_val;
            }
        }
    }
    if(MENU_->PWM_4->active){
        lcd_int(MENU_->PWM_4->value);
    } else {
        lcd_str("-");
    }

    //=======================PWM_5====================================
    lcd_locate(MENU_->PWM_5->posit[0], MENU_->PWM_5->posit[1]);
    lcd_str(MENU_->PWM_5->name);

    if(MENU_->PWM_5->current){
        lcd_locate(MENU_->PWM_5->posit[0], MENU_->PWM_5->posit[1] + 1);
        lcd_str(">");
        MENU_->PWM_5->current = false;

        if(MENU_->PWM_5->active){
            if(SELECT_FLAG){
                int new_val = Change_Value(MENU_->PWM_5->value); 
                MENU_->PWM_5->value = new_val;
            }
        }
    }
    if(MENU_->PWM_5->active){
        lcd_int(MENU_->PWM_5->value);
    } else {
        lcd_str("-");
    }

    //=======================PWM_6====================================
    lcd_locate(MENU_->PWM_6->posit[0], MENU_->PWM_6->posit[1]);
    lcd_str(MENU_->PWM_6->name);

    if(MENU_->PWM_6->current){
        lcd_locate(MENU_->PWM_6->posit[0], MENU_->PWM_6->posit[1] + 1);
        lcd_str(">");
        MENU_->PWM_6->current = false;
        if(MENU_->PWM_6->active){
            if(SELECT_FLAG){
                int new_val = Change_Value(MENU_->PWM_6->value); 
                MENU_->PWM_6->value = new_val;
            }
        }
    }
    if(MENU_->PWM_6->active){
        lcd_int(MENU_->PWM_6->value);
    } else {
        lcd_str("-");
    }
}

int Change_Value(int value){
    if (time1 > 3){
        value += 1;
        time1 = 0;
    }
    if (time2 > 3){
        value -= 1;
        time2 = 0;
    }
    if(value > 180){
        value = 180;
    }
    if(value < 0){
        value = 0;
    }
    return value;
}

void Button_pressed(){
    if (time1 > 15){
        current_Port_Button += 1;
        time1 = 0;
        current_Port_Button %= 7; // Modulo 7 for 1-6 choice
    }
    if (time2 > 15){
        current_Port_Button -= 1;
        time2 = 0;
        if(current_Port_Button > 7){ 
            current_Port_Button = 6; // here range uint8_t 0-255 -> 255-1=254 %=7 => 3
        }
        current_Port_Button %= 7; 
    }
}