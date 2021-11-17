#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <chrono>
#include <memory>
#include "object.h"

using namespace std;

class Composite : public Object
{
public:
    Composite() = default;
    ~Composite() = default;

    Composite(shared_ptr<Object> first, ...);

    virtual bool is_composite() override;
    virtual bool add(shared_ptr<Object> &obj) override;
    virtual bool remove(const IteratorObject &it) override;
    virtual IteratorObject begin() override;
    virtual IteratorObject end() override;

    virtual void conversion(const Point &transfer, const ScaleCoef &scale, const Angle &angle) override;
    virtual void accept(Visitor &visitor) override;

private:
    VectorObject vector;
};

#endif // COMPOSITE_H
