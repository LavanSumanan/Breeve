const int sensorPin = A1;

int sensorValue;
int lastSensorValue = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5000;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = map(analogRead(sensorPin), 0, 1023, 60, 200);
  if (reading != lastSensorValue) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (abs(reading - sensorValue) > 40) {
      // put stuff here
      Serial.println("initalize breeve");
      delay(1000);
    }
  }
  lastSensorValue = reading;
}