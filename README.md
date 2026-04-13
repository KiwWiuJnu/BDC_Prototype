# BDC_Prototype

SOA 기반 통합 바디 제어 시스템(BDC) 프로토타입 프로젝트입니다.  
AUTOSAR 스타일 계층(ASW/RTE/BSW) 구조를 기반으로 C++17 이상에서 동작하도록 설계합니다.

## 아키텍처
- `ASW`: 서비스 제어 로직
- `RTE`: ASW와 BSW 사이 인터페이스 계층
- `BSW/EAL`: 기능-하드웨어 매핑
- `BSW/MCAL`: 저수준 I/O (현 단계 시뮬레이션)
- `Config`: XML 설정 파일

## 핵심 서비스
- `WiperService`
- `DigitalKeyService`
- `IntrusionDetectionService`

## 확장 서비스
- 편의/안전: `PowerWindow`, `SeatControl`, `OSMirror`, `ParkingAssist`, `LampControl`
- 스마트키: `IgnitionPower`, `RemoteControl`
- 차량경보: `RearOccupantAlert`, `TPMS`

## 설정 정책
- 동작 파라미터는 `Config/BDC_Config.xml`에서 관리합니다.
- 실행 시 XML 파싱으로 적용하며, 코드 하드코딩을 최소화합니다.

## 문서
- 상세 설계/구현 가이드: `BDC_PROJECT_PLAN.md`
- 에이전트 작업 규칙: `.cursorrules`
