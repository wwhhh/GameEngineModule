#pragma once

#include <string>

class FileSystem
{
public:
    static std::string GetLogFolder();

    static std::string GetResFolder();
    static std::string GetConfigFolder();
    static std::string GetDLLFolder();

    bool FileExists(const std::string& file);
    bool FileIsNewer(const std::string& file1, const std::string& file2);

private:
    FileSystem() {}

    static char* sLogFolder;
    static char* sResFolder;
    static char* sConfigSubFolder;
    static char* sDllFolder;
};