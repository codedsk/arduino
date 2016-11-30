all:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lesson2.o lesson2.c
	avr-gcc -mmcu=atmega328p lesson2.o -o lesson2
	avr-objcopy -O ihex -R .eeprom lesson2 lesson2.hex

install:
	avrdude -F -b 115200 -c arduino -p atmega328p -P /dev/ttyACM0 -U flash:w:lesson2.hex

clean:
	rm -f lesson2 lesson2.hex lesson2.o

distclean: clean
