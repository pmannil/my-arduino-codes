const int buttonPin = 6;
const int button2=2;    
const int ledPin = 4; 
const int led2=3  ;   
int state1=0,i=0,state2=0,state3=0;



int ledState = LOW;         
int buttonState;             
int lastButtonState = LOW;   

int ledState2 = LOW;         
int buttonState2;             
int lastButtonState2 = LOW; 

unsigned long lastDebounceTime = 0;  
unsigned long lastDebounceTime2 =0;
unsigned long debounceDelay = 50;  
unsigned long on=0;
unsigned long off=0; 
unsigned long a[100]; 

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(button2,INPUT);
  Serial.begin(9600);
//  digitalWrite(ledPin, ledState);
}

void loop() {

  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;
        if(ledState==HIGH)
        {
          off=millis();
        }
      }
    }
  }

  
  if(ledState){
     int reading2 = digitalRead(button2);
  
     if (reading2 != lastButtonState2) {
      lastDebounceTime2 = millis();     
      }

    if ((millis() - lastDebounceTime2) > debounceDelay) {
      if (reading2 != buttonState2) {
        buttonState2 = reading2;

        if (buttonState2 == HIGH) {
          digitalWrite(led2,buttonState2);
          on=millis();
          Serial.println("off :");
          a[i]=millis()-off;
          Serial.println(a[i]);
          i++;
          state1=1;
        }

        if(buttonState2 ==LOW){
          digitalWrite(led2,buttonState2);
          off=millis();
          Serial.println("on :");
          a[i]=millis()-on;
          Serial.println(a[i]);
          i++;
          state1=0;
                                  
        }
      }
    }


  lastButtonState2 = reading2;  
  state2=0;  
  }

  if(!ledState && state2==0){
   // digitalWrite(ledPin,ledState);
    for(int j=0;j<i;j++)
    {
      Serial.println(a[j]);
      for(int k=0;k<a[j];k++)
      {
        digitalWrite(led2,state3);
        delay(1);
        //Serial.print(k);        
      }
      state3=!state3;
    }
    state2=1;
    digitalWrite(led2,LOW);
    i=0;
    //off=millis();
  }

  
  digitalWrite(ledPin,ledState);
  lastButtonState = reading;
}
