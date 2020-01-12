#define soundSensor A0
#define ENA 5  // PWM Pin for Left Motor
#define ENB 6  // PWM Pin for Right Motor
#define M11 7  // Left Motor Pin 1
#define M12 8  // Left Motor Pin 2
#define M21 9  // Right Motor Pin 1
#define M22 10 // Right Motor Pin 2

int count = 4;
int previousValue = 0;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundSensorValue = digitalRead(soundSensor);
  Serial.print(soundSensorValue);
  Serial.print('\t');
  Serial.println(count);

  if(soundSensorValue != previousValue){
    if(soundSensorValue == 1){
      if(count == 4){
      // Move Forward
      digitalWrite(M11, 1);
      digitalWrite(M12, 0);
      digitalWrite(M21, 1);
      digitalWrite(M22, 0);
      count --;
      }
      else if(count == 3){
        // Move Backward
        digitalWrite(M11, 0);
        digitalWrite(M12, 1);
        digitalWrite(M21, 0);
        digitalWrite(M22, 1);
        count --;
      }
      else if(count == 2){
        // Turn Left
        digitalWrite(M11, 0);
        digitalWrite(M12, 0);
        digitalWrite(M21, 1);
        digitalWrite(M22, 0);
        count --;
      }
      else if(count == 1){
        // Turn Right
        digitalWrite(M11, 1);
        digitalWrite(M12, 0);
        digitalWrite(M21, 0);
        digitalWrite(M22, 0);
        count --;
      }
    }
  }

  previousValue = soundSensorValue; // Update Value

  // Reset Counter
  if(count < 1){
    count = 4;
  }
}
