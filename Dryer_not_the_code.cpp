#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

float dryerTemperature = 0;
float yourTemperature = 20.0; // Initial needed temperature
int dryingTime = 0; // Drying time in minutes
const int heaterPin = 2; // Changed to match relay module pin D2
const int temperatureSensorPin = 6; // Digital pin for DS18B20 temperature sensor D6
const int encoderPinA = 3; // Pin A for rotary encoder
const int encoderPinB = 4; // Pin B for rotary encoder
const int encoderButtonPin = 5; // Pin for encoder button
int lastEncoded = 0;
bool settingTemperature = true; // Flag to set temperature first, then time

OneWire oneWire(temperatureSensorPin);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Initialize the LCD (RS, E, D4, D5, D6, D7)

setup() {
  pinMode(heaterPin, OUTPUT);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  pinMode(encoderButtonPin, INPUT_PULLUP);

  // Enable internal pull-ups
  digitalWrite(encoderPinA, HIGH);
  digitalWrite(encoderPinB, HIGH);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), updateEncoder, CHANGE);

  sensors.begin();
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows

  for (int i = 0; i < 5; i++) { // Signals that the setup is complete
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    delay(300);
  }
  lcd.print("Setup completed"); // says that the setup is complete on the 16x2 LCD
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  dryerTemperature = sensors.getTempCByIndex(0); // Read temperature in Celsius

  if(settingTemparature) {
    
  } else if (!settingTemparature) {

  }
}