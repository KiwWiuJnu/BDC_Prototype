#pragma once

#include "RTE/Rte_Interface.h"

class EalWiper;

class RteImpl : public IRte {
public:
    explicit RteImpl(EalWiper& ealWiper);
    void RequestWiperMotor(WiperMotorCommand command) override;

private:
    EalWiper& ealWiper_;
};
