# BDC_Prototype

SOA 기반 통합 바디 제어 시스템(BDC) 프로토타입 프로젝트입니다.  
AUTOSAR 스타일 계층(ASW/RTE/BSW) 구조를 기반으로 C++17 이상에서 동작하도록 설계합니다.

## 핵심 설계

### 1. 분산형 시스템 통합 및 아키텍처 설계

- 기존 분산 제어 방식의 한계를 극복하기 위해 AUTOSAR 기반 **Layered Architecture**(ASW-RTE-BSW)를 도입했습니다.
- 시스템 복잡도를 낮추고 모듈화된 설계를 통해 통합 제어의 확장성을 확보했습니다.

### 2. 하드웨어 추상화 및 표준 인터페이스(RTE) 수립

- `RTE` 인터페이스와 `EAL`/`MCAL` 계층을 구축하여 하드웨어와 로직 사이의 의존성을 제거했습니다.
- 이를 통해 MCU 변경 시에도 소프트웨어 로직 수정 없이 이식이 가능한 표준 SW 플랫폼 구조를 구현했습니다.

### 3. 데이터 중심 설계 (Data-Driven SDV Approach)

- 차량 사양 변경 시 재빌드가 필요한 기존 방식 대신, XML 기반 설정 관리 방식을 채택했습니다.
- 외부 설정 파일 수정을 통해 동작 파라미터를 동적으로 제어함으로써 SDV 환경에 최적화된 개발 환경을 구축했습니다.

### 4. AI 페어 프로그래밍을 통한 설계 검증

- **Cursor AI**를 활용하여 시스템 아키텍처의 무결성을 검토하고 보일러플레이트 코드를 자동화했습니다.
- 아키텍트로서 전체적인 인터페이스 규격을 정의하고, AI를 효율적인 구현 도구로 활용하는 최신 개발 프로세스를 경험했습니다.

---

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

## Engineering Approach (AI-Assisted)

본 프로젝트는 시스템 설계의 무결성을 검토하고 개발 생산성을 높이기 위해 Cursor AI를 페어 프로그래밍 도구로 활용했습니다.

- 설계 주도: 시스템의 계층 구조(Layered Architecture) 및 RTE 인터페이스 사양은 직접 정의했습니다.
- 효율적 구현: 반복적인 보일러플레이트 코드 생성 및 단위 로직 검증에 AI를 활용하여, 하드웨어 추상화와 재사용성 확보라는 본질적 설계 문제에 집중했습니다.

## 문서

- 상세 설계/구현 가이드: `BDC_PROJECT_PLAN.md`
- 에이전트 작업 규칙: `.cursorrules`

