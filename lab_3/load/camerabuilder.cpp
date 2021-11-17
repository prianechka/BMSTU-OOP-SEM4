#include "camerabuilder.h"

bool CameraBuilder::is_build()
{
    return is_position && is_direction;
}

void CameraBuilder::reset()
{
    is_position = is_direction = false;
}

void CameraBuilder::build_position(const Point &_position)
{
    position = _position; is_position = true;
}

void CameraBuilder::build_direction(const Point &_direction)
{
    direction = _direction;
    is_direction = true;
}

std::shared_ptr<Object> CameraBuilder::get_result()
{
    return std::shared_ptr<Object>(new Camera(position, direction));
}
