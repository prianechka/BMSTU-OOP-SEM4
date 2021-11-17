#include "loadmanager.h"

LoadManager::LoadManager()
{
    figure_loader = shared_ptr<LoadDirector>(new FigureDirector);
    scene_loader = shared_ptr<SceneDirector>(new SceneDirector);
    camera_loader = shared_ptr<LoadDirector>(new CameraDirector);
}

shared_ptr<Object> LoadManager::load_figure(const string &file_name)
{
    return figure_loader->load(file_name);
}

shared_ptr<Scene> LoadManager::load_scene(const string &file_name)
{
    return scene_loader->load(file_name);
}

shared_ptr<Object> LoadManager::load_camera(const string &file_name)
{
    return camera_loader->load(file_name);
}

void LoadManagerCreator::create_manager()
{
    static shared_ptr<LoadManager>_manager(new LoadManager);
    manager = _manager;
}

shared_ptr<LoadManager> LoadManagerCreator::get_manager()
{
    if (manager == nullptr)
        create_manager();

    return manager;
}
