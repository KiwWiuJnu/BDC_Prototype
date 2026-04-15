# ASW/WiperService.cpp

## 상위
- [[Domain_SourceCode]]

## 역할
- 와이퍼 모드 제어 로직 구현

## 핵심 로직
- `SetMode`: 모드 변경 시 타이머/토글 초기화 + 즉시 반영
- `Tick`: INT 모드에서 주기 도달 시 LOW/STOP 토글
- `ApplyImmediateMode`: Off/Low/High 즉시 명령 전송

## 호출 대상
- `IRte::RequestWiperMotor`
- `RTE_Rte_Interface_h`
- `Flow_Wiper_Operation`

## 연관
- [[ASW_WiperService_h]]
