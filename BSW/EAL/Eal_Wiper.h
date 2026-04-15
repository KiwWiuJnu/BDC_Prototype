#pragma once

#include "RTE/Rte_Interface.h"

class McalGpio;

class EalWiper {
public:
    explicit EalWiper(McalGpio& gpio);
    void ApplyCommand(WiperMotorCommand command);

private:
    McalGpio& gpio_;
};
