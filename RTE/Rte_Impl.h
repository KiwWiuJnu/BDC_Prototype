#pragma once

#include "RTE/Rte_Interface.h"
#include "Config/ConfigLoader.h"

class EalWiper;
class EalLock;

class RteImpl : public IRte {
public:
    explicit RteImpl(EalWiper& ealWiper, EalLock& ealLock, const SystemConfig& config);
    void RequestWiperMotor(WiperMotorCommand command) override;
    void Tick(int elapsedMs) override;
    bool IsWiperParked() override;

    uint32_t GetDigitalKeyAuthTimeout() override;
    void Call_SetLockState(bool lock) override;

private:
    EalWiper& ealWiper_;
    EalLock& ealLock_;
    const SystemConfig& config_;
};
