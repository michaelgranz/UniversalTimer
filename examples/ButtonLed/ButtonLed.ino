/**
 * In this example we turn on the LED when the button is pressed
 * and keep it on for 5 seconds after the button is released.
 */

#include <UniversalTimer.h>

// The pin number of the LED
const int ledPin = LED_BUILTIN;

// The pin number of the button
const int buttonPin = 2;

// State of LED
int ledState = LOW;

// Create a timer with 5000ms and non-repeating
UniversalTimer ledTimer(5000, false);

void setup()
{
    // Start serial connection
    Serial.begin(9600);

    // Set the digital pin as output
    pinMode(ledPin, OUTPUT);

    // Configure pin 2 as an input and enable the internal pull-up resistor
    pinMode(buttonPin, INPUT_PULLUP);

    // Start the timer
    ledTimer.start();
}

void loop()
{
    // Check if button is pressed.
    // If the button is pressed the state is low because of the pullup.
    if (digitalRead(buttonPin) == LOW)
    {
        // Reset the timer
        ledTimer.resetTimerValue();
        // Start the timer
        ledTimer.start();
        // Turn LED on
        ledState = HIGH;
    }

    // Check timer. Returns true after 5s
    if (ledTimer.check())
    {
        // Turn LED off
        ledState = LOW;
    }

    // Set the LED state
    digitalWrite(ledPin, ledState);

    // Do something else (non-blocking of course)...
}
