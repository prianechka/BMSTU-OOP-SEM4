#include "scene.h"

void Scene::add_object(shared_ptr<Object> &obj)
{
    objects->add(obj);
};


IteratorObject Scene::begin()
{
    return objects->begin();
}
IteratorObject Scene::end()
{
    return objects->end();
}

Scene &Scene::operator=(const Scene &scene)
{
    objects = scene.objects; return (*this);
};


void Scene::accept(Visitor &visitor)
{
    for (const auto &elem : *objects)
        elem->accept(visitor);
}

void Scene::remove_object(int id)
{
    int idTmp = 0;
    for (const auto &elem : *objects)
    {
        if (elem->getId() == id)
        {
            objects->remove(objects->begin() + idTmp);
        }
        idTmp++;
    }
};

void Scene::remove_object(IteratorObject &it)
{
    objects->remove(it);
}

IteratorObject Scene::get_object(int id) const
{
    int idTmp = 0;
    for (const auto &elem : *objects)
    {
        if (elem->getId() == id)
        {
            return objects->begin() + idTmp;
        }
        idTmp++;
    }
    return objects->end() + 1;
};
