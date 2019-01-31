
#include <Servo.h>
Servo myservo;
int potpin = A0;
int val;
void setup()
{
  Serial.begin(9600);
 pinMode(potpin,INPUT);
myservo.attach(9);
}
void loop()
{
  
    val = analogRead(potpin);
    Serial.println(val);
 

         
         
val = sedd(val, 0, 1016, 0, 179); 
         
         
myservo.write(val);    
         
delay(15);      
}
long sedd(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
