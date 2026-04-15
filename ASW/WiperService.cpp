#include "ASW/WiperService.h"

WiperService::WiperService(IRte& rte, int intIntervalMs)
    : rte_(rte), intIntervalMs_(intIntervalMs) {}

void WiperService::SetMode(WiperMode mode) {
    mode_ = mode;
    intElapsedMs_ = 0;
    intPulseOn_ = false;
    ApplyImmediateMode();
}

void WiperService::Tick(int elapsedMs) {
    if (mode_ != WiperMode::Int) {
        return;
    }

    intElapsedMs_ += elapsedMs;
    if (intElapsedMs_ < intIntervalMs_) {
        return;
    }

    intElapsedMs_ = 0;
    intPulseOn_ = !intPulseOn_;
    rte_.RequestWiperMotor(intPulseOn_ ? WiperMotorCommand::RunLow : WiperMotorCommand::Stop);
}

void WiperService::ApplyImmediateMode() {
    switch (mode_) {
        case WiperMode::Off:
            rte_.RequestWiperMotor(WiperMotorCommand::Stop);
            break;
        case WiperMode::Int:
            rte_.RequestWiperMotor(WiperMotorCommand::Stop);
            break;
        case WiperMode::Low:
            rte_.RequestWiperMotor(WiperMotorCommand::RunLow);
            break;
        case WiperMode::High:
            rte_.RequestWiperMotor(WiperMotorCommand::RunHigh);
            break;
    }
}
