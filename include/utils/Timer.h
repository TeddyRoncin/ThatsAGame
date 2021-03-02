#pragma once

class Timer
{

public:
	static void Init(int fpsCap = 60);
	static int getFpsCap();
	static void setFpsCap(int fpsCap);
	static void waitForNextFrame();
	static float getFps();

private:
	static int m_FpsCap;
	static std::chrono::time_point<std::chrono::system_clock> m_StartTime;
	static long m_LastFrameTime;
	static int m_FrameTime;
	static long getCurrentTime();
	static void computeFrameTime();
	static void Sleep(int timeToWait);
	static int GetAverageMinSleepDuration();
	static long m_CurrentFrame;
	static const int FRAME_DURATION_BATCH = 10;
	static const int MIN_SLEEP_DURATION_BATCH = 10;
	static long m_FrameDurations[FRAME_DURATION_BATCH];
	static int m_MinSleepDurations[MIN_SLEEP_DURATION_BATCH];

};