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
    
    storedDis = 0
    while not keyboard.is_pressed('q'):
        if serArd.inWaiting() > 0:
            rec_time = datetime.now().strftime('%H:%M:%S.%f')
            myData = serArd.readline().decode().rstrip()
            calData = float(myData) * 104 * 10 ** (-4)
            finalData = round(calData, 2)
<<<<<<< HEAD
            #diff = finalData - storedDis
            try:
                finalSpeed = (finalData - storedDis) / float(myData) * 10 ** (3)
                storedDis = finalData
=======
            finalSpeed = abs((finalData - timeStored)) / float(myData) * 10 ** 3
            timeStored = round(finalData, 2) 
            try:
                myData = float(myData)
                print(f"The speed is {finalData} cm / s")
>>>>>>> 030800e68ca9b2be8c00bdca87233fb6349ff7fe
            except:
                finalSpeed = 0
            if finalSpeed <= -0.1: #Change
                a = "forward"
            elif finalSpeed >= 0.1:
                a = "backward"
            else:
                a = "not Moving"
            #try:
                #print(f"The distance is {finalData} cm")
            print(f"The speed is {abs(finalSpeed)} cm/s " + a)
            #except:
                #print("No data") 
