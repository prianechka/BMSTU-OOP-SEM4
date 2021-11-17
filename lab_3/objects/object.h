#ifndef OBJECT_H
#define OBJECT_H

#include "point.h"
#include "../Mathobj/mathobjs.h"

class Visitor;

#include <memory>
#include <vector>

using namespace std;

class Object;

using VectorObject = vector<shared_ptr<Object>>;
using IteratorObject = VectorObject::const_iterator;

class Object
{
public:
    Object() = default;
    ~Object() = default;

    virtual bool is_composite();
    virtual bool add(shared_ptr<Object> &);
    virtual bool remove(const IteratorObject &);
    virtual IteratorObject begin();
    virtual IteratorObject end();
    void setId(int newId);
    int getId();

    virtual void conversion(const Point &transfer, const ScaleCoef &scale, const Angle &rotate) = 0;
    virtual void accept(Visitor &visitor) = 0;
protected:
    int id = 0;
};

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() = default;

    virtual bool is_visible() const {return false; };
};

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() = default;

    virtual bool is_visible() const {return true; };
};

#endif // OBJECT_H
