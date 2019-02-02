const int  buttonPin = 2;
const int led3 = 9;  
const int led1 = 3; 
const int led2 = 5; 
int buttonPushCounter = 0;   
boolean buttonState = LOW;         
boolean lastButtonState = LOW;  
int state=1;



void setup() {
 
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);

}
boolean debounce( boolean last)
{
  boolean current =digitalRead(buttonPin);
  if(last!=current)
  {
    delay(100);
    current=digitalRead(buttonPin);
  }
  return current;
  
}

void loop() {
  
  
  buttonState = debounce(lastButtonState);
   if (buttonState == HIGH && state==1) {
      state=0;
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } 
    else if (buttonState==LOW && state==0) {
       state=1;
      //Serial.println("off");
    }
    //lastButtonState = buttonState;
    
    if(buttonPushCounter==8)
    {
      buttonPushCounter=0;
    }
    
  
  if (buttonPushCounter==0) {
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
  }
   else if (buttonPushCounter==1) {
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,HIGH);
  }
   else if (buttonPushCounter==2) {
   digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,LOW);
  } 
   else if (buttonPushCounter==3) {
   digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);
  }
   else if (buttonPushCounter==4) {
   digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
  }
   else if (buttonPushCounter==5) {
   digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
   digitalWrite(led3,HIGH);
  }
   else if (buttonPushCounter==6) {
   digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,LOW);
  }
  else if (buttonPushCounter==7) {
   digitalWrite(led1,HIGH);
   digitalWrite(led2,HIGH);
   digitalWrite(led3,HIGH);

  }
}
