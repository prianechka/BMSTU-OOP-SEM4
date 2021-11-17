#include "object.h"

bool Object::is_composite()
{
    return false;
}

bool Object::add(shared_ptr<Object> &)
{
    return false;
};

bool Object::remove(const IteratorObject &)
{
    return false;
};

IteratorObject Object::begin()
{
    return IteratorObject();
};

IteratorObject Object::end()
{
    return IteratorObject();
};

void Object::setId(int newId)
{
    id = newId;
};

int Object::getId()
{
    return id;
};
