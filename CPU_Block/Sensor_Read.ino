//int sensorPin = A0; // Analog sensor
int sensorPin = 2; // Digital sensor
int sensorValue = 0;

void setup(){
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}

void loop (){
  //sensorValue = analogRead(sensorPin); // Analog read
  sensorValue = digitalRead(sensorPin); // Digital read
  Serial.println (sensorValue);
}
