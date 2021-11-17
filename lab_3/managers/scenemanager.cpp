#include "scenemanager.h"


SceneManager::SceneManager() : camera_set(false)
{
}

shared_ptr<Scene> SceneManager::get_scene() const
{
    return scene;
}

void SceneManager::setScene(shared_ptr<Scene> &_scene)
{
    scene = _scene;
}

void SceneManagerCreator::create_manager()
{
    static shared_ptr<SceneManager> _manager(new SceneManager);
    manager = _manager;
}

shared_ptr<SceneManager> SceneManagerCreator::get_manager()
{
    if (manager == nullptr)
        create_manager();

    return manager;
}

void SceneManager::set_camera(int index)
{
    IteratorObject it = scene->get_object(index);

    set_camera(it);
}

void SceneManager::set_camera(const IteratorObject &it)
{
    camera = (*it);
}

shared_ptr<Object> SceneManager::get_camera()
{
    return camera.lock();
}
