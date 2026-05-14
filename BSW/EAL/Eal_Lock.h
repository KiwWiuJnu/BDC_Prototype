#pragma once

#include "BSW/MCAL/Mcal_Gpio.h"

class EalLock {
public:
    EalLock(McalGpio& gpio) : gpio_(gpio) {}

    /**
     * @brief 차량의 잠금 상태를 설정합니다.
     * @param lock true: 잠금(Lock), false: 해제(Unlock)
     */
    void SetLockState(bool lock) {
        // EAL 계층에서는 '잠금'이라는 논리적 동작을 하드웨어 핀 제어로 매핑합니다.
        // 예: lock이 true일 때 핀을 High로 설정
        gpio_.SetLockPin(lock);
    }

private:
    McalGpio& gpio_;
};
