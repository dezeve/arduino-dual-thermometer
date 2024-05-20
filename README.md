# About arduino-dual-thermometer

arduino-dual-thermometer is an arduino project that uses **3 LEDs, Seven-segment display, DHT11 temperature and humidity sensor** and appropriate resistors to **display the temperature in celcius**. The project was developed on Arduino Uno. 

In order for the thermometer to work properly, **Seven-segment display cables** were connected to pins **2 to 9** (including 2 and 9). **Pins 10, 11 and 12** are connected to **leds**. (The names of the leds are determined as start, middle and end respectively for easier understanding). **Pin 13** is connected to **DHT11**.

**Adafruit's library** was preferred as the library for **DHT11**. It may be necessary to download this library separately to run the project.

### How to tell the temperature?

The temperature values are 10 degrees for the start LED, 20 degrees for the middle LED and 30 degrees for the end LED. The temperature is reached by adding the temperature obtained from the LEDs and the temperature on the Seven-segment display. The project operates between 0 and 39 (0 to 39 inclusive) degrees.

### How should I connect the pins of the Seven-segment display?

You need to connect the pins of the Seven-segment display to pins 2-9 (including 2 and 9) on the Arduino in a **counterclockwise direction starting from the bottom left**. These pins are **only used for LEDs**.

### Important Note:
As far as I know, there are two types of anode and cathode in Seven-segment displays. If for this reason the code does not give proper results in the Seven-segment display, **you can solve the problem by replacing LOWs with HIGHs and HIGHs with LOWs in the Seven-segment display functions**.
