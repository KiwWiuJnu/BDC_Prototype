#include "BSW/MCAL/Mcal_Gpio.h"

#include <iostream>

void McalGpio::SetWiperLow(bool on) {
    std::cout << "[MCAL] Wiper LOW pin: " << (on ? "ON" : "OFF") << '\n';
}

void McalGpio::SetWiperHigh(bool on) {
    std::cout << "[MCAL] Wiper HIGH pin: " << (on ? "ON" : "OFF") << '\n';
}
