#include "pch.h"

#include "utils/Timer.h"

Timer::Timer() :
    m_FpsCap(60), m_StartTime(std::chrono::system_clock::now()), m_LastFrameTime(0)
{
    computeFrameTime();
}

Timer::Timer(int fpsCap) :
    m_FpsCap(fpsCap), m_StartTime(std::chrono::system_clock::now()), m_LastFrameTime(0)
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

float Timer::getFps() {
    return 1.0 / (getCurrentTime() - m_LastFrameTime) * 1000000;
}

int Timer::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - m_StartTime).count();
}

void Timer::computeFrameTime()
{
    m_FrameTime = (1 / (float) m_FpsCap) * 1000000;
}