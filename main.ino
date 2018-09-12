#include <Wire.h>
#include "SparkFunHTU21D.h"

//Create an instance of the object
HTU21D myHumidity;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1 * 60 * 1000UL ;  //valeur en millisecondes pour l'envoie des données


void setup()
{
  Serial.begin(9600); // on initialise le port série à 9600
  myHumidity.begin(); //on initialise le HTU21D
  startMillis = millis();  //initial start time
}

void loop()
{
  float h = myHumidity.readHumidity();
  float t = myHumidity.readTemperature();
  
  currentMillis = millis();
  if (currentMillis - startMillis >=  period)
  {
  Serial.print(t, 1); //affiche la temperature
  Serial.print(" \t"); 
  Serial.print(h, 1); //affiche l'humidité
  Serial.println();
  startMillis = currentMillis;
  }
}
