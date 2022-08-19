import serial
from datetime import datetime
import time
import keyboard 

SampleTime = '500'

with serial.Serial('/dev/cu.usbmodem14201',9600) as serArd:
    print(f"The arduino board is connected through {serArd.port}")
    time.sleep(2)
    serArd.reset_input_buffer()

    if (serArd.writable()):
        serArd.write(SampleTime.encode())
        print(serArd.readline().decode().rstrip())
    while not keyboard.is_pressed('q'):
        if serArd.inWaiting() > 0:
            rec_time = datetime.now().strftime('%H:%M:%S.%f')
            myData = serArd.readline().decode().rstrip()
            calData = float(myData) / 57
            finalData = round(calData, 2)
            try:
                myData = float(myData)
                print(f"Raw data at {rec_time} : {finalData}")
            except:
                print("No data") 
