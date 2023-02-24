#ifndef MAIN_MENU_H
#define MAIN_MENU_H

/************************************
//  =====  GLOBAL VARIABLES  ===== //
************************************/
#include <stdbool.h>

typedef struct{
    char *name;
    int value;
    int posit[2];
    bool active;
    bool current;
}PWM;

typedef struct{
    PWM *PWM_1;
    PWM *PWM_2;
    PWM *PWM_3;
    PWM *PWM_4;
    PWM *PWM_5;
    PWM *PWM_6;
}MENU;

uint8_t current_Port_Button;
bool SELECT_FLAG;

void MENU_init(void);
void Update_MENU(MENU *);

int Change_Value(int value);
void Button_pressed(void);

#endif