#define leftSensor A0
#define rightSensor A1
#define ENA 5  // PWM Pin for Left Motor
#define ENB 6  // PWM Pin for Right Motor
#define M11 7  // Left Motor Pin 1
#define M12 8  // Left Motor Pin 2
#define M21 9  // Right Motor Pin 1
#define M22 10 // Right Motor Pin 2

void setup() {
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leftSensorValue = digitalRead(leftSensor);
  Serial.print(leftSensorValue);
  Serial.print('\t');
  int rightSensorValue = digitalRead(rightSensor);
  Serial.println(rightSensorValue);
  
  // GO STRAIGHT IF BOTH SENSORS ARE ON WHITE
  if(leftSensorValue == 1 && rightSensorValue ==1) {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
  }

  // TURN LEFT IF LEFT SENSOR DETECTS BLACK
  if(leftSensorValue == 0 && rightSensorValue ==1) {
    digitalWrite(M11, 0);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
  }

  // TURN RIGHT IF RIGHT SENSOR DETECTS BLACK
  if(leftSensorValue == 1 && rightSensorValue ==0) {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 0);
    digitalWrite(M22, 0);
  }
}
