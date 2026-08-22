#include <iostream>
#include <string>
#include <fstream>

std::string extractValue(
    const std::string& line,
    const std::string& target = ""
)
{
    const size_t targetPos = line.find(target);

    if (targetPos == std::string::npos) {
        return "";
    }

    const size_t valueStart = targetPos + target.length();
    const size_t valueEnd = line.find(' ', valueStart);

    if (valueEnd == std::string::npos) {
        return line.substr(valueStart);
    }

    return line.substr(valueStart, valueEnd - valueStart);
}

std::string extractTimestamp(const std::string& line) {
    return extractValue(line);
}

struct SensorReading {
    std::string timestamp;
    int rpm;
    double temperature;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: SensorLogAnalyzer <log_file>\n";
        return 1;
    }   

    std::ifstream logFile(argv[1]);

    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open your log file: " << argv[1] << '\n';
        return 1;
    }

    std::string line;

    while (std::getline(logFile, line)) {
        SensorReading reading;
        reading.timestamp = extractTimestamp(line);
        reading.rpm = std::stoi(extractValue(line, "RPM="));
        reading.temperature = std::stod(extractValue(line, "TEMP="));
        std::cout << "Timestamp: " << reading.timestamp << '\n';
        std::cout << "RPM: " << reading.rpm << '\n';
        std::cout << "TEMP: " << reading.temperature << '\n';
    }

    return 0;
}