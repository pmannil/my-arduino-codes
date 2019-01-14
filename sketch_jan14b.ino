int ledpin=5;
int ldrpin=A0;
int value=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
pinMode(ldrpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(ldrpin);
  value=constrain(value,0,100);
  value=map(value,0,100,255,0);
 analogWrite(ledpin,value);
 Serial.println(value);
  
 
  

}
