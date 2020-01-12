#define Trig 13   // Trigger Pin of Ultrasonic Sensor
#define Echo 12   // Echo Pin of Ultrasonic Sensor to Pin Number 12 of Arduino UNO
#define ENA 5  // PWM Pin for Left Motor
#define ENB 6  // PWM Pin for Right Motor
#define M11 7  // Left Motor Pin 1
#define M12 8  // Left Motor Pin 2
#define M21 9  // Right Motor Pin 1
#define M22 10 // Right Motor Pin 2
void setup() {
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  long t = 0, h = 0;              
  digitalWrite(Trig, LOW);        // Transmitting Pulse
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);        
  t = pulseIn(Echo, HIGH);        // Waiting for Pulse
  h = (t/2) / 29.1;               // Calculating Distance
  Serial.print(h);                // Sending to Computer
  Serial.print(" cm\n");
     
  if (h<=10)                      // Condition for Motors
  {
    digitalWrite(M11, 0);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
    delay(1000);                    // Alter for Accurate Turn After Detecting Obstacle
  }
  else
  {
    digitalWrite(M11, 1);
    digitalWrite(M12, 0);
    digitalWrite(M21, 1);
    digitalWrite(M22, 0);
  }
}
