#pragma once

#include "RTE/Rte_Interface.h"

class EalWiper;

class RteImpl : public IRte {
public:
    explicit RteImpl(EalWiper& ealWiper);
    void RequestWiperMotor(WiperMotorCommand command) override;
    void Tick(int elapsedMs) override;
    bool IsWiperParked() override;

private:
    EalWiper& ealWiper_;
};
