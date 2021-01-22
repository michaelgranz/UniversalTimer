/**
 * In this example we create three diffrent timer.
 */

#include <UniversalTimer.h>

// Create a timer with 1000ms(default) and non-repeating(default)
UniversalTimer defaultTimer;

// Create a timer with 3000ms and non-repeating
UniversalTimer delay3sTimer(3000, false);

// Create a timer with 5000ms and repeating
UniversalTimer every5sTimer(5000, true);

void setup()
{
    // Start serial connection
    Serial.begin(9600);

    // Start the timer
    defaultTimer.start();
    delay3sTimer.start();
    every5sTimer.start();
}

void loop()
{
    // Check timer. Returns true after 1s
    if (defaultTimer.check())
    {
        Serial.println("Triggered after 1 second!  (defaultTimer)");
    }

    // Check timer. Returns true after 3s
    if (delay3sTimer.check())
    {
        Serial.println("Triggered after 3 seconds! (delay3sTimer)");
    }

    // Check timer. Returns true every 5s
    if (every5sTimer.check())
    {
        Serial.println("Triggered every 5 seconds! (every5sTimer)");
    }

    // Do something else (non-blocking of course)...
}
