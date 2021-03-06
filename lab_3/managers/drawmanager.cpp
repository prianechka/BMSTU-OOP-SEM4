#include "drawmanager.h"
#include "visitor/visitor.h"
#include "objects/edge.h"

#define WINDOW_CENTER_W 300
#define WINDOW_CENTER_H 300

void DrawManager::draw(const shared_ptr<BaseDrawer> &drawer, const shared_ptr<Camera> &camera)
{
    Visitor visitor(drawer, camera);
    scene->accept(visitor);
}


void DrawManagerCreator::create_manager()
{
    static shared_ptr<DrawManager>_manager(new DrawManager);
    manager = _manager;
}

shared_ptr<DrawManager> DrawManagerCreator::get_manager()
{
    if (manager == nullptr)
        create_manager();

    return manager;
}
