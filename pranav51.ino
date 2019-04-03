const int  buttonPin1 = 2;
const int  buttonPin2 = 4;
const int led3 = 8;  
const int led1 = 3; 
const int led2 = 5; 
boolean button1 = LOW;
boolean button2 = LOW;         
boolean last1 = LOW;
boolean last2 = LOW;
//int state1=1;
//int state2=2;    
void setup() {
 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);

  Serial.begin(9600);
}
boolean debounce( boolean last,const int pin)
{
  boolean current =digitalRead(pin);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(pin);
  }
  return current;
  
}

void loop() {


      digitalWrite(led3,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led1,HIGH);
  
  button1 = debounce(last1,buttonPin1);
  button2 = debounce(last2,buttonPin2);
  Serial.println(button1);
  Serial.println(button2);
  
  

  if(button1==HIGH && button2==LOW )
  {
    
    if(led1==HIGH)
    {
      digitalWrite(led3,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led1,LOW);
    }
    else if(led2==HIGH)
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
    }
    else
    {
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led1,LOW);
    }
   last1=button1;
  }
  else if(button2==HIGH && button1==LOW )
  {
    
    if(led1==HIGH)
    {
      digitalWrite(led2,HIGH);
      digitalWrite(led3,LOW);
      digitalWrite(led1,LOW);
    }
    else if(led2==HIGH)
    {
      digitalWrite(led3,HIGH);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
    }
    else
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led3,HIGH);
    }
    last2=button2;
  } 
    
      
    }
  
