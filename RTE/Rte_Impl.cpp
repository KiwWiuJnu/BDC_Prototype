#include "RTE/Rte_Impl.h"

#include "BSW/EAL/Eal_Wiper.h"

RteImpl::RteImpl(EalWiper& ealWiper) : ealWiper_(ealWiper) {}

void RteImpl::RequestWiperMotor(WiperMotorCommand command) {
    ealWiper_.ApplyCommand(command);
}

void RteImpl::Tick(int elapsedMs) {
    ealWiper_.Tick(elapsedMs);
}

bool RteImpl::IsWiperParked() {
    return ealWiper_.IsParked();
}
