#include <SoftwareSerial.h>
SoftwareSerial BT(5, 6); //TX, RX respetively
int statePin = 2;
///////////////////////////////////////////////////////////////
#define leftSensor A0
#define rightSensor A3
///////////////////////////////////////////////////////////////
#define M11 7  // Left Motor Pin 1
#define M12 8  // Left Motor Pin 2
#define M21 9  // Right Motor Pin 1
#define M22 10 // Right Motor Pin 2
///////////////////////////////////////////////////////////////

void setup() 
{
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(statePin,INPUT);
  ///////////////////////////////////////////////////////////////
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
}

void loop() 
{
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //                                           Teleoperated Robot                                                 //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int statePinValue = digitalRead(statePin);
  //Serial.println(statePinValue);

  if (statePinValue == 1)
  {
    while (BT.available())     //Check if there is an available byte to read
    {                       
      delay(10);              //Delay added to make communication stable
      char b = BT.read();     //Define BT read character
      
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
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //                                           Light Follower Robot                                               //
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  else
  {
    int leftSensorValue = analogRead(leftSensor);
    Serial.print(leftSensorValue);
    Serial.print('\t');
    int rightSensorValue = analogRead(rightSensor);
    Serial.println(rightSensorValue);
  
    // GO STRAIGHT IF BOTH SENSORS ARE ALMOST EQUAL
    if((leftSensorValue - rightSensorValue) < 50 || (rightSensorValue - leftSensorValue) < 50){
      digitalWrite(M11, 1);
      digitalWrite(M12, 0);
      digitalWrite(M21, 1);
      digitalWrite(M22, 0);
    }
  
    // TURN LEFT IF LEFT SENSOR GETS MORE LIGHT
    if((rightSensorValue - leftSensorValue) > 50) {
      digitalWrite(M11, 0);
      digitalWrite(M12, 0);
      digitalWrite(M21, 1);
      digitalWrite(M22, 0);
    }
  
    // TURN RIGHT IF RIGHT SENSOR GETS MORE LIGHT
    if((leftSensorValue - rightSensorValue) > 50) {
      digitalWrite(M11, 1);
      digitalWrite(M12, 0);
      digitalWrite(M21, 0);
      digitalWrite(M22, 0);
    }
  }
}
