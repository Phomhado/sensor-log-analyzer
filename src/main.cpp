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

int main()
{
    std::ifstream logFile;
    logFile.open("sample.log");

    if (!logFile.is_open()) {
        std::cout << "Error: Could not read your log file.\n";
        return 1;
    }

    std::string line;
    while (std::getline(logFile, line)) {
        std::cout << "Timestamp: " << extractTimestamp(line) << "\n";
        std::cout << "RPM: " << extractValue(line, "RPM=") << '\n';
        std::cout << "TEMP: " << extractValue(line, "TEMP=") << '\n';
    }

    return 0;
}