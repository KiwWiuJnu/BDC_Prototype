#pragma once

#include <string>
#include <iostream>
#include "RTE/Rte_Interface.h"

class DigitalKeyService {
public:
    DigitalKeyService(IRte& rte) : rte_(rte), isAuthenticated_(false) {}

    /**
     * @brief 키 인증을 요청합니다.
     * @param keyId 인증할 키의 식별자
     */
    void RequestAuthentication(const std::string& keyId) {
        std::cout << "[ASW] DigitalKeyService: Requesting authentication for KeyID: " << keyId << "...\n";
        
        // 시뮬레이션: "VALID_KEY"인 경우에만 인증 성공
        if (keyId == "VALID_KEY") {
            std::cout << "[ASW] DigitalKeyService: Authentication SUCCESS.\n";
            isAuthenticated_ = true;
        } else {
            std::cout << "[ASW] DigitalKeyService: Authentication FAILED.\n";
            isAuthenticated_ = false;
        }

        // SDV 설정값 활용 예시
        uint32_t timeout = rte_.GetDigitalKeyAuthTimeout();
        std::cout << "[ASW] DigitalKeyService: Auth token valid for " << timeout << "ms.\n";
    }

    /**
     * @brief 차량의 잠금 상태를 변경합니다.
     * @param lock true: 잠금, false: 해제
     */
    void SetLockState(bool lock) {
        if (!isAuthenticated_) {
            std::cout << "[ASW] DigitalKeyService: Access Denied. Please authenticate first.\n";
            return;
        }

        std::cout << "[ASW] DigitalKeyService: Authorized. Setting lock state to: " 
                  << (lock ? "LOCK" : "UNLOCK") << "\n";
        rte_.Call_SetLockState(lock);
    }

    bool IsAuthenticated() const { return isAuthenticated_; }

private:
    IRte& rte_;
    bool isAuthenticated_;
};
