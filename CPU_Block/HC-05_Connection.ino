int statePin = 2;

void setup() {
pinMode(statePin,INPUT);
Serial.begin(9600);
}

void loop() {
  int statePinValue = digitalRead(statePin);
  Serial.println(statePinValue);
}
