#pragma once

#include "RTE/Rte_Interface.h"

enum class WiperMode {
    Off,
    Int,
    Low,
    High
};

class WiperService {
public:
    WiperService(IRte& rte, int intIntervalMs);
    void SetMode(WiperMode mode);
    void Tick(int elapsedMs);

private:
    IRte& rte_;
    int intIntervalMs_;
    WiperMode mode_ = WiperMode::Off;
    int intElapsedMs_ = 0;
    bool intPulseOn_ = false;

    void ApplyImmediateMode();
};
