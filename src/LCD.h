/*
 * LCD.h
 *
 *  Created on: Aug 24, 2019
 *      Author: MCLEANS
 */

#ifndef LCD_H_
#define LCD_H_

#define D0PORT	GPIOB
#define D0PIN	3
#define D1PORT 	GPIOB
#define D1PIN 	5
#define D2PORT	GPIOB
#define D2PIN	4
#define D3PORT	GPIOB
#define D3PIN	10
#define D4PORT	GPIOA
#define D4PIN	8
#define D5PORT	GPIOA
#define D5PIN	9
#define D6PORT	GPIOC
#define D6PIN	7
#define D7PORT	GPIOB
#define D7PIN	6
#define ENABLEPORT	GPIOA
#define ENABLEPIN	10
#define RWPORT	GPIOA
#define RWPIN	2
#define RSPORT GPIOA
#define RSPIN 	3

#define TIMEDELAYBEFOREENABLE 4
#define TIMEDELAYBEFOREDISABLE  8

#include "stm32f4xx.h"
#include "stdio.h"

namespace custom_drivers {



class LCD {
private:
	int duration = 0;
	char data[16];
	int row = 0;
	int column = 0;





public:
	LCD();
	virtual ~LCD();
	void enable_port(GPIO_TypeDef* PORT);
	void configure_pin_for_output(GPIO_TypeDef* PORT, uint8_t PIN);
	void configure_pins();
	void initialize();
	void delay_ms(int duration);
	void send_bit_to_pin(GPIO_TypeDef* PORT, uint8_t PIN, uint8_t state);
	void send_byte(char byte);
	void enable();
	void set_to_read_mode();
	void set_to_write_mode();
	void set_to_instruction_mode();
	void set_to_character_mode();
	void send_character(char character);
	void send_instruction(char byte);
	void clear();
	void newline();
	void send_string(char *data);
	void set_cursor_to_location(int row, int column);


};

} /* namespace custom_drivers */

#endif /* LCD_H_ */
