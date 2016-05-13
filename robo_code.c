int motor1p = 2;
int motor1n = 4;
int motor2p = 7;
int motor2n = 8;
int i;
void forward();
void back();
void left();
void right();
void back_left();
void back_right();
void robo_stop();


void forward()
{
  digitalWrite(motor1n,LOW);
  digitalWrite(motor1p,HIGH);
  digitalWrite(motor2n,LOW);
  digitalWrite(motor2p,HIGH);
}

void back()
{
  digitalWrite(motor1p,LOW);
  digitalWrite(motor1n,HIGH);
  digitalWrite(motor2p,LOW);
  digitalWrite(motor2n,HIGH);
}
void left()
{
  digitalWrite(motor1n,LOW);
  digitalWrite(motor1p,LOW);
  digitalWrite(motor2n,LOW);
  digitalWrite(motor2p,HIGH);
}
void right()
{
  digitalWrite(motor1n,LOW);
  digitalWrite(motor1p,HIGH);
  digitalWrite(motor2n,LOW);
  digitalWrite(motor2p,LOW);
}

void turnright()
{
  digitalWrite(motor1n,LOW);
  digitalWrite(motor1p,HIGH);
  digitalWrite(motor2n,HIGH);
  digitalWrite(motor2p,LOW);
}
  
void turnleft()
{
   digitalWrite(motor1n,HIGH);
  digitalWrite(motor1p,LOW);
  digitalWrite(motor2n,LOW);
  digitalWrite(motor2p,HIGH);
}
  
void robo_stop()
{
  digitalWrite(motor1p,LOW);
  digitalWrite(motor1n,LOW);
  digitalWrite(motor2p,LOW);
  digitalWrite(motor2n,LOW);
}

void step1()
{
  forward();
  delay(500);
  robo_stop();
  delay(100);
}

void shiftright()
{
  turnright();
  delay(400);
  step1();
   turnright();
  delay(450);
}

void shiftleft()
{
  turnleft();
  delay(460);
  robo_stop();
  delay(1000);
  step1();
  turnleft();
  delay(460);
  robo_stop();
  delay(1000);
  
}

void turn180()
{
   turnleft();
  delay(820);
  robo_stop();
}

void turnl90()
{
   turnleft();
  delay(410);
  robo_stop();
}

void turnr90()
{
   turnright();
  delay(410);
  robo_stop();
}


void setup()  
{

  Serial.begin(9600);
  pinMode(motor1n,OUTPUT);
  pinMode(motor2n,OUTPUT);
  pinMode(motor1p,OUTPUT);
  pinMode(motor2p,OUTPUT);
}



void loop() 
{
  unsigned int a[4][4],m=a[0][0],x=0,y=0;
  int i=0,j=0,s1,s2,s;
  
  i=0;
  while(i<=3)
  {  
      j=0;
      while(j<=3)
  
      {
         s1=analogRead(A1);
     
         a[i][j]=s1;
         s = map(s1, 0, 1023, 0, 255); 
         Serial.print(i);
         Serial.print(j);
         Serial.println(s);
          
         step1();
         j++;
      }
      i++;
      if(i%2==1)
      {
          shiftright();
          j=3;
          while(j>=0)
          {
               s2=analogRead(A1);
               a[i][j]=s2;
               s = map(s2, 0, 1023, 0, 255);
              Serial.print(i);
              Serial.print(j);
              Serial.println(s);
               step1();
               j--;
          }
          i++;
          if(i>3)
         {
            break;
         }
         shiftleft();
       }
         robo_stop();
   }
  
  for(i=0;i<=3;i++)
  {
    for(j=0;j<=3;j++)
    {
       if(a[i][j]>m)
         { m=a[i][j];
            x=i;
            y=j;
        }
    }
  }
  
  Serial.print(" max intensity ");
  Serial.print(x);
  Serial.print(y);
      
  //turn180();  
   shiftright();
   i=3;
   j=0;
  
  while(j<=y) 
  {
     
    step1();
    j++;
  }

  while(i>=x)
  {
     step1();
     i--;
  }
  turnl90();
  
  
  delay(10000);
