//unsigned long now = 0;
#include<string.h>
unsigned long previousMillis[3];
int led1 = 3;
int led2 = 5;
int led3 = 9;

String str;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}


void loop()
{
  int i=0;
  int k=0;
  String b[6];
  char a[100];
  if(Serial.available()>0)
  {
  str=Serial.readStringUntil('\n');
  }
  str.toCharArray(a,100);
  while(i!=str.length())
  {
    if(a[i]==' ')
    {
    b[k]=b[k]+a[i];
    k++;
    i++;
    }
    else
    {
      b[k]=b[k]+a[i];
      i++;
    }
    
    
  }
  


BlinkLed(led1,b[1].toInt(),0);
BlinkLed(led2,b[3].toInt(),1);
BlinkLed(led3,b[5].toInt(),2);
}


 


void BlinkLed (int led, int interval, int array1) {

  Serial.println(interval);

  if ((millis() - previousMillis[array1]) >= interval) {

    previousMillis[array1] = millis();

    digitalWrite(led, !digitalRead(led));

  }
}
