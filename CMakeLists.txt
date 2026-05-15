cmake_minimum_required(VERSION 3.16)
project(BDC_Prototype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # 컴파일러 확장 꺼서 이식성 증가
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(bdc_prototype
    main.cpp
    ASW/WiperService.cpp
    RTE/Rte_Impl.cpp
    BSW/EAL/Eal_Wiper.cpp
    BSW/MCAL/Mcal_Gpio.cpp
    Config/ConfigLoader.cpp
)

target_include_directories(bdc_prototype PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

