#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "scene/scene.h"
#include "../objects/object.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();

    shared_ptr<Scene> get_scene() const;
    void setScene(shared_ptr<Scene> &_scene);

    shared_ptr<Object> get_camera();
    void set_camera(int index);
    void set_camera(const IteratorObject &it);
    
private:
    shared_ptr<Scene> scene;
    weak_ptr<Object> camera;
    bool camera_set;
};

class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> get_manager();
private:
    void create_manager();

    std::shared_ptr<SceneManager> manager;
};

#endif // SCENEMANAGER_H
