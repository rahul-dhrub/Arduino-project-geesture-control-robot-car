//Tutorial by RoboIndia on Motor Control
//Hardware Require: Motor Driver(By RoboIndia) & Arduino
#include <SoftwareSerial.h>
#include"NewPing.h"
SoftwareSerial BTSerial(1, 0);
#define max_dis 200
//Motor A
const int inputPin1  = 10;    // Pin 15 of L293D IC
const int inputPin2  = 2;    // Pin 10 of L293D IC
//Motor B
const int inputPin3  = 9;   // Pin  7 of L293D IC
const int inputPin4  = 8;   // Pin  2 of L293D IC
const int inputPin5  = 3;  
const int inputPin6  = 5; 
//////
//const int flexPin1 = A0; 
//const int flexPin2 = A1;
int value1,value2; 
//////
int speedcar=250;
static int command;
char c=' ';
//-------------------------------------//
const int trigPin1=  6;
const int echoPin1 = A0;///1
const int trigPin2 = A2;
const int echoPin2 = A3;////2
const int trigPin3 = A4;
const int echoPin3 = A5;///3
const int trigPin4 = A1;
const int echoPin4 = 11;///4
//long duration1;
int distance1;
//long duration2;
int distance2;
//long duration3;
int distance3;
//long duration4;
int distance4;
NewPing sonar1(trigPin1,echoPin1,max_dis);
NewPing sonar2(trigPin2,echoPin2,max_dis);
NewPing sonar3(trigPin3,echoPin3,max_dis);
NewPing sonar4(trigPin4,echoPin4,max_dis);

void setup() 
{
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);
    pinMode(inputPin5, OUTPUT);
     pinMode(inputPin6, OUTPUT);
     BTSerial.begin(38400); 
     ///----------------------------------//
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT); //1
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT); //2
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT); //3
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT); //4
//Serial.begin(9600); 
    
}

void moveforward()
{
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH);
    analogWrite(inputPin6, speedcar);
}

void moveback()
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);
    analogWrite(inputPin6, speedcar);
}

void goright_forward()
{
     digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);
    analogWrite(inputPin6, speedcar);
}

void goright_back()
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);
    analogWrite(inputPin6, speedcar);
}

void goleft_forward()
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH);
    analogWrite(inputPin6, speedcar);
}
void goleft_back()
{
   digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);
    analogWrite(inputPin6, speedcar);
}
void stopRobot()
{
  digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    analogWrite(inputPin5, speedcar);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);
    analogWrite(inputPin6, speedcar);
}

void loop() 
{
  if(BTSerial.available()> 0)
 { 
    // Checks whether data is comming from the serial port                                                                                                                                
    c = BTSerial.read(); // Reads the data from the serial port
   // Serial.write(state);
 }
 distance1=sonar1.ping_cm();
 distance2=sonar2.ping_cm();
 distance3=sonar3.ping_cm();
 distance4=sonar4.ping_cm();
/* delay(500);
 Serial.println(distance1);
 Serial.println(distance2);
 Serial.println(distance3);
 Serial.println(distance4);
 Serial.println("mannn");
 delay(500);*/
 
 
 /* if((distance1<=25&&distance2<=25&&distance1!=0&&distance2!=0)||distance3<=25)
  {
    stopRobot();
  }*/
//else 
//{
   if(c=='a')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
    {
      stopRobot();
    }
    else
    {
      speedcar=50;
      moveforward();  
    }
   }
  else if(c=='b')
   {
      if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
     
      }
      else
      {
      speedcar=100;
      moveforward();  
      }
   }
    else if(c=='c')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      stopRobot();
      else{
      speedcar=150;
      moveforward();  
      }
   }
    else if(c=='d')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      }
      else
      {
      speedcar=200;
      moveforward();  
      }
   }
    else if(c=='e')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
     
      }
      else
      {
      speedcar=250;
      moveforward();
      }  
   }
   else if (c=='f')
   {
       if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
       {
      stopRobot();
      
      }
      else{
         speedcar=50;
        goleft_forward();
      }
   }
   else if (c=='g')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
     {
      stopRobot();
     
      }  
      else{   
         speedcar=100;
        goleft_forward();
      }
   }
   else if (c=='h')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      
      }
      else{
         speedcar=150;
        goleft_forward();
      }
   }else if (c=='i')
   {
    if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
    
      }
      else{
         speedcar=200;
        goleft_forward();
      }
   }
   else if (c=='j')
   {
     if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      
      }
      else{
         speedcar=250;
        goleft_forward();
      }
   }
    else if (c=='k')
    {
      if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      }
      else{
       speedcar=50;
         goright_forward();
      }
        
    }
      else if (c=='l')
    {
      if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      
      }
      else{
       speedcar=100;
         goright_forward();
      }
        
    }  
    else if (c=='m')
    {
       if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      
      }
      else{
       speedcar=150;
         goright_forward();
      }
        
    } 
    else if (c=='n')
    {
       if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
      {
      stopRobot();
      
      }
      else
      {
       speedcar=200;
         goright_forward();
      }
    }
     else if (c=='o')
    {
      if((distance3<15||distance4<15)&&distance3!=0&&distance4!=0)
       {
      stopRobot();
      
      }
      else{
       speedcar=250;
         goright_forward();
      }
    }
    else if(c=='p')
   {
    if((distance1<15||distance2<15)&&distance1!=0&&distance2!=0)
         {
      stopRobot();
      
      }
      else{
        speedcar=50; 
        moveback();
      }
    }
    else if(c=='q')
   {
        if(distance1<15||distance2<15&&distance1!=0&&distance2!=0)
        stopRobot();
        else{
        speedcar=100; 
        moveback();
        }
    }
      else if(c=='r')
   {
        if((distance1<15||distance2<15)&&distance1!=0&&distance2!=0)
        {
      stopRobot();
      
      }
      else{
        speedcar=150; 
        moveback();
      }
    }
      else if(c=='s')
   {
    if((distance1<15||distance2<15)&&distance1!=0&&distance2!=0)
         {
      stopRobot();
      }
      else{
        speedcar=200; 
        moveback();
      }
    }
      else if(c=='t')
   {
    if((distance1<15||distance2<15)&&distance1!=0&&distance2!=0)
         {
      stopRobot();
       
      }
      else{
        speedcar=250; 
        moveback();
      }
    }
    else  if(c=='z')
         stopRobot();
//}
}
