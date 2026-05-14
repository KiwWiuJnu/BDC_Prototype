#include "BSW/MCAL/Mcal_Gpio.h"

#include <iostream>

#include "BSW/MCAL/Mcal_Gpio.h"
#include <iostream>

void McalGpio::SetWiperLow(bool on) {
    // 단순화를 위해 on이 true면 모터가 돌아가는 것으로 간주
    // 실제로는 Low/High 핀 상태를 모두 체크해야 함
    if (on) isMotorOn_ = true; 
    else if (!on) {
        // High 핀도 꺼져있을 때만 완전히 멈춘 것으로 간주 (여기선 단순화)
        isMotorOn_ = false; 
        motorActiveTime_ = 0;
    }
    std::cout << "[MCAL] Wiper LOW pin: " << (on ? "ON" : "OFF") << '\n';
}

void McalGpio::SetWiperHigh(bool on) {
    if (on) isMotorOn_ = true;
    else if (!on) {
        isMotorOn_ = false;
        motorActiveTime_ = 0;
    }
    std::cout << "[MCAL] Wiper HIGH pin: " << (on ? "ON" : "OFF") << '\n';
}

void McalGpio::SetLockPin(bool on) {
    std::cout << "[MCAL] Lock pin: " << (on ? "ON" : "OFF") << '\n';
}

void McalGpio::Tick(int elapsedMs) {
    if (isMotorOn_) {
        motorActiveTime_ += elapsedMs;
    }
}

bool McalGpio::ReadParkPin() {
    return motorActiveTime_ >= 1500;
}