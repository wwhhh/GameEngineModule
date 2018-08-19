#pragma once

#include <Windows.h>
#include <string>
#include "ICore.h"

class IModule
{
public:
    virtual ~IModule() {}
    virtual  bool Initialize() = 0;
    virtual  bool Launch() = 0;
    virtual  bool Destory() = 0;

public:
    IModule() : _next(nullptr) {}

    inline void SetNext(IModule * & pModule) { _next = pModule; }

    inline IModule * GetNext() { return _next; }

    inline void SetName(const char * name) { _name = name; }

    inline const char * GetName() const { return _name; }

    inline int GetVersion() const { return CORE_VERSION; }

private:
    IModule * _next;
    const char* _name;
};

typedef IModule * (*GetModule)(void);

#define CREATE_MODULE(name) \
class factroy##name {    \
public:    \
    factroy##name(IModule * & pModule) { \
        IModule * pModule##name = NEW name; \
        pModule##name->SetName(#name); \
        pModule##name->SetNext(pModule); \
        pModule = pModule##name; \
    } \
}; \
factroy##name factroy##name(s_modules);

#define GET_DLL_ENTRANCE \
    static IModule * s_modules = NULL; \
    extern "C" __declspec(dllexport) IModule * __cdecl GetModules() {\
        return s_modules; \
    } \
    bool WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) { \
            return TRUE;    \
    }