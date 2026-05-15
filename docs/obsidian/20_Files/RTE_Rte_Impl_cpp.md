# RTE/Rte_Impl.cpp

## 상위
- [[Domain_SourceCode]]

## 역할
- ASW 요청을 EAL로 전달하는 브릿지

## 핵심 로직
- `RequestWiperMotor(command)` -> `ealWiper_.ApplyCommand(command)`

## 연관
- [[RTE_Rte_Impl_h]]
- `BSW_EAL_Eal_Wiper_cpp`
- `Architecture_ASW_RTE_BSW`
