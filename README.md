# GRBL 1.1 Pendant with LCD
![IMG_20210303_090325](https://user-images.githubusercontent.com/50437199/109773474-89943300-7bff-11eb-8153-c5cf375ac23e.jpg)

Arduino UNO or MEGA Pendant with LCD for GRBL 1.1f (Jog X Y Z and send any Command while connected to PC simultaneously)  

* Requires second Arduino UNO or MEGA for pendant and another MEGA for LCD.
* Needs Serial TX from pendant Arduino to Serial RX on GRBL Arduino connected.
* Needs Serial RX(pin 10) from LCD Arduino to Serial TX on GRBL Arduino connected.
* Can be used while connected to PC with Gcode sender software. 

Libraries:
* https://www.arduino.cc/reference/en/libraries/regexp/
* https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/

Send any command to GRBL with push buttons. 
Already included Jogging with pin 7, 6, 5, 4, 3 and 2. Diagonal jogging support included.
And Unlock with pin 8.

* Pin 7 = X1  
* Pin 6 = X2  
* Pin 5 = Y1  
* Pin 4 = Y2  
* Pin 3 = Z1  
* Pin 2 = Z2  

* Pin 8 = Unlock

LCD 4x20:
![IMG_20210303_090054](https://user-images.githubusercontent.com/50437199/109773085-12f73580-7bff-11eb-8436-7b7d54cffe93.jpg)



**Video** : https://www.youtube.com/watch?v=AHFh_BJhGSI  
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/AHFh_BJhGSI/0.jpg)](https://www.youtube.com/watch?v=AHFh_BJhGSI)

Tip: Use 10k resistors for your buttons to avoid static interference!
