#include <assert.h>
#include "ILogic.h"
#include "Core.h"

using namespace core;

int main()
{
    // 初始化 Core 指针
    Core::GetInstance();

    // 初始化逻辑模块
    ILogic* pLogic = GetLogicInstance();
    if (!pLogic || !pLogic->Launch()) {
        // 逻辑模块加载失败
        assert(false);
    }

    if (pLogic)
    {
        pLogic->Shutdown();
    }

    return 0;
}