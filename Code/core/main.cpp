#include <Windows.h>
#include "IModule.h"


int main()
{
    HINSTANCE hinst = ::LoadLibrary("");
    
    GetModule fun = (GetModule)::GetProcAddress(hinst, "GetModules");
    IModule* pModule = fun();

    return 0;
}