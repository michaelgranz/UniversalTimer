# UniversalTimer

Easy to use, multifunctional and non-blocking timer.
Its based on the arduino millis() function. Supporting repeating and non repeating timer intervals. You can use it to execute code periodically or other timing tasks like timeout, non-blocking delay, debounce buttons or measure time.

## Example

```cpp
#include <UniversalTimer.h>

// Create a timer with 3000ms and non-repeating
UniversalTimer delay3sTimer(3000, false);

// Create a timer with 5000ms and repeating
UniversalTimer every5sTimer(5000, true);

void setup()
{
    Serial.begin(9600);

    // Start the timer
    delay3sTimer.start();
    every5sTimer.start();
}

void loop()
{
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
}
```

## How does it work?

Its easier to understand how to use the timer if you know how its working.
The timer is based on the timerValue and the interval you choose.

By default the timerValue starts at 0 and every time you `check()` the timer the elapsed time since the last check is added to the timerValue. If the timerValue is greater than the interval the `check()` will return true. If the timer is not repeating it will be stopped and the timerValue set to 0. If the timer is repeating the interval is substracted from the timerValue an the timer continues. The subtraction leads to an exact repeating timing because no time is "lost".
For example your timerValue is currently 95ms and your interval is 100ms. The next loop takes 10ms. 105ms is grater than 100ms and `check()` returns true and the repeating timer continues with the remaining 5ms.

A special case is a timer with interval set to 0. The `check()` for this timer will never return true. The timer can be used to measure time. See example.

## UniversalTimer Class

### Construct Timer

```cpp
    UniversalTimer();
    UniversalTimer(uint32_t intervalMS, bool repeat);
```

By default (no parameter given) the timer interval is 1000 milliseconds and non-repeating.
You can pass interval in milliseconds and repeat mode as an argument.

The timer is using uint32_t. This result in a maximum interval of (2^32-1) milliseconds.
4294967295 milliseconds ~ 4294967 seconds ~ 71582 minutes ~ 1193 hours ~ 49 days

Do not choose a smaller interval than your average loop time. Otherwise the timer cant keep up and will overflow earlier or later.

### Change Timer

```cpp
    void setInterval(uint32_t intervalMS);
    void setRepaet(bool repeat);
```

This methods let you change the timer. Be careful. You can use this functions even with a running timer. To avoid unexpected behavior `stop()` and `resetTimerValue()` before setting this values.

### Manipulate Timer Value

```cpp
    void addToTimerValue(uint32_t timeMS);
    void resetTimerValue();
```

With this methods you can manipulate the timerValue. You can use it to preload the timer or reset the timerValue to 0.
This methods do not effect the running state of the timer. If your reset the timerValue of a running timer it will continue from 0.

### Start/Stop

```cpp
    void start();
    void stop();
```

With this methods you can start and stop the timer.
This methods do not effect the timerValue.

### Check Timer

```cpp
    bool check();
```

If the timerValue is greater than your choosen interval `check()` will return true. In case the timer is not repeating the timerValue will be stopped and the timerValue will be set to 0. In case of a repeating timer the interval will be subtracted from the timerValue and the timer continues with the remaining time.

### Getter

```cpp
    bool isRunning();
    uint32_t getTimerValue();
    uint32_t getInterval();
    bool isRepeating();
```

Get the diffrent timer values.
