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

        // ����ģ���
        TiXmlDocument doc(configpath.c_str());
        bool bSuccess = doc.LoadFile();
        assert(bSuccess);

        // ��ȡ���ڵ�
        TiXmlElement* root = doc.RootElement();
        TiXmlElement* pModule = root->FirstChildElement();
        while (pModule)
        {
            // �õ�ģ�� dll ·��
            const char* pName = pModule->FirstChild()->Value();
            std::string sDllPath = FileSystem::GetDLLFolder();
            sDllPath.append(pName);
            sDllPath.append(".dll");

            // ����ģ�� dll
            HINSTANCE hinst = ::LoadLibrary(sDllPath.c_str());
            if (!hinst) {
                assert(hinst);
                return false;
            }

            // �õ�ģ�鷽��
            GetModule fun = (GetModule)::GetProcAddress(hinst, "GetModules");
            IModule* module = fun();
            
            // ����ģ������
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

            // ��ȡ��һ���ڵ�
            pModule = pModule->NextSiblingElement();
        }

        return true;
    }

    void Logic::Shutdown() {
        MODULE_LIST::iterator itor = _module_list.begin();
        MODULE_LIST::iterator iend = _module_list.end();

        // ����ģ���ս᷽��
        while (itor != iend) {
            (*itor)->Destory(Core::GetInstance());
            itor++;
        }

        // �ͷ�ģ��
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