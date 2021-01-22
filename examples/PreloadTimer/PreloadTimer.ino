/**
 * In this example we create a timer printing "Hello" every 10 seconds. 
 * Before starting the timer we add 9 seconds to the timer value. 
 * This results in printing "Hello" after 1 second and then every 10 seconds. 
 * Be careful: If you add more time than the timer interval to a repeating timer
 * you can cause the check() to become true multiple times. 
 * For example: When you start a 10s timer with 30s preloaded time check()
 * will return true three times in a row and then every 10 seconds.
 */

#include <UniversalTimer.h>

// Create a timer with 10000ms and repeating
UniversalTimer helloTimer(10000, true);

void setup()
{
    // Start serial connection
    Serial.begin(9600);

    // Add 9000ms to the timer value
    helloTimer.addToTimerValue(9000);
    // Start the timer
    helloTimer.start();
}

void loop()
{
    // Check timer. Returns true first time after 1s and then every 10s
    if (helloTimer.check())
    {
        Serial.println("Hello");
    }

    // Do something else (non-blocking of course)...
}
