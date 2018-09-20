#pragma once

#include "IModule.h"

class Event : public IModule
{
public:

    virtual bool Initialize(ICore * core);
    virtual bool Launch(ICore * core);
    virtual bool Destory(ICore * core);

};