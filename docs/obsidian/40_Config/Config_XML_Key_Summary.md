# Config_XML_Key_Summary

## 상위
- [[Domain_Config]]

## 파일
- `Config_BDC_Config.xml`
- 로더: `Config_ConfigLoader.cpp`

## 키 목록
- `Wiper_Int_Interval_Ms` -> `SystemConfig.wiperIntIntervalMs`
- `DigitalKey_Auth_Timeout_Ms` -> `SystemConfig.digitalKeyAuthTimeoutMs`
- `Intrusion_Alarm_Duration_Sec` -> `SystemConfig.intrusionAlarmDurationSec`
- `Auto_Lock_Speed` -> `SystemConfig.autoLockSpeed`

## 참고
- 기본값 정의: `Config_ConfigLoader.h`
- 실제 사용(main): `main.cpp`
