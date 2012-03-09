int blinkState=0;
int lastBlinkState=0;

const int ledPin=13;
const int relayPin=12;

int light = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  
}

void loop(){
  if(Serial.available()>0){
    unsigned char info = Serial.read();
    //byte info= Serial.read();
    // String info = Serial.read();
    //Serial.println(info);
    
   digitalWrite(ledPin, HIGH);
   delay(100);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
/*
  blinkState=0;}
  
  if(blinkState!=lastBlinkState){
   if(blinkState=1){
   
   // delay(100);
    Serial.println("on");
    light = 1;
   }
  else{
    blinkState=0;
    light = 0;
   
    Serial.println("off");
  }
  
}
 
lastBlinkState=blinkState;
digitalWrite(ledPin, light);
}

//if you use xbee shield - keep it clicked on USB cause you are using USB
*/
