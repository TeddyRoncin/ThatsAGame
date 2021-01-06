#include "pch.h"

#include "utils/Timer.h"

Timer::Timer() :
    m_FpsCap(60), m_StartTime(std::chrono::system_clock::now()), m_LastFrameTime(0), m_CurrentFrame(0)
{
    computeFrameTime();
}

Timer::Timer(int fpsCap) :
    m_FpsCap(fpsCap), m_StartTime(std::chrono::system_clock::now()), m_LastFrameTime(0), m_CurrentFrame(0)
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
    long currentTime = getCurrentTime();
    long timeElapsed = currentTime - m_LastFrameTime;
    int timeToWait = m_FrameTime - timeElapsed;
    std::this_thread::sleep_for(std::chrono::microseconds(timeToWait));
    currentTime = getCurrentTime();
    m_FrameDurations[m_CurrentFrame % 10] = currentTime -  m_LastFrameTime;
    m_LastFrameTime = currentTime;
    m_CurrentFrame++;
}

float Timer::getFps()
{
    long last10FramesDuration = 0;
    for (int i = 0; i < 10; i++) {
        last10FramesDuration += m_FrameDurations[i];
    }
    return 1.0 / /*(getCurrentTime() - m_LastFrameTime)*/(last10FramesDuration / 10) * 1000000;
}

long Timer::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - m_StartTime).count();
}

void Timer::computeFrameTime()
{
    m_FrameTime = (1 / (float) m_FpsCap) * 1000000;
}