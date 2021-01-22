/**
 * In this example we debounce a button with a timer and print "Hello".
 * Every time the buton state switch from HIGH to LOW (buton pressed) we start the timer. 
 * When the state switch from LOW to HIGH (button released) we stop the timer and
 * reset the timer value. If the timer runs for a certain amount of time,
 * in our case 10 milliseconds, check() will become true. 
 * 10ms-50ms is good for debouncing but you can also use longer periods of time to detect a long click. 
 * 
 *  ______ - ___ --------------10ms------------>(Hello)          _ -- ___ - _ -- ________
 *        |_|   |_______________________________________________| |__|   |_| |__|
 * The timer starts every time the button state is low. If its low for more than 10ms "Hello"
 * is printed one time. The timer prevents multiple execution of code caused by button bounces.
 */

#include <UniversalTimer.h>

// The pin number of the button
const int buttonPin = 2;

// Create a timer with 10ms and non-repeating
UniversalTimer buttonDebounceTimer(10, false);

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
    // Read the current state of the button
    int buttonStateNew = digitalRead(buttonPin);

    // Buton state switch from HIGH to LOW (buton pressed)
    if (buttonStateOld == HIGH && buttonStateNew == LOW)
    {
        // Start the timer
        buttonDebounceTimer.start();
    }

    // Buton state switch from LOW to HIGH (button released)
    if (buttonStateOld == LOW && buttonStateNew == HIGH)
    {
        // Stop the timer
        buttonDebounceTimer.stop();
        // Reset timer value
        buttonDebounceTimer.resetTimerValue();
    }

    // Save new state as old state for the next loop call
    buttonStateOld = buttonStateNew;

    // Check timer. Returns true if the button is pressed for 10ms
    if (buttonDebounceTimer.check())
    {
        Serial.println("Hello!");
    }

    // Do something else (non-blocking of course)...
}
