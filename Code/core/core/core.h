#pragma once

#include "ICore.h"

namespace core {
    class Core : public ICore
    {
    public:
        static Core * GetInstance();

        bool Initialize();

        virtual IModule * FindModule(const char * name);

        virtual void Shutdown() { _shutdown = true; }
        inline bool IsShutdown() { return _shutdown; }
    private:
        bool _shutdown;
        static Core * s_self;
    };
}