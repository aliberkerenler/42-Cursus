#include "Replacer.hpp"

std::string Replacer::replaceAll(const std::string& str, const std::string& s1, const std::string& s2) {
    if (s1.empty()) return str;
    std::string result;
    size_t pos = 0, prev = 0;
    while ((pos = str.find(s1, prev)) != std::string::npos) {
        result.append(str, prev, pos - prev);
        result += s2;
        prev = pos + s1.length();
    }
    result.append(str, prev, std::string::npos);
    return result;
}