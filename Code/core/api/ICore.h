#pragma once

#define CORE_VERSION 0x0001
class IModule;

namespace core {
    class ICore
    {
    public:
        virtual ~ICore() {};

        virtual IModule * FindModule(const char * name) = 0;

        virtual void Shutdown() = 0;
    };
}