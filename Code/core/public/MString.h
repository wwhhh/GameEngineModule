#pragma once

#include <string>
#include <vector>

class MString
{
public:
    static std::string ToAscii(const std::wstring& input);
    static std::wstring ToUnicode(const std::string& input);

    static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    static std::vector<std::string> split(const std::string &s, char delim);

private:
    MString();
};

// Converts a number to a string
template<typename T> inline std::wstring ToString(const T& val)
{
    std::wostringstream stream;
    if (!(stream << val))
        return L"";
    return stream.str();
}