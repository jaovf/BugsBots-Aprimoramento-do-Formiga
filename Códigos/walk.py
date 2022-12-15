import time
import serial

while (1):

	time.sleep(2)

	ser1 = serial.Serial("/dev/serial/by-id/usb-mbed_Microcontroller_101000000000000000000002F7F0C7A2-if01")

	ser2 = serial.Serial("/dev/serial/by-id/usb-mbed_Microcontroller_101000000000000000000002F7F1EA94-if01")


	ser1.write(1)
	ser2.write(1)

	time.sleep(10)

	ser1.close()
	ser2.close()





