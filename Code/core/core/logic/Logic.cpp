#include "Logic.h"
#include <Windows.h>
#include "tinyxml\tinyxml.h"
#include "FileSystem.h"
#include "IModule.h"
#include "Core.h"

namespace core {

    ILogic * GetLogicInstance() {
        return Logic::GetInstance();
    }

    ILogic * Logic::GetInstance() {
        static Logic * p = NULL;
        if (NULL == p) {
            p = new Logic;
        }

        return p;
    }

    bool Logic::Launch() {
        std::string configpath = FileSystem::GetConfigFolder();
        configpath.append("modules.xml");

        // 加载模块表
        TiXmlDocument doc(configpath.c_str());
        bool bSuccess = doc.LoadFile();
        assert(bSuccess);

        // 读取主节点
        TiXmlElement* root = doc.RootElement();
        TiXmlElement* pModule = root->FirstChildElement();
        while (pModule)
        {
            // 得到模块 dll 路径
            const char* pName = pModule->FirstChild()->Value();
            std::string sDllPath = FileSystem::GetDLLFolder();
            sDllPath.append(pName);
            sDllPath.append(".dll");

            // 加载模块 dll
            HINSTANCE hinst = ::LoadLibrary(sDllPath.c_str());
            if (!hinst) {
                assert(hinst);
                return false;
            }

            // 得到模块方法
            GetModule fun = (GetModule)::GetProcAddress(hinst, "GetModules");
            IModule* module = fun();
            
            // 加入模块容器
            while (module) {
                MODULE_MAP::iterator itor = _module_map.find(module->GetName());
                if (itor != _module_map.end()) {
                    assert(false);
                    return false;
                }

                _module_map.insert(make_pair(module->GetName(), module));
                _module_list.push_back(module);
                module->Initialize(Core::GetInstance());
                module = module->GetNext();
            }

            // 获取下一个节点
            pModule = pModule->NextSiblingElement();
        }

        return true;
    }

    void Logic::Shutdown() {
        MODULE_LIST::iterator itor = _module_list.begin();
        MODULE_LIST::iterator iend = _module_list.end();

        // 调用模块终结方法
        while (itor != iend) {
            (*itor)->Destory(Core::GetInstance());
            itor++;
        }

        // 释放模块
        while (itor != iend) {
            delete *itor;
            itor++;
        }
    }

    IModule * Logic::FindModule(const char * name) {
        MODULE_MAP::iterator itor = _module_map.find(name);
        if (itor == _module_map.end() || NULL == itor->second) {
            assert(false);
            return NULL;
        }

        return itor->second;
    }
    
    void Logic::LoadModule(const char * path) {

    }

}