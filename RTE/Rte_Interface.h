#pragma once

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
};
