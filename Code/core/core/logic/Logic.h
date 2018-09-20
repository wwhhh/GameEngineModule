#pragma once

#include "ILogic.h"

#include <string>
#include <map>
#include <list>
using namespace std;

typedef list<IModule *> MODULE_LIST;
typedef map<string, IModule *> MODULE_MAP;

namespace core {

    class Logic : public ILogic
    {
    public:
        static ILogic * GetInstance();

        virtual bool Launch();
        virtual void Proces(const int overtiem) {}
        virtual void Shutdown();

        virtual IModule * FindModule(const char * name);
        virtual void LoadModule(const char * path);

    private:
        MODULE_LIST _module_list;
        MODULE_MAP _module_map;
    };
}