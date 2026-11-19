// DHT20 code
/*
  For the DHT20 to work properly you will have to add the line:

    robtillaart/DHT20

    to the lib_deps

*/

#include <Arduino.h>      // include Arduino.h
#include <Wire.h>         // include Wire.h
#include <DHT20.h>        // include DHT20.h

// ESP32 I2C pins
#define SDA_PIN 21        // Connect SDA of DHT20 to Pin 21 using 10k Pullup
#define SCL_PIN 22        // Connect SCL of DHT20 to Pin 22 using 10k Pullup

// Create DHT20 sensor object
DHT20 sensor;             // declare sensor as a DHT20 object

void setup()
{
    Serial.begin(9600);   // Set Baud Rate to 9699
    delay(1000);          // Wait 1 second


    // Initialize I2C
    Wire.begin(SDA_PIN, SCL_PIN);

    // Initialize sensor
    sensor.begin();       // Activate the DHT20 sensor

   printf("\e[2J\e[3;1HDHT20 Initialization Complete");
   printf("\e[4;1HTemperature    Humidity");
   
}

void loop()
{
    // Read sensor
    int status = sensor.read();

    // If you try to poll the DHT20 faster than 1 second, you will get the
    // DHT20 Read Error Message

    if (status == DHT20_OK)
    {
        float temperature = sensor.getTemperature();
        float humidity = sensor.getHumidity();

        printf("\e[5;3H %4.2f\t%4.2f",temperature,humidity);
    }
    else
    {
        Serial.print("DHT20 read error: ");
        Serial.println(status);
    }

    delay(1000);        // delay must be at least 1000 ms
}
