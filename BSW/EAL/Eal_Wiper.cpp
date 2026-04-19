#include "BSW/EAL/Eal_Wiper.h"

#include "BSW/MCAL/Mcal_Gpio.h"

EalWiper::EalWiper(McalGpio& gpio) : gpio_(gpio) {}

void EalWiper::ApplyCommand(WiperMotorCommand command) {
    switch (command) {
        case WiperMotorCommand::Stop:
            gpio_.SetWiperLow(false);
            gpio_.SetWiperHigh(false);
            break;
        case WiperMotorCommand::RunLow:
            gpio_.SetWiperLow(true);
            gpio_.SetWiperHigh(false);
            break;
        case WiperMotorCommand::RunHigh:
            gpio_.SetWiperLow(false);
            gpio_.SetWiperHigh(true);
            break;
    }
}

void EalWiper::Tick(int elapsedMs) {
    gpio_.Tick(elapsedMs);
}

bool EalWiper::IsParked() {
    return gpio_.ReadParkPin();
}
