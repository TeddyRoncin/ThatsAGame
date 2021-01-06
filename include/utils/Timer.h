#pragma once

class Timer
{

public:
    Timer();
    Timer(int fpsCap);
    int getFpsCap();
    void setFpsCap(int fpsCap);
    void waitForNextFrame();
    float getFps();

private:
    int m_FpsCap;
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    long m_LastFrameTime;
    int m_FrameTime;
    long getCurrentTime();
    void computeFrameTime();
    long m_CurrentFrame;
    long m_FrameDurations[10];

};