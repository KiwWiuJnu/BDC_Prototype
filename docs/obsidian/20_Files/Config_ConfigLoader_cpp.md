# Config/ConfigLoader.cpp

## 상위
- [[Domain_SourceCode]]

## 역할
- XML 텍스트에서 설정값 파싱

## 핵심 로직
- 파일 열기 실패 시 예외
- `ReadIntTagOrDefault`로 태그별 정수 추출
- 누락 태그는 기본값 유지

## 연관
- [[Config_ConfigLoader_h]]
- [[Config_BDC_Config_xml]]
- `Config_XML_Key_Summary`
