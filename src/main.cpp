#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

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
    std::size_t lineNumber = 0;

    while (std::getline(logFile, line)) {
        ++lineNumber;
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        SensorReading reading;
        reading.timestamp = extractTimestamp(line);
        const std::string rpmToken = extractValue(line, "RPM=");
        const std::string temperatureToken = extractValue(line, "TEMP=");

        try {
            std::size_t consumed = 0;
            reading.rpm = std::stoi(rpmToken, &consumed);
            if (consumed != rpmToken.size()) {
                throw std::invalid_argument("Trailing characters in RPM");
            }

            reading.temperature = std::stod(temperatureToken, &consumed);
            if (consumed != temperatureToken.size()) {
                throw std::invalid_argument("Trailing characters in TEMP");
            }
        } catch (const std::invalid_argument&) {
            std::cerr << "Skipping line " << lineNumber
                      << ": missing or invalid numeric value.\n";
            continue;
        } catch (const std::out_of_range&) {
            std::cerr << "Skipping line " << lineNumber
                      << ": numeric value is out of range.\n";
            continue;
        }

        std::cout << "Timestamp: " << reading.timestamp << '\n';
        std::cout << "RPM: " << reading.rpm << '\n';
        std::cout << "TEMP: " << reading.temperature << '\n';
    }

    return 0;
}
