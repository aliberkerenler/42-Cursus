#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
public:
    static std::string replaceAll(const std::string& str, const std::string& s1, const std::string& s2);
};

#endif