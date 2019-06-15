#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int speakerPin = 9;
int length = 15; // the number of nots
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

//  /* set pin 1 high to turn led on */
//  PORTB |= _BV(PORTB1);
//  /* set pin 2 low to turn led off */
//  PORTB &= ~_BV(PORTB2);
//
//  /* sleep */
//  _delay_ms(BLINK_DELAY_MS);

void playTone(int tone, int duration) {
    long i = 0;

    for (i = 0; i < duration * 1000L; i += tone * 2) {
        // digitalWrite(speakerPin, HIGH);
        // delayMicroseconds(tone);

        // set arduino pin 9 high
        PORTB |= _BV(PORTB1);
        // _delay_ms((const uint32_t)tone);
        _delay_ms(1915);
    }

    // digitalWrite(speakerPin, LOW)
    // delayMicroseconds(tone);

    // set arduino pin 9 low
    PORTB &= ~_BV(PORTB1);
    // _delay_ms((const uint32_t)tone);
    _delay_ms(1915);
}

void playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'c' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
    int i = 0;

    // play the tone corresponding to the note name
    for (i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}


void setup() {
    // pinmode(speakerPin, OUTPUT);

    /* set arduino pin 9 (pin 1 of PORTB) for output*/
    DDRB |= _BV(DDB1);
}

void loop() {
    int i = 0;

    for (i = 0; i < length; i++) {
        if (notes[i] == ' ') {
            // delay(beats[i] * tempo); // rest
            _delay_ms(beats[i] * tempo); // rest
        } else {
            playNote(notes[i], beats[i] * tempo);
        }
        // pause between notes
        // delay(tempo / 2);
        _delay_ms((int const)(tempo / 2));
    }
}

int main (void)
{
    setup();

    while(1) {
        loop();
    }
}

