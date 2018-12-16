/***************************************************************************
  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface. The device's I2C address is either 0x76 or 0x77.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
/*Ici on défini*/
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "SparkFunHTU21D.h"
#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C
HTU21D myHumidity;

/*Ici on défini le l'intervalle de temp pour la transmission des donées*/
unsigned long period = 1000UL * 30;
unsigned long time_now = 0;

float minTemp; // keep track of minimum recorded temp
float maxTemp; // keep track of maximum recorded temp

void setup() {
  Serial.begin(9600);

  if (! bme.begin(&Wire)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  myHumidity.begin();
  minTemp = myHumidity.readTemperature();
  maxTemp = myHumidity.readTemperature();

}
void loop() {
  // Only needed in forced mode! In normal mode, you can remove the next line.
  bme.takeForcedMeasurement(); // has no effect in normal mode

  // update min and max temp values
  if (myHumidity.readTemperature() < minTemp) {
    minTemp = myHumidity.readTemperature();
  }
  if (myHumidity.readTemperature() > maxTemp) {
    maxTemp = myHumidity.readTemperature();
  }

  //Ici on utilise le time millis() déclaré plus haut.A chaque fois que l'on atteind le conmpteur, on execute void printValues().
  if (millis() > time_now + period) {
    time_now = millis();
    printValues();
  }


}


void printValues() {
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();
  float tempp = bme.readTemperature();
  float humdp = bme.readHumidity();
  float pres = bme.readPressure() / 100.0F + 23.6;

  Serial.print(temp, 1);
  Serial.print(" \t");
  Serial.print(minTemp, 1);
  Serial.print(" \t");
  Serial.print(maxTemp, 1);
  Serial.print(" \t");
  Serial.print(humd, 1);
  Serial.print(" \t");
  Serial.print(tempp, 1);
  Serial.print(" \t");
  Serial.print(humdp, 1);
  Serial.print(" \t");
  Serial.print(pres, 1);
  Serial.print(" \t");
  Serial.println();

}
