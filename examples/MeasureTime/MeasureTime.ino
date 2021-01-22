/**
 * In this example we will sum up the time the button is pressed. 
 * When starting a timer with the interval time of 0 check() will
 * never return true. The timer will run forever. But we can still 
 * use stop and start to measure time. After ~ 49 days 
 * the timerValue has an overflow and will start from 0 again.
 */

#include <UniversalTimer.h>

// The pin number of the button
const int buttonPin = 2;

// Create a timer with 0ms and non-repeating
// 0ms causes the timer check never return true
UniversalTimer buttonPressedTimer(0, false);

// Old button state to detect change in button state
int buttonStateOld = HIGH;

void setup()
{
    // Start serial connection
    Serial.begin(9600);

    // Configure pin 2 as an input and enable the internal pull-up resistor
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    // read the current state of the button
    int buttonStateNew = digitalRead(buttonPin);

    // Buton state switch from HIGH to LOW (buton pressed)
    if (buttonStateOld == HIGH && buttonStateNew == LOW)
    {
        // Start the timer
        buttonPressedTimer.start();
    }

    // Buton state switch from LOW to HIGH (button released)
    if (buttonStateOld == LOW && buttonStateNew == HIGH)
    {
        // Stop the timer
        buttonPressedTimer.stop();

        // Print the timer value
        Serial.print("Time button pressed total: ");
        Serial.println(buttonPressedTimer.getTimerValue());
    }

    // Save new state as old state for the next loop call
    buttonStateOld = buttonStateNew;

    // Do something else (non-blocking of course)...
}
