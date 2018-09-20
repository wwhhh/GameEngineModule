#include "Event.h"

bool Event::Initialize(ICore * core) {
    printf("Module Event Initialized");
    return true;
}

bool Event::Launch(ICore * core) {
    printf("Module Event Launched");
    return true;
}

bool Event::Destory(ICore * core) {
    printf("Module Event Destoryed");
    return true;
}