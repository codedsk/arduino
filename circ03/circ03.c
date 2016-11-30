#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000
#define HIGH 1
#define LOW 0

void digitalWrite(uint8_t pin, uint8_t sig) {
    if (sig == HIGH) {
        PORTB |= _BV(pin);
        PORTB |= _BV(PORTB5);
    } else if (sig == LOW) {
        PORTB &= ~_BV(pin);
        PORTB &= ~_BV(PORTB5);
    }
}

// FIXME: use pulse width modulation to immitate analogWrite
void analogWrite(uint8_t pin, uint8_t sig) {
    if (sig == HIGH) {
        PORTB |= _BV(pin);
        PORTB |= _BV(PORTB5);
    } else if (sig == LOW) {
        PORTB &= ~_BV(pin);
        PORTB &= ~_BV(PORTB5);
    }
}


void motorOnThenOff() {
    int onTime = 2500;
    int offTime = 1000;
    int motorPin = PORTB1;

    digitalWrite(motorPin,HIGH);
    _delay_ms(onTime);

    digitalWrite(motorPin,LOW);
    _delay_ms(offTime);
}

void motorOnThenOffWithSpeed() {
    int onTime = 2500;
    int offTime = 1000;
    int motorPin = PORTB1;

    // motor speed ranges from 0 (LOW) to 255 (HIGH)
    int onSpeed = 200;
    int offSpeed = 50;

    analogWrite(motorPin,onSpeed);
    _delay_ms(onTime);

    analogWrite(motorPin,offSpeed);
    _delay_ms(offTime);
}

int main (void) {

    /* set PORTB for output*/
    DDRB = 0xFF;

    while(1) {
        motorOnThenOff();
    }
}
