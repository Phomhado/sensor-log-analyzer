#include <iostream>
#include <string>

std::string extractValue(
    const std::string& line,
    const std::string& target
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

int main()
{
    const std::string line =
        "2026-07-26T21:15:31 RPM=1350 TEMP=82.4";

    std::cout << extractValue(line, "RPM=") << '\n';
    std::cout << extractValue(line, "TEMP=") << '\n';

    return 0;
}