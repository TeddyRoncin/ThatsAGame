#include "pch.h"

#include "utils/Timer.h"

int Timer::m_FpsCap(0);
std::chrono::time_point<std::chrono::system_clock> Timer::m_StartTime {};
long Timer::m_LastFrameTime(0);
int Timer::m_FrameTime(0);
long Timer::m_CurrentFrame(0);
long Timer::m_FrameDurations[FRAME_DURATION_BATCH] {0};
int Timer::m_MinSleepDurations[MIN_SLEEP_DURATION_BATCH] {0};

void Timer::Init(int fpsCap)
{
	for (int i = 0; i < FRAME_DURATION_BATCH; i++)
	{
		m_FrameDurations[i] = 1;
	}
	for (int i = 0; i < MIN_SLEEP_DURATION_BATCH; i++)
	{
		m_MinSleepDurations[i] = 1;
	}
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
	long currentTime = getCurrentTime();
	long timeElapsed = currentTime - m_LastFrameTime;
	int timeToWait = m_FrameTime - timeElapsed;
	Sleep(timeToWait);
	currentTime = getCurrentTime();
	m_FrameDurations[m_CurrentFrame % FRAME_DURATION_BATCH] = currentTime - m_LastFrameTime;
	m_LastFrameTime = currentTime;
	m_CurrentFrame++;
}

void Timer::Sleep(int timeToWait)
{
	float minSleepDuration = GetAverageMinSleepDuration();
	int fixedTimeToWait = timeToWait / minSleepDuration * minSleepDuration; // Converts time to a multiple of minSleepDuration
	std::chrono::time_point start = std::chrono::system_clock::now();
	std::this_thread::sleep_for(std::chrono::microseconds(fixedTimeToWait));
	m_MinSleepDurations[m_CurrentFrame % MIN_SLEEP_DURATION_BATCH] = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count() - fixedTimeToWait;
	if (m_MinSleepDurations[m_CurrentFrame % MIN_SLEEP_DURATION_BATCH] < 0)
	{
		m_MinSleepDurations[m_CurrentFrame % MIN_SLEEP_DURATION_BATCH] = 1;
	}
}

float Timer::getFps()
{
	long last10FramesDuration = 0;
	for (int i = 0; i < FRAME_DURATION_BATCH; i++) {
		last10FramesDuration += m_FrameDurations[i];
		//std::cout << m_FrameDurations[i] << std::endl;
	}
	return 1.0 / (last10FramesDuration / FRAME_DURATION_BATCH) * 1000000;
}

long Timer::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - m_StartTime).count();
}

void Timer::computeFrameTime()
{
	m_FrameTime = (1 / (float) m_FpsCap) * 1000000;
}

float Timer::GetAverageMinSleepDuration()
{
	float last10MinSleepDuration = 0.0f;
	for (int i = 0; i < MIN_SLEEP_DURATION_BATCH; i++) {
		last10MinSleepDuration += m_MinSleepDurations[i];
	}
	// std::cout << last10MinSleepDuration << std::endl;
	return last10MinSleepDuration / MIN_SLEEP_DURATION_BATCH;
}
