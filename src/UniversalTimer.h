/**
 * Copyright 2020 Michael Granz
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef UNIVERSALTIMER_H
#define UNIVERSALTIMER_H

#include <Arduino.h>

class UniversalTimer
{

public:
    UniversalTimer();
    UniversalTimer(uint32_t intervalMS, bool repeat);

    void setInterval(uint32_t intervalMS);
    void setRepaet(bool repeat);

    void addToTimerValue(uint32_t timeMS);
    void resetTimerValue();

    void start();
    void stop();

    bool check();

    bool isRunning();
    uint32_t getTimerValue();
    uint32_t getInterval();
    bool isRepeating();

private:
    bool running = false;
    uint32_t timerValue = 0;

    uint32_t intervalMS = 1000;
    bool repeat = false;

    uint32_t lastTime = 0;

    void updateTimerValue();
    bool checkTimerValue();
    uint32_t getElapsedTime();
};

#endif // UNIVERSALTIMER_H
