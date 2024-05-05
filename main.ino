#include "DHT.h"
#include <math.h>

#define DHTPIN 13

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

/*

Important Note:

As far as I know, there are two types of
anode and cathode in Seven-segment displays.
If for this reason the code does not give proper
results in the Seven-segment display,
you can solve the problem by
replacing LOWs with HIGHs and HIGHs with LOWs
in the Seven-segment functions.

*/

void clearScreen() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void displayOne() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void displayTwo() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void displayThree() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
}

void displayFour() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void displayFive() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void displaySix() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void displaySeven() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void displayEight() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void displayNine() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void displayZero() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
}

void turnOnStartLed() {
  digitalWrite(10, HIGH);
}

void turnOffStartLed() {
  digitalWrite(10, LOW);
}

void turnOnMiddleLed() {
  digitalWrite(11, HIGH);
}

void turnOffMiddleLed() {
  digitalWrite(11, LOW);
}

void turnOnEndLed() {
  digitalWrite(12, HIGH);
}

void turnOffEndLed() {
  digitalWrite(12, LOW);
}

void turnOnAllLed() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
}

void turnOffAllLed() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

void setup() {

 //Seven-segment display connections
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  //Start, middle and end leds respectively
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  //Initializes DHT11 sensor
  dht.begin();
}
 
void loop() {

  //DHT11 measures at 2 second (2000ms) intervals
  delay(2000);

  float temperature = dht.readTemperature();
  int roundedTemperature = round(temperature);
  int sevenDisplayNumber;

  if (isnan(temperature)) {
    turnOnEndLed();
    clearScreen();
    return;
  }

  if (roundedTemperature > 39 && roundedTemperature < 0) {
    turnOnAllLed();
    clearScreen();
  }

  if (roundedTemperature > 30) {
    
    sevenDisplayNumber = roundedTemperature - 30;
    
    turnOnEndLed();
    turnOffMiddleLed();
    turnOffStartLed();
  }

  else if (roundedTemperature > 20) {
    
    sevenDisplayNumber = roundedTemperature - 20;
    
    turnOnMiddleLed();
    turnOffStartLed();
    turnOffEndLed();
  }

  else if (roundedTemperature > 10) {
    
    sevenDisplayNumber = roundedTemperature - 10;
    
    turnOnStartLed();
    turnOffMiddleLed();
    turnOffEndLed();
  }

  else {
    sevenDisplayNumber = roundedTemperature;
  }

  switch (sevenDisplayNumber) {
      case (0):
        displayZero();
        break; 
      case (9):
        displayNine();
        break;
      case (8):
        displayEight();
        break;
      case (7):
        displaySeven();
        break;
      case (6):
        displaySix();
        break; 
      case (5):
        displayFive();
        break;
      case (4):
        displayFour();
        break;
      case (3):
        displayThree();
        break;
      case (2):
        displayTwo();
        break;
      case (1):
        displayOne();
        break;        
    }
}
