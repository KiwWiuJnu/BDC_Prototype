# main.cpp

## 상위
- [[Domain_SourceCode]]

## 역할
- 프로그램 엔트리 포인트
- Config 로드, 객체 조립(MCAL->EAL->RTE->ASW), 시뮬레이션 실행

## 주요 책임
- XML 설정 로드: `ConfigLoader::LoadFromXml`
- 의존성 주입으로 계층 연결
- 와이퍼 모드 전환 및 Tick 루프 수행

## 의존
- `Config_ConfigLoader_h`
- `BSW_MCAL_Mcal_Gpio_h`
- `BSW_EAL_Eal_Wiper_h`
- `RTE_Rte_Impl_h`
- `ASW_WiperService_h`

## 연관 흐름
- `Flow_Wiper_Operation`
