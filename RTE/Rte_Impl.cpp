#include "RTE/Rte_Impl.h"

#include "BSW/EAL/Eal_Wiper.h"
#include "BSW/EAL/Eal_Lock.h"

RteImpl::RteImpl(EalWiper& ealWiper, EalLock& ealLock, const SystemConfig& config) 
    : ealWiper_(ealWiper), ealLock_(ealLock), config_(config) {}

void RteImpl::RequestWiperMotor(WiperMotorCommand command) {
    ealWiper_.ApplyCommand(command);
}

void RteImpl::Tick(int elapsedMs) {
    ealWiper_.Tick(elapsedMs);
}

bool RteImpl::IsWiperParked() {
    return ealWiper_.IsParked();
}

uint32_t RteImpl::GetDigitalKeyAuthTimeout() {
    return config_.digitalKeyAuthTimeoutMs;
}

void RteImpl::Call_SetLockState(bool lock) {
    ealLock_.SetLockState(lock);
}
