#include<Arduino.h>
#include"DHT22.h"
#define DHTPIN 2
#define STEP_PIN 9
#define DIR_PIN 8
DHT22 dht(DHTPIN);
unsigned long lastPrint = 0;
int tempToPWM(float temp)
{
  if (temp < 27) return 0;
  if (temp > 40) return 255;
  return map((int)(temp * 10), 270, 400, 0, 255);

}
void setup()
{
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, HIGH);
   Serial.begin(9600);
}
void loop()
{
  float temp= dht.getTemperature();
  int pwm = tempToPWM(temp);
  if (pwm > 0)
  {
    int delayMicros = map(pwm, 0, 255, 5000, 500);
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(delayMicros);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(delayMicros);
  }
  if (millis() - lastPrint >= 500)
  {
    Serial.print("temp: ");
    Serial.print(temp);
    Serial.print("C, PWM: ");
    Serial.println(pwm);
    lastPrint = millis();
  }
}