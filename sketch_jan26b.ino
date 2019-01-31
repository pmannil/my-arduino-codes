#include<ctype.h>
#include<string.h>


unsigned long previousMillis[3]; 
int ledpin1=3;
int ledpin2=5;
int ledpin3=10;
String level;
String level1;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin1,OUTPUT);
pinMode(ledpin2,OUTPUT);
pinMode(ledpin3,OUTPUT);
}
  void loop() {
  if(Serial.available()>0)
  {
   level=Serial.readStringUntil('\n');
   Serial.println(level);
 
  }
  int isDigit1 = 0;
  int isDigit2 = 0;
  int isDigit3 = 0;
 
  int j=0;
while(j<level.length()){
  if(level.charAt(j) <= 57 && level.charAt(j)>= 48 )
  {
    isDigit3 = 1;
    
    
    
  }
  else if(level.charAt(j)<= 122 && level.charAt(j)>= 65)
  {
    isDigit1 = 1;
    
    
    
  }
  else 
  {
    isDigit2=1;
    
    
  }
  j++;
  //Serial.print(1);
}

   if(isDigit3==1&&isDigit1==0&&isDigit2==0)
  {
    Serial.println("itsnumber");
    Serial.println(level);
    
    BlinkLed(ledpin1, 1000, 0);
  }
  
  else if(level.length()>=5 && isDigit1==1 && isDigit2==0 && isDigit3==0 )
  {
    Serial.println("hi");
    Serial.println(level);
    BlinkLed(ledpin2, 1000, 1);
  }
  else if(isDigit1==1 || isDigit2==1 || isDigit3==1)
  {
    Serial.println("hello");
    Serial.println(level);
    BlinkLed(ledpin3, 1000, 2);
    
  }
 
 
}

void BlinkLed (int led, int interval, int array){   
  
 
   if ((millis() - previousMillis[array]) >= interval){ 
   
    previousMillis[array]= millis(); 
   
    digitalWrite(led, !digitalRead(led)); 
  }
 }
