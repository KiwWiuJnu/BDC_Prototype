# RTE/Rte_Interface.h

## 상위
- [[Domain_SourceCode]]

## 역할
- ASW와 하위 계층 사이 계약 인터페이스

## 핵심 요소
- `WiperMotorCommand { Stop, RunLow, RunHigh }`
- `class IRte { RequestWiperMotor(...) }`

## 설계 의미
- ASW가 BSW/MCAL을 직접 모르도록 경계 고정

## 연관
- [[RTE_Rte_Impl_h]]
- `ASW_WiperService_cpp`
- `Architecture_ASW_RTE_BSW`
