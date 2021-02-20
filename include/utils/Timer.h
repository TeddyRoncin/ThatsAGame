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
	static long m_CurrentFrame;
	static long m_FrameDurations[10];

};