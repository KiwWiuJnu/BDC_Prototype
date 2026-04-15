#include "ASW/WiperService.h"
#include "BSW/EAL/Eal_Wiper.h"
#include "BSW/MCAL/Mcal_Gpio.h"
#include "Config/ConfigLoader.h"
#include "RTE/Rte_Impl.h"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    try {
        const SystemConfig config = ConfigLoader::LoadFromXml("Config/BDC_Config.xml");
        std::cout << "[Config] Wiper INT interval: " << config.wiperIntIntervalMs << " ms\n";

        McalGpio mcalGpio;
        EalWiper ealWiper(mcalGpio);
        RteImpl rte(ealWiper);
        WiperService wiperService(rte, config.wiperIntIntervalMs);

        wiperService.SetMode(WiperMode::Low);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        wiperService.SetMode(WiperMode::Int);
        for (int i = 0; i < 8; ++i) {
            wiperService.Tick(250);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }

        wiperService.SetMode(WiperMode::High);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        wiperService.SetMode(WiperMode::Off);
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << "[Error] " << ex.what() << '\n';
        return 1;
    }
}
