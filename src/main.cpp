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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: SensorLogAnalyzer <log_file>\n";
        return 1;
    }   

    std::ifstream logFile(argv[1]);

    if (!logFile.is_open()) {
        std::cout << "Error: Could not open your log file: " << argv[1] << '\n';
        return 1;
    }

    std::string line;

    while (std::getline(logFile, line)) {
        std::cout << "Timestamp: " << extractTimestamp(line) << '\n';
        std::cout << "RPM: " << extractValue(line, "RPM=") << '\n';
        std::cout << "TEMP: " << extractValue(line, "TEMP=") << '\n';
    }

    return 0;
}