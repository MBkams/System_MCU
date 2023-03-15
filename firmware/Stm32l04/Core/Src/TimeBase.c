#include "TimeBase.h"
#include "tim.h"

void TimeBaseStartIT(void){

    HAL_TIM_Base_Start_IT(&htim21);
}