#include "led.h"
#include "tim.h"

void LedStart(void){
    // Démarre le timer
    HAL_TIM_Base_Start(&htim2);
    htim2.Instance->CCR1 = 127; // Rapport Cyclique 255/127.5 = 0.5 
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
}

void LedSetValue(unsigned int val){
    // Configure le rapport cyclique de la PWM entre 0 et 255
    htim2.Instance->CCR1 = val;
}

void LedPulse(void){
    // À chaque appel, cette fonction incrémente la luminosité de la LED
    // Arrivé à la valeur maximale, chaque appel décrémente la LED
    static unsigned int lux = 1;
    static unsigned int up = 1;

    if (lux >= 255)
    {
        up = 0; //Si la luminosité atteint la valeur max, alors on décrémente
    }

    if (lux <= 0)
    {
        up = 1; //Si la luminosité atteint la valeur m, alors on incrémente
    }

    if(up = 0){
        lux--;
    }else{
        lux++;
    }

    LedSetValue(lux);
    

}