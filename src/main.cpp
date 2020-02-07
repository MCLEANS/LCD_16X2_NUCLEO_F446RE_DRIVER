/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "LCD.h"
			

int main(void)
{
	custom_drivers::LCD lcd;
	lcd.enable_port(GPIOA);
	lcd.enable_port(GPIOB);
	lcd.enable_port(GPIOC);

	lcd.initialize();
	lcd.clear();
	char greeting[] = "HELLO WORLD";
	lcd.send_string(greeting);

	while(1){

	}
}
