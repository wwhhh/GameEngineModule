#pragma once

#include "ICore.h"

namespace core {
    class ILogic
    {
    public:
        virtual ~ILogic() {}

        virtual IModule * FindModule(const char * name) = 0;
        virtual void LoadModule(const char * path) = 0;

        virtual bool Launch() = 0;
        virtual void Proces(const int overtiem) = 0;
        virtual void Shutdown() = 0;
    };

    ILogic * GetLogicInstance();
}