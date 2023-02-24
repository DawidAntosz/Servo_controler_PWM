#ifndef ADC_JSTICK_H
#define ADC_JSTICK_H 


//================== DEFINE PORT =================//

/*

#define PT1_vx PC3
#define PT1_vy PC2

#define PT2_vx PC1
#define PT2_vy PC0

#define PT2_SW PC5
#define PT1_SW PC4
#define Button_PT1 !(PINC & (1<<PT1_SW))
#define Button_PT2 !(PINC & (1<<PT2_SW))

*/

//================== VARIABLE ==================//


volatile float PT1_vx_val;
volatile float PT1_vy_val;

volatile float PT2_vx_val;
volatile float PT2_vy_val;


volatile uint8_t J1_time, J2_time, J1_J2_time;

//================== FUNCTION =================//
void ADC_init();
void ADC_Read();
void Joystick_Button_init(void);


#endif