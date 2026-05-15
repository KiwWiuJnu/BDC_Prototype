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
    // 1. 하위 계층(MCAL)의 타이머를 업데이트하기 위해 Tick 전달
    rte_.Tick(elapsedMs);

    if (mode_ != WiperMode::Int) {
        return;
    }

    intElapsedMs_ += elapsedMs;

    if (!intPulseOn_) {
        // [대기 상태] 레버로 설정된 인터벌 시간이 지났는지 확인
        if (intElapsedMs_ >= intIntervalMs_) {
            intElapsedMs_ = 0;
            intPulseOn_ = true;
            rte_.RequestWiperMotor(WiperMotorCommand::RunLow);
        }
    } else {
        // [작동 상태] 하드웨어(MCAL)의 파크 스위치 신호를 확인
        if (rte_.IsWiperParked()) {
            intElapsedMs_ = 0;
            intPulseOn_ = false;
            rte_.RequestWiperMotor(WiperMotorCommand::Stop);
        }
    }
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
