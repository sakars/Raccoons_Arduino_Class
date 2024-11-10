// This is just something we need to add at the top of our code
// for our code to work
#include <Arduino.h>

// The PIN number to which the LED is connected
const int LED_PIN = 8;

// How long we should wait between turning the LED on and off
const int CHANGE_INTERVAL = 1000;

// Our setup function runs once, when the board is first turned on
void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

// This function runs repeatedly after the setup function has run
void loop()
{
    digitalWrite(LED_PIN, HIGH); // Turn the LED on
    delay(CHANGE_INTERVAL);      // Wait some time so we can see the LED is on
    digitalWrite(LED_PIN, LOW);  // Turn the LED off
    delay(CHANGE_INTERVAL);      // Wait again so we can see the LED is off
}