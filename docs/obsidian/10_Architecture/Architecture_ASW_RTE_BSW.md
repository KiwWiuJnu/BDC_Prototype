# Architecture_ASW_RTE_BSW

## 상위
- [[Domain_Architecture]]

## 원칙
- ASW는 하드웨어 직접 접근 금지
- ASW -> RTE -> BSW(EAL/MCAL) 순서만 허용

## 현재 구현 기준
- ASW: `ASW_WiperService.cpp`
- RTE 계약: `RTE_Rte_Interface.h`
- RTE 구현: `RTE_Rte_Impl.cpp`
- EAL: `BSW_EAL_Eal_Wiper.cpp`
- MCAL: `BSW_MCAL_Mcal_Gpio.cpp`
