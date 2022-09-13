/*
 * Proximity detector that lights up leds based on distance
 * @author Dustin Mullins
 * Last Updated 9/4/2022
 */

#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define GREEN_PIN 2
#define YELLOW_PIN 4
#define RED_PIN 7

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;

void setup() {
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  a = sr04.Distance();
  if (a < 45) {
    digitalWrite(GREEN_PIN, HIGH);
  } else {
    digitalWrite(GREEN_PIN, LOW);
  }
  if (a < 30) {
    digitalWrite(YELLOW_PIN, HIGH);
  } else {
    digitalWrite(YELLOW_PIN, LOW);
  }
  if (a < 15) {
    digitalWrite(RED_PIN, HIGH);
  } else {
    digitalWrite(RED_PIN, LOW);
  }
  delay(500);
}
