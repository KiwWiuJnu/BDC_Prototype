#pragma once

#include <string>

struct SystemConfig {
    int wiperIntIntervalMs = 700;
    int digitalKeyAuthTimeoutMs = 3000;
    int intrusionAlarmDurationSec = 30;
    int autoLockSpeed = 20;
};

class ConfigLoader {
public:
    static SystemConfig LoadFromXml(const std::string& path);
};
