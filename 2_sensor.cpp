// This is just something we need to add at the top of our code
// for our code to work
#include <Arduino.h>

const int LED_PIN = 12;
const int TRIGGER_PIN = 11;
const int ECHO_PIN = 10;

// This function runs once, when the board is first turned on
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    // Clear the trigger
    digitalWrite(TRIGGER_PIN, LOW);
}

// This function runs repeatedly after the setup function has run
void loop()
{
    double speedOfSound = 343;                   // Speed of sound in m/s
    double speedOfSound2 = speedOfSound / 10000; // Speed of sound in cm/uS

    // Fire a pulse to the sensor
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Read the time it took for the sound wave to come back
    long duration = pulseIn(ECHO_PIN, HIGH); // Time in microseconds

    // Calculate the distance
    double fullDist = duration * speedOfSound2; // Distance in cm
    double dist = fullDist / 2;                 // Distance to the object

    // If the distance is less than 30 cm, turn the LED on
    if (dist < 30)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
    // Wait a bit before we do it again
    delay(100);
}