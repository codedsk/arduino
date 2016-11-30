import serial
import time

PORT = '/dev/ttyACM0'
SPEED = 9600

modes = ['off','on']


for i in xrange(5):
    connection = serial.Serial( PORT,
        SPEED, timeout=0, stopbits=serial.STOPBITS_TWO)
    connection.write(modes[i%2])
    connection.close()
    time.sleep(2)

