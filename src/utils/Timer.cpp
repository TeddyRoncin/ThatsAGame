#include "pch.h"

#include "utils/Timer.h"

int Timer::m_FpsCap(0);
std::chrono::time_point<std::chrono::system_clock> Timer::m_StartTime {};
long Timer::m_LastFrameTime(0);
int Timer::m_FrameTime(0);
long Timer::m_CurrentFrame(0);
long Timer::m_FrameDurations[10] {0};

void Timer::Init(int fpsCap)
{
	m_FpsCap = fpsCap;
	m_StartTime = std::chrono::system_clock::now();
	m_LastFrameTime = 0;
	m_CurrentFrame = 0;
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
	std::this_thread::sleep_for(std::chrono::microseconds(1000));
	long currentTime = getCurrentTime();
	long timeElapsed = currentTime - m_LastFrameTime;
	int timeToWait = m_FrameTime - timeElapsed;
	std::this_thread::sleep_for(std::chrono::microseconds(timeToWait));
	currentTime = getCurrentTime();
	m_FrameDurations[m_CurrentFrame % 10] = currentTime - m_LastFrameTime;
	m_LastFrameTime = currentTime;
	m_CurrentFrame++;
}

float Timer::getFps()
{
	long last10FramesDuration = 0;
	for (int i = 0; i < 10; i++) {
		last10FramesDuration += m_FrameDurations[i];
	}
	//std::cout << last10FramesDuration / 10 << std::endl;
	return 1.0 / (last10FramesDuration / 10) * 1000000;
}

long Timer::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - m_StartTime).count();
}

void Timer::computeFrameTime()
{
	m_FrameTime = (1 / (float) m_FpsCap) * 1000000;
}