#pragma once

#include <cstdint>

enum class WiperMotorCommand {
    Stop,
    RunLow,
    RunHigh
};

class IRte {
public:
    virtual ~IRte() = default;
    virtual void RequestWiperMotor(WiperMotorCommand command) = 0;
    virtual void Tick(int elapsedMs) = 0;
    virtual bool IsWiperParked() = 0;
    virtual uint32_t GetDigitalKeyAuthTimeout() = 0;
    virtual void Call_SetLockState(bool lock) = 0;
};
