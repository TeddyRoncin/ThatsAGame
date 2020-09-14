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
    int m_LastFrameTime;
    int m_FrameTime;
    int getCurrentTime();
    void computeFrameTime();

};