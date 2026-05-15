#include "Config/ConfigLoader.h"

#include <fstream>
#include <regex>
#include <sstream>
#include <stdexcept>

namespace {
int ReadIntTagOrDefault(const std::string& xml, const std::string& tag, int defaultValue) {
    const std::regex pattern("<" + tag + R"(>\s*([0-9]+)\s*</)" + tag + ">");
    std::smatch match;
    if (std::regex_search(xml, match, pattern) && match.size() > 1) {
        return std::stoi(match[1].str());
    }
    return defaultValue;
}
}  // namespace

SystemConfig ConfigLoader::LoadFromXml(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open config file: " + path);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    const std::string xml = buffer.str();

    SystemConfig config;
    config.wiperIntIntervalMs = ReadIntTagOrDefault(xml, "Wiper_Int_Interval_Ms", config.wiperIntIntervalMs);
    config.digitalKeyAuthTimeoutMs = ReadIntTagOrDefault(xml, "DigitalKey_Auth_Timeout_Ms", config.digitalKeyAuthTimeoutMs);
    config.intrusionAlarmDurationSec = ReadIntTagOrDefault(xml, "Intrusion_Alarm_Duration_Sec", config.intrusionAlarmDurationSec);
    config.autoLockSpeed = ReadIntTagOrDefault(xml, "Auto_Lock_Speed", config.autoLockSpeed);
    return config;
}
