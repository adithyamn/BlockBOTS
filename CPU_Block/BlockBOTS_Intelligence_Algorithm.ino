//   2         pin1
// 3  6     pin2  pin3
// 4  5     pin4  pin5

#include <SoftwareSerial.h>
SoftwareSerial BT(10,11); // (Tx,Rx)

int Pin1 = 2;
int Pin2 = 3;
int Pin3 = 4;
int Pin4 = 5;
int Pin5 = 6;

void setup() 
{
Serial.begin(9600);
BT.begin(9600);

pinMode(pin1, INPUT)
pinMode(pin2, INPUT);
pinMode(pin3, INPUT);
pinMode(pin4, INPUT);
pinMode(pin5, INPUT);
}

void loop() 
{

pin1 = digitalRead(Pin1);
pin2 = digitalRead(Pin2);
pin3 = digitalRead(Pin3);
pin4 = digitalRead(Pin4);
pin5 = digitalRead(Pin5);

///////////////////////////////////////////////////////////////////////////////

if (pin1 == 1)
{
  mode = "Obstacle Avoider";
}
///////////////////////////////////////////////////////////////////////////////

if (pin1 == 0)
{
  mode = "Sound Reactor";
}
///////////////////////////////////////////////////////////////////////////////

if (pin2 == 1 && pin5 == 1)
{
  mode = "Line Follower";
}
///////////////////////////////////////////////////////////////////////////////

else if (pin2 == 0 && pin5 == 0)
{
  mode = "Light Follower";
}
///////////////////////////////////////////////////////////////////////////////

else if (pin2 == 1 && pin5 == 1 && pin3 == 1 && pin4 == 1)
{
  mode = "Edge Avoider";
}
///////////////////////////////////////////////////////////////////////////////

else if (BT.available())
{
  mode = "Teleoperation";
}
///////////////////////////////////////////////////////////////////////////////

else
{
  mode = "Idle";
  Serial.println("Invalid Configuration");
}
///////////////////////////////////////////////////////////////////////////////

Serial.println(mode);

delay(5);

}
