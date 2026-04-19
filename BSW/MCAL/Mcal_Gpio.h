#pragma once

class McalGpio {
public:
    void SetWiperLow(bool on);
    void SetWiperHigh(bool on);
    void Tick(int elapsedMs);
    bool ReadParkPin();

private:
    bool isMotorOn_ = false;
    int motorActiveTime_ = 0;
};
