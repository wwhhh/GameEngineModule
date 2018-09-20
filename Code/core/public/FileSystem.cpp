#include "FileSystem.h"
#include "Tools.h"

char* FileSystem::sLogFolder = 0;
char* FileSystem::sResFolder = 0;
char* FileSystem::sConfigSubFolder = 0;
char* FileSystem::sDllFolder = 0;

std::string FileSystem::GetLogFolder()
{
    if (sLogFolder == 0)
    {
        sLogFolder = new char[256];
        std::string path = tools::GetAppPath();
        path.append("/../../");
        memcpy(sLogFolder, path.c_str(), path.length() + 1);
    }

    return sLogFolder;
}

std::string FileSystem::GetResFolder()
{
    if (sResFolder == 0)
    {
        sResFolder = new char[256];
        std::string path = tools::GetAppPath();
        path.append("/../../");
        memcpy(sResFolder, path.c_str(), path.length() + 1);
    }
    return sResFolder;
}

std::string FileSystem::GetConfigFolder()
{
    if (sConfigSubFolder == 0)
    {
        sConfigSubFolder = new char[256];
        std::string path = tools::GetAppPath();
        path.append("/../Configs/");
        memcpy(sConfigSubFolder, path.c_str(), path.length() + 1);
    }
    return sConfigSubFolder;
}

std::string FileSystem::GetDLLFolder()
{
    if (sDllFolder == 0)
    {
        sDllFolder = new char[256];
        std::string path = tools::GetAppPath();
        path.append("/../Debug/");
        memcpy(sDllFolder, path.c_str(), path.length() + 1);
    }
    return sDllFolder;
}