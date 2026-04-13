# BDC 프로토타입 계획

## 프로젝트 목표

현대모비스 통합 바디도메인 제어기 및 SDV 구현을 목표로, **SOA 기반 통합 바디 제어 시스템(BDC)**을 **C++17 이상**으로 프로토타입 구현한다.

## 아키텍처 설계 원칙 (AUTOSAR 스타일)

### ASW (Application Software)

- **순수 제어 로직만** 담당한다.
- **하드웨어 의존성은 0**이어야 한다. (MCAL 직접 호출 금지)

### RTE (Runtime Environment)

- ASW와 BSW 사이의 **가상 통신 인터페이스**를 제공한다.
- 서비스 지향(SOA) 구조를 드러내기 위해, 서비스는 RTE 인터페이스를 통해서만 하위 계층과 연동한다.

### BSW (Basic Software)

- **EAL (ECU Abstraction Layer)**: 논리 기능과 하드웨어 자원을 매핑한다. (예: Pin 7 = Headlamp)
- **MCAL (Microcontroller Abstraction Layer)**: 로우레벨 입출력을 담당한다. (현 단계에서는 printf/log 기반 시뮬레이션)

## 구현할 핵심 서비스 (3대 영역)

1. **WiperService (편의/안전)**
  - 입력 모드(OFF/INT/LOW/HIGH)에 따라 와이퍼 상태를 제어한다.
  - 간헐(INT) 동작은 설정값 기반 주기 제어가 가능해야 한다.

2. **DigitalKeyService (스마트키)**
  - 스마트폰/키 인증 상태를 바탕으로 차량 접근 권한을 판정한다.
  - 잠금/해제 요청을 처리하고, 필요 시 다른 서비스와 연계한다.

3. **IntrusionDetectionService (차량경보)**
  - 잠금 상태에서 실내 침입 이벤트 감지 시 경보를 발생한다.
  - 상태 머신(대기/감지/경보/해제)을 통해 동작 전이를 관리한다.

## 핵심 기능: XML 기반 설정 (SDV 개념)

- `Config/BDC_Config.xml` 파일을 별도로 관리한다.
- 프로그램 실행 시 XML을 파싱하여 파라미터를 적용한다. **코드 수정 없이 사양 변경**이 가능해야 한다.
- 예시 파라미터:
  - `Wiper_Int_Interval_Ms`
  - `DigitalKey_Auth_Timeout_Ms`
  - `Intrusion_Alarm_Duration_Sec`
  - `Auto_Lock_Speed`

## 제안 폴더 구조(초기)

```text
ASW/
RTE/
BSW/
  EAL/
  MCAL/
Config/
```

## 설계 계약(경계)

- `RTE/Rte_Interface.h`는 ASW ↔ BSW 사이의 **핵심 SOA 통신 경계**를 명확히 보여주는 파일이다.
- ASW 서비스는 RTE 인터페이스를 사용하며, MCAL에 직접 의존하지 않는다.

## 확장 구현 범위

### 편의/안전
- 파워윈도우
- 시트 제어
- O/S Mirror
- 주차 보조
- 내/외장 램프 제어

### 스마트키
- 시동/전원 제어
- 원격 제어(도어/윈도우/주차)

### 차량경보
- 후석 동승자 알림
- TPMS

## 서비스별 최소 인터페이스 가이드

### WiperService
- 입력: 와이퍼 모드 변경 이벤트
- 출력: 와이퍼 모터 제어 요청
- 설정: 간헐 주기, 자동 정지 조건

### DigitalKeyService
- 입력: 인증 요청/인증 결과/사용자 잠금 요청
- 출력: 잠금/해제 요청, 권한 상태
- 설정: 인증 타임아웃, 재시도 횟수

### IntrusionDetectionService
- 입력: 도어/실내 센서 이벤트, 차량 잠금 상태
- 출력: 경보 ON/OFF, 이벤트 로그
- 설정: 경보 지속 시간, 민감도(옵션)

## 검증 시나리오 (초기)

- 와이퍼 모드 전환 시 상태 전이가 정상 동작하는지 확인
- 디지털 키 인증 실패/성공 시 잠금 상태가 올바르게 반영되는지 확인
- 잠금 상태 침입 이벤트에서 경보 상태 머신이 예상대로 전이되는지 확인
- XML 설정 변경 후 재빌드 없이 동작이 달라지는지 확인

## 기술 기준

- C++17 이상

