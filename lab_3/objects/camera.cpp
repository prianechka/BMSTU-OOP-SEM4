#include "camera.h"


Camera::Camera(const Point &_position, const Point &_direction)
{
    position = _position;
    direction = _direction;
}

Point Camera::get_direction() const
{
    return direction;
}

Point Camera::get_pos() const
{
    return position;
}

void Camera::transfer(const Point &transfer)
{
    position.transfer(transfer);
}

void Camera::rotate(const Angle &rotate)
{
    direction.rotate(Point(0,0,0), rotate);
}

void Camera::accept(Visitor &visitor)
{

}

void Camera::conversion(const Point &transfer, const ScaleCoef &scale, const Angle &rotate)
{
    this->transfer(transfer);
    this->rotate(rotate);
}
