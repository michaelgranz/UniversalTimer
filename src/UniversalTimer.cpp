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

#include "UniversalTimer.h"

UniversalTimer::UniversalTimer() {}
UniversalTimer::UniversalTimer(uint32_t intervalMS, bool repeat)
    : intervalMS(intervalMS), repeat(repeat) {}

void UniversalTimer::setInterval(uint32_t intervalMS)
{
    this->intervalMS = intervalMS;
}
void UniversalTimer::setRepaet(bool repeat)
{
    this->repeat = repeat;
}

void UniversalTimer::addToTimerValue(uint32_t timeMS)
{
    timerValue += timeMS;
}
void UniversalTimer::resetTimerValue()
{
    timerValue = 0;
    lastTime = millis();
}

void UniversalTimer::start()
{
    if (!running)
    {
        running = true;
        lastTime = millis();
    }
}
void UniversalTimer::stop()
{
    updateTimerValue();
    running = false;
}

bool UniversalTimer::check()
{
    updateTimerValue();
    return checkTimerValue();
}

bool UniversalTimer::isRunning()
{
    return running;
}
uint32_t UniversalTimer::getTimerValue()
{
    updateTimerValue();
    return timerValue;
}
uint32_t UniversalTimer::getInterval()
{
    return intervalMS;
}
bool UniversalTimer::isRepeating()
{
    return repeat;
}

void UniversalTimer::updateTimerValue()
{
    if (running)
    {
        timerValue += getElapsedTime();
    }
}
bool UniversalTimer::checkTimerValue()
{
    if (running && intervalMS > 0 && timerValue >= intervalMS)
    {
        timerValue -= intervalMS;
        if (!repeat)
        {
            stop();
            resetTimerValue();
        }
        return true;
    }

    return false;
}
uint32_t UniversalTimer::getElapsedTime()
{
    uint32_t now = millis();
    uint32_t elapsedTime = now - lastTime;
    lastTime = now;
    return elapsedTime;
}
