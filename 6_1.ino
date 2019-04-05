int button1 = 6;
int button2 = 2;
int led=3;
int state1=0,state2=0,state3=1;
int val=0;
int i=0;
unsigned long int a[100];
unsigned long int start;
unsigned long int finish;
int on=0;
int off=0;


void setup() {
  // put your setup code here, to run once:
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int one=digitalRead(button1);
  int two;
  if(one==HIGH){ 
   digitalWrite(13,HIGH);
   
    if(state1==0){
      val=!val;  
      i=i+2;
//      for(int j=0;j<i;j++)
//      {
//        Serial.println(a[j]);   
//      }
    }
    state1=1;
  }
  else{
    digitalWrite(13,LOW);
    state1=0;
  }

  if(val){   
//    Serial.println(val);
      
   

      
  }

}
