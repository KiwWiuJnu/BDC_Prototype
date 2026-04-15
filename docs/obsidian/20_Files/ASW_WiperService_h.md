# ASW/WiperService.h

## 상위
- [[Domain_SourceCode]]

## 역할
- 와이퍼 서비스 인터페이스/상태 정의(ASW)

## 핵심 요소
- `enum class WiperMode { Off, Int, Low, High }`
- `SetMode`, `Tick`
- 내부 상태: 간헐 주기/경과시간/펄스 토글

## 의존
- `RTE_Rte_Interface_h`

## 구현
- [[ASW_WiperService_cpp]]
