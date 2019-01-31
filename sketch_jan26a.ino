int period = 10000;
unsigned long time_now = 0;
int led1 =5;
unsigned long previousMillis;
int delay1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0)
  {
  
   delay1=(Serial.readStringUntil('\n')).toInt();
  }
  BlinkLed(led1,delay1);
 if(millis()-time_now >= period)
  {
   time_now=millis();
   Serial.println(delay1);
  }
  

}
void BlinkLed (int led, int interval){   
  
 
   if ((millis() - previousMillis) >= interval){ 
  
    previousMillis= millis(); 
   
    digitalWrite(led, !digitalRead(led)); 
  }
}
