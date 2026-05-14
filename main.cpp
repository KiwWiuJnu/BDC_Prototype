#include "ASW/WiperService.h"
#include "ASW/DigitalKeyService.h"
#include "BSW/EAL/Eal_Wiper.h"
#include "BSW/EAL/Eal_Lock.h"
#include "BSW/MCAL/Mcal_Gpio.h"
#include "Config/ConfigLoader.h"
#include "RTE/Rte_Impl.h"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    try {
        // 1. Configuration Load
        const SystemConfig config = ConfigLoader::LoadFromXml("Config/BDC_Config.xml");
        std::cout << "[Config] Wiper INT interval: " << config.wiperIntIntervalMs << " ms\n";
        std::cout << "[Config] DigitalKey Auth Timeout: " << config.digitalKeyAuthTimeoutMs << " ms\n";

        // 2. BSW Layer Initialization
        McalGpio mcalGpio;
        EalWiper ealWiper(mcalGpio);
        EalLock ealLock(mcalGpio);

        // 3. RTE Layer Initialization
        RteImpl rte(ealWiper, ealLock, config);

        // 4. ASW Layer Initialization
        WiperService wiperService(rte, config.wiperIntIntervalMs);
        DigitalKeyService digitalKeyService(rte);

        std::cout << "\n--- Scenario 1: Wiper Operation Test ---\n";
        wiperService.SetMode(WiperMode::Low);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        wiperService.SetMode(WiperMode::Off);

        std::cout << "\n--- Scenario 2: Digital Key Access Denied Test ---\n";
        // 인증 없이 잠금 해제 시도
        digitalKeyService.SetLockState(false);

        std::cout << "\n--- Scenario 3: Digital Key Authentication & Control Test ---\n";
        // 잘못된 키로 인증 시도
        digitalKeyService.RequestAuthentication("WRONG_KEY");
        digitalKeyService.SetLockState(false);

        // 올바른 키로 인증 시도
        digitalKeyService.RequestAuthentication("VALID_KEY");
        digitalKeyService.SetLockState(false); // Unlock
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        digitalKeyService.SetLockState(true);  // Lock

        std::cout << "\n--- All Scenarios Completed ---\n";
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "[Error] " << ex.what() << '\n';
        return 1;
    }
}
