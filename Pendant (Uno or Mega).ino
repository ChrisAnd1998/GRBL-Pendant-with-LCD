// By Chris Andriessen
// Requires second Arduino UNO or MEGA for pendant and another MEGA for LCD.
// Needs Serial TX from pendant Arduino to Serial RX on GRBL Arduino connected.
// Needs Serial RX(pin 10) from LCD Arduino to Serial TX on GRBL Arduino connected.
// Can be used while connected to PC with Gcode sender software.



int X1Pin = 7;
int X2Pin = 6;
int Y1Pin = 5;
int Y2Pin = 4;
int Z1Pin = 3;
int Z2Pin = 2;
int T8Pin = 8;

int X1val = 0;   
int X2val = 0;  
int Y1val = 0;  
int Y2val = 0;   

int Z1val = 0;  
int Z2val = 0; 
int T8val = 0;  



void setup() {
  pinMode(X1Pin, INPUT);
  pinMode(X2Pin, INPUT);
  pinMode(Y1Pin, INPUT);
  pinMode(Y2Pin, INPUT);
  pinMode(Z1Pin, INPUT);
  pinMode(Z2Pin, INPUT);
  pinMode(T8Pin, INPUT);
 

  X1val = digitalRead(X1Pin); 
  X2val = digitalRead(X2Pin); 
  Y1val = digitalRead(Y1Pin); 
  Y2val = digitalRead(Y2Pin); 
  Z1val = digitalRead(Z1Pin); 
  Z2val = digitalRead(Z2Pin); 
  T8val = digitalRead(T8Pin); 

  


  if (X1val == HIGH && Y1val == HIGH) {  
     Serial.begin(115200);      
    Serial.println("$J=G21G91X0.1Y0.1F1000");
     Serial.println("?");
     Serial.end();
  }

  else if (X2val == HIGH && Y2val == HIGH) {        
    Serial.begin(115200); 
    Serial.println("$J=G21G91X-0.1Y-0.1F1000");
    Serial.println("?");
    Serial.end();
  }

  else if (X1val == HIGH && Y2val == HIGH) {        
    Serial.begin(115200); 
    Serial.println("$J=G21G91X0.1Y-0.1F1000");
    Serial.println("?");
    Serial.end();
  }

  else if (X2val == HIGH && Y1val == HIGH) {        
    Serial.begin(115200); 
    Serial.println("$J=G21G91X-0.1Y0.1F1000");
    Serial.println("?");
    Serial.end();
  }
  
  else if (X1val == HIGH) {        
    Serial.begin(115200); 
    Serial.println("$J=G21G91X0.1F1000");
    Serial.println("?");
    Serial.end();
  }

  else if (X2val == HIGH) {     
    Serial.begin(115200);    
    Serial.println("$J=G21G91X-0.1F1000");
    Serial.println("?");
    Serial.end();
  }

  else if (Y1val == HIGH) {    
    Serial.begin(115200);     
    Serial.println("$J=G21G91Y0.1F1000");
    Serial.println("?");
    Serial.end();
  }

  else if (Y2val == HIGH) {    
    Serial.begin(115200);     
    Serial.println("$J=G21G91Y-0.1F1000");
    Serial.println("?");
    Serial.end();
  }

  else if (Z1val == HIGH) {    
    Serial.begin(115200);     
    Serial.println("$J=G21G91Z0.1F500");
    Serial.println("?");
    Serial.end();
  }

  else if (Z2val == HIGH) {     
    Serial.begin(115200);    
    Serial.println("$J=G21G91Z-0.1F500");
    Serial.println("?");
    Serial.end();
  }

  else if (T8val == HIGH) { 
    Serial.begin(115200); 
     Serial.println("$X");
     Serial.println("?");
     Serial.end();
  }


   
    delay(50);
    setup();
    exit;

}

