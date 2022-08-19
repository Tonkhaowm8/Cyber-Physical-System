from tempfile import TemporaryFile
import serial
import sys 
LED_flag = False
with serial.Serial('/dev/cu.usbmodem14301', 9600, timeout = 1) as serArd:
    print(f"The Arduino board is connect through {serArd.port}")
    while True:
        try:
            con_val = input(f"Enter 1 to turn on RED LED and 0 to turn off RED LED 2 to turn on GREEN LED and 3 for potentiometer: ")
            while not con_val in ['0', '1', '2', '3', 'q']:
                print(f"Please enter 0, 1, 2 or 3 !")
                con_val = input(f"Enter 1 to turn on RED LED and 0 to turn off RED LED 2 to turn on GREEN LED and 3 for potentiometer: ")
            print(f"You entered {con_val}")
            if (serArd.writable() and con_val != 'q'):
                serArd.write(con_val.encode())
                myData = serArd.readline().decode()
                print(myData)

            if con_val == 'q':
                print('program is stopped!')
                break

        except serial.SerialException as er: #
            print(er)

        except KeyboardInterrupt:
            sys.exit(0)
