#include "IModule.h"

static IModule * s_modules = NULL;
extern "C" __declspec(dllexport) IModule * __cdecl GetModules() {

        return s_modules;
}

GET_DLL_ENTRANCE;
//CREATE_MODULE(Event);