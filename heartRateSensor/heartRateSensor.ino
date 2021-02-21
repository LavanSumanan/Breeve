#include <Keyboard.h>

const int sensorPin = A1;

int sensorValue;
int lastSensorValue = LOW;

char leftCtrlKey = KEY_LEFT_CTRL;
char leftShift = KEY_LEFT_SHIFT;
char rightCtrlKey = KEY_RIGHT_CTRL;
char rightShift = KEY_RIGHT_SHIFT;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5000;

void setup() {
  pinMode(sensorPin, INPUT);
  Keyboard.begin();
}

void loop() {
  int reading = map(analogRead(sensorPin), 0, 1023, 60, 200);
  if (reading != lastSensorValue) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (abs(reading - buttonState) > 40) {
      Keyboard.press(leftCtrlKey);
      Keyboard.press(rightCtrlKey);
      Keyboard.press(leftShift);
      Keyboard.press(rightShift);
      Keyboard.press('b');
      delay(100);
      Keyboard.releaseAll();
      delay(10000);
    }
  }
  lastSensorValue = reading;
}