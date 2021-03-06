// By Chris Andriessen
// Requires second Arduino UNO or MEGA for pendant and another MEGA for LCD.
// Needs Serial TX from pendant Arduino to Serial RX on GRBL Arduino connected.
// Needs Serial RX(pin 10) from LCD Arduino to Serial TX on GRBL Arduino connected.
// Can be used while connected to PC with Gcode sender software.


#include <Wire.h>  
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Regexp.h>


LiquidCrystal_I2C lcd(0x27, 20, 4);
SoftwareSerial mySerial(10, 11); // RX, TX
   
    
    String data = "";
    String Posd = "";
   

    void setup()  
    {
        mySerial.begin(115200);
        lcd.begin();
        drawEmpty();
    }

    void loop() // run over and over
    {
      while(mySerial.available()==0)
      {}
      char character;
      while(mySerial.available()>0)
      {
       character = mySerial.read();
       data += character;
     }
     getStatus();
     getPOS();

     data = "";
    }

    void drawEmpty(){
      lcd.setCursor(0,0);
      lcd.print("X: 0.000            ");
      lcd.setCursor(0,1);
      lcd.print("Y: 0.000            ");
      lcd.setCursor(0,2);
      lcd.print("Z: 0.000            ");
      lcd.setCursor(0,3);
      lcd.print("FS: 0      ");
      lcd.setCursor(11,3);
      lcd.print(">: NoData");
    }
     
     void getStatus(){
      String str = data; 
      int str_len = str.length() + 1; 
      char char_array[str_len];
      str.toCharArray(char_array, str_len);
      char buf [100];
      MatchState ms;
      ms.Target (char_array);  
      char result = ms.Match ("<([A-z]+)\|", 0); 
      if (result == REGEXP_MATCHED){
       lcd.setCursor(11,3);
       lcd.print(">: ");
       lcd.print(ms.GetCapture (buf,0));
       String buflen(ms.GetCapture (buf,0));
       int len = 9 - (3 + buflen.length());
       while (len > 0) {
        lcd.print(" ");
        len -= 1;
       }
      }
      buf [100] = "";
     }

     void getPOS(){
      String str = data; 
      int str_len = str.length() + 1; 
      char char_array[str_len];
      str.toCharArray(char_array, str_len);
      char buf [100];
      MatchState ms;
      ms.Target (char_array); 
      char result = ms.Match ("MPos:((.*))\|FS", 0);  
      Posd = ms.GetCapture (buf,0);
      getX();
      getY();
      getZ();
      getFeed();
     }


     void getX(){
      String str = Posd; 
      int str_len = str.length() + 1; 
      char char_array[str_len];
      str.toCharArray(char_array, str_len);
      char buf [100];
      MatchState ms;
      ms.Target (char_array); 
      char result = ms.Match ("([0-9-]+[.][0-9]+)", 0);  
      if (result == REGEXP_MATCHED){
       lcd.setCursor(0,0);
       lcd.print("X: ");
       lcd.print(ms.GetCapture (buf,0));
       String buflen(ms.GetCapture (buf,0));
       int len = 20 - (3 + buflen.length());
       while (len > 0) {
        lcd.print(" ");
        len -= 1;
       }
      }
      buf [100] = "";
     }

     void getY(){
      String str = Posd; 
      int str_len = str.length() + 1; 
      char char_array[str_len];
      str.toCharArray(char_array, str_len);
      char buf [100];
      MatchState ms;
      ms.Target (char_array);
      char result = ms.Match (",([0-9-]+[.][0-9]+),", 0);  
      if (result == REGEXP_MATCHED){
       lcd.setCursor(0,1);
       lcd.print("Y: ");
       lcd.print(ms.GetCapture (buf,0));
       String buflen(ms.GetCapture (buf,0));
       int len = 20 - (3 + buflen.length());
       while (len > 0) {
        lcd.print(" ");
        len -= 1;
       }
      }
      buf [100] = "";
     }

     void getZ(){
      String str = Posd; 
      int str_len = str.length() + 1; 
      char char_array[str_len];
      str.toCharArray(char_array, str_len);
      char buf [100];
      MatchState ms;
      ms.Target (char_array); 
      char result = ms.Match ("([0-9-]+[.][0-9]+)$", 0);  
      if (result == REGEXP_MATCHED){
       lcd.setCursor(0,2);
       lcd.print("Z: ");
       lcd.print(ms.GetCapture (buf,0));
       String buflen(ms.GetCapture (buf,0));
       int len = 20 - (3 + buflen.length());
       while (len > 0) {
        lcd.print(" ");
        len -= 1;
       }
      }
      buf [100] = "";
     }

     void getFeed(){
      String str = data; 
      int str_len = str.length() + 1; 
      char char_array[str_len];
      str.toCharArray(char_array, str_len);
      char buf [100];
      MatchState ms;
      ms.Target (char_array);  
      char result = ms.Match ("FS:([0-9]+),[0-9]+", 0); 
      if (result == REGEXP_MATCHED){
       lcd.setCursor(0,3);
       lcd.print("FS: ");
       lcd.print(ms.GetCapture (buf,0));
       String buflen(ms.GetCapture (buf,0));
       int len = 10 - (3 + buflen.length());
       while (len > 0) {
        lcd.print(" ");
        len -= 1;
       }
      }
      buf [100] = "";
     }

     
