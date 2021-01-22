/**
 * In this example we turn on an off the LED every 3 seconds.
 */

#include <UniversalTimer.h>

// The number of the LED pin
const int ledPin = LED_BUILTIN;

// State of LED
int ledState = LOW;

// Create a timer with 3000ms and repeating
UniversalTimer ledTimer(3000, true);

void setup()
{
    // Start serial connection
    Serial.begin(9600);

    // Set the digital pin as output
    pinMode(ledPin, OUTPUT);

    // Start the timer
    ledTimer.start();
}

void loop()
{
    // Check timer. Returns true every 3s
    if (ledTimer.check())
    {
        // Switch LED state
        if (ledState == LOW)
        {
            ledState = HIGH;
        }
        else
        {
            ledState = LOW;
        }
    }

    // Set the LED state
    digitalWrite(ledPin, ledState);

    // Do something else (non-blocking of course)...
}
