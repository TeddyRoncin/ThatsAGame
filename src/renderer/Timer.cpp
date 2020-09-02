#include "pch.h"

#include "renderer/Timer.h"

Timer::Timer() :
m_FpsCap(60)
{
    computeFrameTime();
}

Timer::Timer(int fpsCap) :
m_FpsCap(fpsCap)
{
    computeFrameTime();
}

int Timer::getFpsCap()
{
    return m_FpsCap;
}

void Timer::setFpsCap(int fpsCap)
{
    m_FpsCap = fpsCap;
}

void Timer::waitForNextFrame()
{
    int currentTime = getCurrentTime();
    int timeElapsed = currentTime - m_LastFrameTime;
    int timeToWait = m_FrameTime - timeElapsed;
    std::this_thread::sleep_for(std::chrono::microseconds(timeToWait));
    m_LastFrameTime = getCurrentTime();
}

int Timer::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void Timer::computeFrameTime()
{
    m_FrameTime = (1 / (float) m_FpsCap) * 1000000;
}