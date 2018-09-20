#include <assert.h>
#include "Core.h"
#include "logic\Logic.h"

using namespace core;

namespace core {
    Core * Core::s_self = 0;

    Core * Core::GetInstance() {
        if (nullptr == s_self) {
            s_self = new Core;
            if (!s_self->Initialize()) {
                delete s_self;
                s_self = 0;
                assert(false);
            }
        }

        return s_self;
    }

    bool Core::Initialize()
    {
        return true;
    }

    IModule * Core::FindModule(const char * name)
    {
        return GetLogicInstance()->FindModule(name);
    }
}