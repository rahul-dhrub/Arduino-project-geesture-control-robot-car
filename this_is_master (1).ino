
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

int state = 0;
int pot1=0,pot2=0,pot3=0,pot4=0;
void setup() 
{
 Serial.begin(9600);
  BTSerial.begin(38400);
  //pinMode(ledPin, OUTPUT);
  //digitalWrite(ledPin, LOW);
  //digitalWrite(buttonPin, HIGH);
}

void loop()
{
 /*if(BTSerial.available() > 0)
 { 
    // Checks whether data is comming from the serial port
    state = BTSerial.read(); // Reads the data from the serial port
 } */
 char s;
 pot1 = analogRead(A0);
 pot2=analogRead(A1);
  pot3=analogRead(A2);
   pot4=analogRead(A3);
   if(pot1>600&&pot1<=620)
     BTSerial.write('a');
   else if(pot1>620&&pot1<=640)
     BTSerial.write('b');
   else if(pot1>640&&pot1<=660)
     BTSerial.write('c');
   else if(pot1>660&&pot1<=680)
     BTSerial.write('d');
   else if(pot1>680)
     BTSerial.write('e');

     
   if(pot2>600&&pot2<=620)
     BTSerial.write('f');
   else if(pot2>620&&pot2<=640)
     BTSerial.write('g');
   else if(pot2>640&&pot2<=660)
     BTSerial.write('h');
   else if(pot2>660&&pot2<=680)
     BTSerial.write('i');
   else if(pot2>680)
     BTSerial.write('j');

   if(pot3>600&&pot3<=620)
     BTSerial.write('k');
   else if(pot3>620&&pot3<=640)
     BTSerial.write('l');
   else if(pot3>640&&pot3<=660)
     BTSerial.write('m');
   else if(pot3>660&&pot3<=680)
     BTSerial.write('n');
   else if(pot3>680)
     BTSerial.write('o');

   if(pot4>600&&pot4<=620)
     BTSerial.write('p');
   else if(pot4>620&&pot4<=640)
     BTSerial.write('q');
   else if(pot4>640&&pot4<=660)
     BTSerial.write('r');
   else if(pot4>660&&pot4<=680)
     BTSerial.write('s');
   else if(pot4>680)
     BTSerial.write('t');
  if(pot1<600&&pot2<600&&pot3<600&&pot4<600)
   {
       BTSerial.write('z');
   }

   Serial.println(pot1);
   Serial.println(pot2);
   Serial.println(pot3);
   Serial.println(pot4);

delay(100);
}
