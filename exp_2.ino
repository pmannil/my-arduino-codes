
int ledpin=3;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0);

  int level=(Serial.readStringUntil('\n')).toInt();
  analogWrite(ledpin,level);
  Serial.println(level);

}
