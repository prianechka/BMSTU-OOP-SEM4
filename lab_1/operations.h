#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <math.h>
#include "defines.h"
#include "object.h"

struct Move
{
    float dx;
    float dy;
    float dz;
};

struct Scale
{
    float kx;
    float ky;
    float kz;
    point center;
};

struct Rotate
{
    int dgx;
    int dgy;
    int dgz;
    point center;
};

struct trig
{
    float cos_x;
    float cos_y;
    float cos_z;
    float sin_x;
    float sin_y;
    float sin_z;
};

int move_object(object_t &object, struct Move &mo);
int scale_object(object_t &object, struct Scale &sc);
int rotate_object(object_t &object, struct Rotate &ro);

#endif // OPERATIONS_H
