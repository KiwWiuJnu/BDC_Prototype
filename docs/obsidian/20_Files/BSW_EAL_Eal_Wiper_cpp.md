# BSW/EAL/Eal_Wiper.cpp

## 상위
- [[Domain_SourceCode]]

## 역할
- 와이퍼 명령을 실제 핀 제어 시퀀스로 매핑

## 매핑
- Stop -> LOW OFF, HIGH OFF
- RunLow -> LOW ON, HIGH OFF
- RunHigh -> LOW OFF, HIGH ON

## 연관
- [[BSW_EAL_Eal_Wiper_h]]
- `BSW_MCAL_Mcal_Gpio_cpp`
- `Flow_Wiper_Operation`
