int ledpin1=3;
int ledpin2=5;
int ledpin3=6;
int ldrpin=A0;
int value=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin1,OUTPUT);
pinMode(ledpin2,OUTPUT);
pinMode(ledpin3,OUTPUT);
pinMode(ldrpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    value=analogRead(ldrpin);
    value=constrain(value,0,28);
    int level=map(value,0,28,255,0);
    Serial.println(level);

    if(level==0)
    {
      digitalWrite(ledpin1,HIGH);
      digitalWrite(ledpin2,LOW);
      digitalWrite(ledpin3,LOW);
   
    }
    else if(level==255)
    {
      digitalWrite(ledpin1,LOW);
      digitalWrite(ledpin2,HIGH);
      digitalWrite(ledpin3,LOW);
    }
    else
    {
      
      digitalWrite(ledpin1,LOW);
      digitalWrite(ledpin2,LOW);
      digitalWrite(ledpin3,HIGH);
    }
 
      



      
   
      
    

}
