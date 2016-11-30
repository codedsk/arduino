PROG   = circ02
cc     = avr-gcc
oc     = avr-objcopy
du     = avrdude
clock  = 16000000UL
mcu    = atmega328p
baud   = 115200
programmer = arduino
port   = /dev/ttyACM0
memtype = flash
op     = w
filename = ${PROG}.hex

cflags = -Os -DF_CPU=${clock} -mmcu=${mcu}


all:
	${cc} ${cflags} -c -o ${PROG}.o ${PROG}.c
	${cc} -mmcu=${mcu} ${PROG}.o -o ${PROG}
	${oc} -O ihex -R .eeprom ${PROG} ${PROG}.hex

install:
	${du} -F -b ${baud} -c ${programmer} -p ${mcu} -P ${port} -U ${memtype}:${op}:${filename}

clean:
	rm -f ${PROG} ${PROG}.hex ${PROG}.o

distclean: clean
