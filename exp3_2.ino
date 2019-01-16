
unsigned long previousMillis[3]; 
int led1=3;
int led2=5;
int led3=9;

void setup() { 
  pinMode(led1, OUTPUT);   
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop() {
 BlinkLed(led1, 10, 0);   
 BlinkLed(led2, 100, 1);
 BlinkLed(led3, 1000, 2);
 
 
}

void BlinkLed (int led, int interval, int array){   
  
 
   if ((millis() - previousMillis[array]) >= interval){ 
   
    previousMillis[array]= millis(); 
   
    digitalWrite(led, !digitalRead(led)); 
  }
 }
