# Flow_Wiper_Operation

## 상위
- [[Domain_Flows]]

## 호출 체인
`main.cpp` -> `WiperService` -> `IRte::RequestWiperMotor` -> `RteImpl` -> `EalWiper` -> `McalGpio`

## 모드 동작
- Off: Stop
- Low: RunLow
- High: RunHigh
- Int: Tick 주기마다 RunLow/Stop 토글

## 관련 파일(참고명)
- `main.cpp`
- `ASW_WiperService.cpp`
- `RTE_Rte_Interface.h`
- `RTE_Rte_Impl.cpp`
- `BSW_EAL_Eal_Wiper.cpp`
- `BSW_MCAL_Mcal_Gpio.cpp`
- `Config_BDC_Config.xml`
- `Config_ConfigLoader.cpp`
