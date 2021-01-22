/**
 * In this example we create a simple timeout.
 * Every time the buton is pressed we reset the timer value.
 * The running timer is starting from 0 again. 
 * If the button is not pressed for 5 seconds the check()
 * will become true.
 */

#include <UniversalTimer.h>

// The pin number of the button
const int buttonPin = 2;

// Create a timer with 5000ms and repeating
UniversalTimer buttonTimeoutTimer(5000, true);

void setup()
{
    // Start serial connection
    Serial.begin(9600);

    // Configure pin 2 as an input and enable the internal pull-up resistor
    pinMode(buttonPin, INPUT_PULLUP);

    // Start the timer
    buttonTimeoutTimer.start();
}

void loop()
{
    // Bacause of the pull-up our signal goes low when we press the button
    if (digitalRead(buttonPin) == LOW)
    {
        // Reset the timer value
        buttonTimeoutTimer.resetTimerValue();
    }

    // Check timer. Returns true if the button is not pressed for 5s
    if (buttonTimeoutTimer.check())
    {
        Serial.println("Button not pressed for 5 seconds!");
    }

    // Do something else (non-blocking of course)...
}
