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
};
