#include <LiquidCrystal.h> // Include the library for the LCD
#include <OneWire.h>
#include <DallasTemperature.h>

float dryerTemperature = 0; // Will be pulled from the temperature sensor
float yourTemperature = 20.0; // Initial needed temperature
int dryingTime = 0; // Drying time in minutes
const int heaterPin = 2; // Changed to match relay module pin D2
const int temperatureSensorPin = 6; // Digital pin for DS18B20 temperature sensor D6
const int encoderPinA = 3; // Pin A for rotary encoder
const int encoderPinB = 4; // Pin B for rotary encoder
const int encoderButtonPin = 5; // Pin for encoder button
int lastEncoded = 0;
bool settingTemperature = true; // Flag to set temperature first, then time
bool drying = false; // Flag to indicate if drying process is active
bool cancelOption = false; // Flag for cancel option

OneWire oneWire(temperatureSensorPin);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); // Initialize the LCD (RS, E, D4, D5, D6, D7)

void setup() {
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
  lcd.print("   KachleGG's   ");
  lcd.setCursor(0, 1);
  lcd.print("Filament Dryier");
}

void loop() {
  if (!drying) {
    if (digitalRead(encoderButtonPin) == LOW) {
      delay(50); // Debounce delay
      while (digitalRead(encoderButtonPin) == LOW); // Wait for button release

      if (cancelOption) {
        drying = false;
        digitalWrite(heaterPin, LOW); // Turn off heater
        lcd.clear();
        lcd.print("Drying Cancelled");
        delay(2000); // Display message for 2 seconds
        settingTemperature = true; // Reset flag to set temperature again
      } else if (settingTemperature) {
        settingTemperature = false; // Switch to setting time
        lcd.clear();
        lcd.print("Set Dry Time");
        lcd.setCursor(0, 1);
        lcd.print(dryingTime);
        lcd.print(" min");
      } else {
        drying = true;
        dryingTime *= 60; // Convert minutes to seconds
        lcd.clear();
        lcd.print("Drying...");
      }
    }

    // Display current setting on LCD
    lcd.clear();
    if (cancelOption) {
      lcd.print("> Cancel Drying");
    } else if (settingTemperature) {
      lcd.print("Set Temp: ");
      lcd.print(yourTemperature);
      lcd.print(" C");
    } else {
      lcd.print("Set Time: ");
      lcd.print(dryingTime);
      lcd.print(" min");
    }
    delay(200); // Delay for stability
  } else {
    sensors.requestTemperatures(); // Send the command to get temperatures
    dryerTemperature = sensors.getTempCByIndex(0); // Read temperature in Celsius

    if (dryerTemperature >= yourTemperature) {
      digitalWrite(heaterPin, LOW);
    } else {
      digitalWrite(heaterPin, HIGH);
    }

    // Display on LCD
    lcd.clear();
    lcd.print("Dryer Temp: ");
    lcd.print(dryerTemperature);
    lcd.setCursor(0, 1);
    lcd.print("Remain: ");
    lcd.print(dryingTime / 60);
    lcd.print(" min");

    delay(1000); // Delay for 1 second
    dryingTime--;

    if (dryingTime <= 0) {
      drying = false;
      digitalWrite(heaterPin, LOW); // Turn off heater
      lcd.clear();
      lcd.print("Drying Done");
      delay(2000); // Display message for 2 seconds
      settingTemperature = true; // Reset flag to set temperature again
    }
  }
}

void updateEncoder() {
  int MSB = digitalRead(encoderPinA); // Most significant bit
  int LSB = digitalRead(encoderPinB); // Least significant bit

  int encoded = (MSB << 1) | LSB; // Convert the 2 pin values to a single number
  int sum = (lastEncoded << 2) | encoded; // Concatenate previous encoded value with current

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
    if (cancelOption) {
      cancelOption = false;
      settingTemperature = true;
    } else if (settingTemperature) {
      yourTemperature += 0.1;
    } else {
      dryingTime++;
    }
  }
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
    if (cancelOption) {
      cancelOption = false;
      settingTemperature = true;
    } else if (settingTemperature) {
      yourTemperature -= 0.1;
    } else {
      dryingTime--;
    }
  }

  lastEncoded = encoded; // Store this value for next time
}
