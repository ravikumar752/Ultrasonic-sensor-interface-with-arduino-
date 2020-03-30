/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7
*/
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float inches = 0;
float cm = 0;
#define sensor 7
long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);  // Clear the trigger
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  // Sets the pin on HIGH state for 10 micro seconds
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  // Reads the pin, and returns the sound wave travel time in microseconds
  return pulseIn(pin, HIGH);
}

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(sensor);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  lcd.setCursor(0, 0);
  lcd.print("Dist in cm=");
  lcd.setCursor(11, 0);
  lcd.print(cm);
  lcd.setCursor(0, 1);
  lcd.print("Dist in inch=");
  lcd.setCursor(13, 1);
  lcd.print(inches);
  delay(100);
  //lcd.clear();
  // Wait for 100 millisecond(s)
}
