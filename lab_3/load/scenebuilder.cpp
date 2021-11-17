#include "scenebuilder.h"

bool SceneBuilder::is_build()
{
    return scene != nullptr;
}

void SceneBuilder::reset()
{
    scene = shared_ptr<Scene>(new Scene);
}

void SceneBuilder::build_objects(std::vector<shared_ptr<Object>> &objects)
{
    for (auto &object : objects)
        scene->add_object(object);
}

shared_ptr<Scene> SceneBuilder::get_result()
{
    return scene;
}
