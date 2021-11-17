#ifndef SCENE_H
#define SCENE_H

#include "../objects/object.h"
#include "../objects/composite.h"

#include <QtDebug>

using namespace std;

class Scene
{
public:
    Scene() :objects(new Composite) {};
    ~Scene() = default;

    void accept(Visitor &visitor);

    void add_object(shared_ptr<Object> &obj);
    void remove_object(int id);
    void remove_object(IteratorObject &it);

    IteratorObject get_object(int id) const;

    IteratorObject begin();
    IteratorObject end();

    Scene &operator=(const Scene &scene);

private:
    shared_ptr<Object> objects;
};

#endif // SCENE_H
