#include <SoftwareSerial.h>
SoftwareSerial BT(5, 6); //TX, RX respetively

void setup() {
Serial.begin(9600);
BT.begin(9600);

pinMode(7,OUTPUT);    // RIGHT MOTOR 1
pinMode(8,OUTPUT);    // RIGHT MOTOR 2
pinMode(9,OUTPUT);    // LEFT MOTOR 1
pinMode(10,OUTPUT);    // LEFT MOTOR 2
}

void loop() {
while (BT.available()){                       //Check if there is an available byte to read
delay(10);                                    //Delay added to make communication stable
char b = BT.read();                           //Define BT read character

if(b=='w'){
  Serial.println("ROBOT IS MOVING FORWARD");                // FORWARD
  BT.println("ROBOT IS MOVING FORWARD");
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  
}

if(b=='s'){
  Serial.println("ROBOT IS MOVING BACKWARD");                // BACKWARD
  BT.println("ROBOT IS MOVING BACKWARD");
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}

if(b=='d'){
  Serial.println("ROBOT IS TAKING RIGHT TURN");               // RIGHT
  BT.println("ROBOT IS TAKING RIGHT TURN");
  digitalWrite (7,HIGH);
  digitalWrite (8,LOW);
  digitalWrite (9,LOW);
  digitalWrite (10,LOW);
}

if(b=='a'){
  Serial.println("ROBOT IS TAKING LEFT TURN");                // LEFT
  BT.println("ROBOT IS TAKING LEFT TURN");
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  digitalWrite (9,HIGH);
  digitalWrite (10,LOW);
}

if(b=='x'){
  Serial.println("ROBOT HAS STOPPED");                        // STOP
  BT.println("ROBOT HAS STOPPED");
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  digitalWrite (9,LOW);
  digitalWrite (10,LOW);  
}
b="";                                                         //Reset the variable
}





while (Serial.available()){                   //Check if there is an available byte to read
delay(10);                                    //Delay added to make communication stable
char s = Serial.read();                       //Define BT read character

if(s=='w'){
  Serial.println("ROBOT IS MOVING FORWARD");                // FORWARD
  BT.println("ROBOT IS MOVING FORWARD");
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  
}

if(s=='s'){
  Serial.println("ROBOT IS MOVING BACKWARD");                // BACKWARD
  BT.println("ROBOT IS MOVING BACKWARD");
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
}

if(s=='d'){
  Serial.println("ROBOT IS TAKING RIGHT TURN");               // RIGHT
  BT.println("ROBOT IS TAKING RIGHT TURN");
  digitalWrite (7,HIGH);
  digitalWrite (8,LOW);
  digitalWrite (9,LOW);
  digitalWrite (10,LOW);
}

if(s=='a'){
  Serial.println("ROBOT IS TAKING LEFT TURN");                // LEFT
  BT.println("ROBOT IS TAKING LEFT TURN");
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  digitalWrite (9,HIGH);
  digitalWrite (10,LOW);
}

if(s=='x'){
  Serial.println("ROBOT HAS STOPPED");                        // STOP
  BT.println("ROBOT HAS STOPPED");
  digitalWrite (7,LOW);
  digitalWrite (8,LOW);
  digitalWrite (9,LOW);
  digitalWrite (10,LOW);  
}
s="";                                                         //Reset the variable
}
}
