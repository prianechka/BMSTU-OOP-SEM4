#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include "point.h"
#include "../Mathobj/mathobjs.h"

class InvisibleObject;

class Camera : public InvisibleObject
{
public:
    Camera() = default;
    Camera(const Point &_position, const Point &_direction);
    ~Camera() = default;

    virtual void conversion(const Point &transfer, const ScaleCoef &scale, const Angle &rotate) override;
    virtual void accept(Visitor &visitor) override;

    friend class Visitor;

protected:
    Point get_direction() const;
    Point get_pos() const;

private:
    void transfer(const Point &transfer);
    void rotate(const Angle &rotate);

    Point position;
    Point direction;
};

#endif // CAMERA_H
