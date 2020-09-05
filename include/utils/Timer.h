#pragma once

class Timer
{

public:
    Timer();
    Timer(int fpsCap);
    int getFpsCap();
    void setFpsCap(int fpsCap);
    void waitForNextFrame();

private:
    int m_FpsCap;
    int m_TimeRunning;
    int m_LastFrameTime;
    int m_FrameTime;
    int getCurrentTime();
    void computeFrameTime();

};