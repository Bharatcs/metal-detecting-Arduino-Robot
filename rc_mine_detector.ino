int LF=10;//left L293+
int LB=9; //left L293-           
int RF=12;//right L293+
int RB=11;//right l293-
int A=7;
int B=6;
int C=5;
int D=4;                   //PIN numbers from serial to parallel converter connected to pins 7,6,5,4 from HT12D 
                           //HT12D is connected to an RF module
boolean w,x,y,z;

void setup()
{pinMode(LF,OUTPUT);  //motor l293 
 pinMode(LB,OUTPUT);
 pinMode(RF,OUTPUT);
 pinMode(RB,OUTPUT);
 pinMode(A,INPUT);            //ht12d
 pinMode(B,INPUT);
 pinMode(C,INPUT);
 pinMode(D,INPUT);
}
void loop()
{
  w=digitalRead(A);
  x=digitalRead(B);
  y=digitalRead(C);
  z=digitalRead(D);
  if((w==0)&&(x==1)&&(y==1)&&(z==1))
  up();
  if((w==1)&&(x==0)&&(y==1)&&(z==1))
  down();
  if((w==1)&&(x==1)&&(y==0)&&(z==1))
  left();
  if((w==1)&&(x==1)&&(y==1)&&(z==0))
  right();
  else
  wait();
}
void up()
{digitalWrite(RF,HIGH);            //forward
 digitalWrite(RB,LOW);
 digitalWrite(LF,HIGH);
 digitalWrite(LB,LOW);
 delay(500);

}
  
void down()
{digitalWrite(RF,LOW);                   //back
 digitalWrite(RB,HIGH);
 digitalWrite(LF,LOW);
 digitalWrite(LB,HIGH);
 delay(500);
}
  
void left()
{digitalWrite(RF,HIGH);                   //left
 digitalWrite(RB,LOW);
 digitalWrite(LF,LOW);
 digitalWrite(LB,HIGH);
 delay(500);
}
 void right()
 {digitalWrite(RF,LOW);                    //right
 digitalWrite(RB,HIGH);
 digitalWrite(LF,HIGH);
 digitalWrite(LB,LOW);
 delay(500);
 }
 void wait()
 {digitalWrite(RF,LOW);
 digitalWrite(RB,LOW);
 digitalWrite(LF,LOW);
 digitalWrite(LB,LOW);
 delay(500);
 }
