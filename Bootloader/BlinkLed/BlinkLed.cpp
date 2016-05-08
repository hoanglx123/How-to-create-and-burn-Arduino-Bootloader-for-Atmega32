/*
 * BlinkLed.cpp
 *
 * Created: 4/22/2016 10:38:47 PM
 *  Author: Mr Hoang
 */ 


#include <avr/io.h>
#include <util/delay.h>

/* Configure port to control LED */
#define LED_DDR  DDRA
#define LED_PORT PORTA
#define LED_CTRL PINA4

/* Set and clear each bit */
#define sbi(port, bit) port | (1 << bit)	/* Set bit */
#define cbi(port, bit) port & (~(1 << bit))	/* Clear bit */

int main(void)
{
	LED_DDR  = 0xFF; 
	LED_PORT = 0xFF; 
	
    while(1)
    {
        LED_PORT ^= sbi(LED_PORT, LED_CTRL);
		_delay_ms(100); 
    }
}