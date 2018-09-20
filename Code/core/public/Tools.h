#pragma once

#include <string>
#include <wrl.h>

namespace tools {

    const char * GetAppPath()
    {
        static char* s_path = NULL;

        if (NULL == s_path) {
            s_path = new char[256];
            GetModuleFileName(NULL, s_path, 256);
            std::string str = s_path;
            int pos = str.find_last_of('\\', str.length());
            std::string path = str.substr(0, pos);
            memcpy(s_path, path.c_str(), path.length() + 1);
        }

        return s_path;
    }
}