#define frontLeftSensor A0
#define frontRightSensor A1
#define rearLeftSensor A2
#define rearRightSensor A3
#define ENA 5  // PWM Pin for Left Motor
#define ENB 6  // PWM Pin for Right Motor
#define M11 7  // Left Motor Pin 1
#define M12 8  // Left Motor Pin 2
#define M21 9  // Right Motor Pin 1
#define M22 10 // Right Motor Pin 2

void setup() {
  pinMode(frontLeftSensor, INPUT);
  pinMode(frontRightSensor, INPUT);
  pinMode(rearLeftSensor, INPUT);
  pinMode(rearRightSensor, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int frontLeftSensorValue = digitalRead(frontLeftSensor);
  Serial.print(frontLeftSensorValue);
  Serial.print('\t');
  int frontRightSensorValue = digitalRead(frontRightSensor);
  Serial.print(frontRightSensorValue);
  Serial.print('\t');
  int rearLeftSensorValue = digitalRead(rearLeftSensor);
  Serial.print(rearLeftSensorValue);
  Serial.print('\t');
  int rearRightSensorValue = digitalRead(rearRightSensor);
  Serial.println(rearRightSensorValue);
  
  // GO FORWARD IF ALL SENSORS DETECT SURFACE BELOW
  if(frontLeftSensorValue == 1 && frontRightSensorValue == 1 && rearLeftSensorValue == 1 && rearRightSensorValue == 1) {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
  }

  // GO FORWARD AND TURN LEFT IF REAR-RIGHT SENSOR DETECTS CLIFF
  if(frontLeftSensorValue == 1 && frontRightSensorValue == 1 && rearLeftSensorValue == 1 && rearRightSensorValue == 0) {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
    delay(1000);
    digitalWrite(M11, 0);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
    delay(1100);
  }

  //  GO FORWARD AND TURN RIGHT IF REAR-LEFT SENSOR DETECTS CLIFF
  if(frontLeftSensorValue == 1 && frontRightSensorValue == 1 && rearLeftSensorValue == 0 && rearRightSensorValue == 1) {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
    delay(1000);
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 0);
    digitalWrite(M22, 0);
    delay(1100);
  }

  //  GO FORWARD IF REAR SENSORS DETECT CLIFF
  if(frontLeftSensorValue == 1 && frontRightSensorValue == 1 && rearLeftSensorValue == 0 && rearRightSensorValue == 0) {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
    delay(1000);
  }

  // GO REVERSE AND TURN LEFT IF FRONT-RIGHT SENSOR DETECTS CLIFF
  if(frontLeftSensorValue == 1 && frontRightSensorValue == 0 && rearLeftSensorValue == 1 && rearRightSensorValue == 1) {
    digitalWrite(M11, 0);
    digitalWrite(M12, 1);
    digitalWrite(M21, 0);
    digitalWrite(M22, 1);
    delay(1000);
    digitalWrite(M11, 0);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
    delay(1100);
  }

  //  GO REVERSE AND TURN RIGHT IF FRONT-LEFT SENSOR DETECTS CLIFF
  if(frontLeftSensorValue == 0 && frontRightSensorValue == 1 && rearLeftSensorValue == 1 && rearRightSensorValue == 1) {
    digitalWrite(M11, 0);
    digitalWrite(M12, 1);
    digitalWrite(M21, 0);
    digitalWrite(M22, 1);
    delay(1000);
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 0);
    digitalWrite(M22, 0);
    delay(1100);
  }

  //  GO REVERSE IF FRONT SENSORS DETECT CLIFF
  if(frontLeftSensorValue == 0 && frontRightSensorValue == 0 && rearLeftSensorValue == 1 && rearRightSensorValue == 1) {
    digitalWrite(M11, 0);
    digitalWrite(M12, 1);
    digitalWrite(M21, 0);
    digitalWrite(M22, 1);
    delay(1000);
  }
}
