#include "Serial.h"
#include "usart.h"

// Cette fonction pourra être utilisée par le moniteur serie VSCode
unsigned char SerialTransmit(char * pData, unsigned short Size){
         for(uint16_t i = 0 ; i< Size; i++)
         {
            HAL_UART_Transmit(&huart2, (unsigned short *)&pData[i], Size, HAL_MAX_DELAY);
         }
         

         return 0;
}

// Modification de la fonction pour intégrer HAL
void SerialReceiveChar(char * pData, unsigned short Size){

        HAL_UART_Receive(&huart2, (unsigned short *)pData, Size, HAL_MAX_DELAY);

}