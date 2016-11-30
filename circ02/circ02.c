#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000


void blink_pin(uint8_t pin) {
    /* set pin 1 high to turn led on */
    PORTB |= _BV(pin);
    _delay_ms(BLINK_DELAY_MS);

    /* set pin 1 low to turn led off */
    PORTB &= ~_BV(pin);
    _delay_ms(BLINK_DELAY_MS);
}

int main (void) {

    /* set PORTB for output*/
    DDRB = 0xFF;

    while(1) {
        blink_pin(PORTB0);
        blink_pin(PORTB1);
        blink_pin(PORTB2);
        blink_pin(PORTB3);
        blink_pin(PORTB4);
        blink_pin(PORTB5);
    }
}
