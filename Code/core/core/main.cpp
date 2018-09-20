#include <assert.h>
#include "ILogic.h"
#include "Core.h"

using namespace core;

int main()
{
    // ��ʼ�� Core ָ��
    Core::GetInstance();

    // ��ʼ���߼�ģ��
    ILogic* pLogic = GetLogicInstance();
    if (!pLogic || !pLogic->Launch()) {
        // �߼�ģ�����ʧ��
        assert(false);
    }

    if (pLogic)
    {
        pLogic->Shutdown();
    }

    return 0;
}