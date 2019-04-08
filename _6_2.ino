int led=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0);
  String n= Serial.readStringUntil('\n');
  Serial.println(n); 
  int level;

  if(n=="one")
  {
    level=255/5;
  }
  else if(n=="two")
  {
    level=(255/5)*2;
  }
  else if(n=="three")
  {
    level=(255/5)*3;
  }
  else if(n=="four")
  {
    level=(255/5)*4;
  }
  else 
  {
    level=255;
  }
  Serial.println(level);
  analogWrite(led,level);    
  
}
  
