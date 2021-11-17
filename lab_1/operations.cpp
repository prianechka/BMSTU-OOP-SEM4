#include "operations.h"
//#include <math.h>
//#include "defines.h"
//#include "object.h"

static void substract_center_coords(point &point, struct point &center)
{
    point.x -= center.x;
    point.y -= center.y;
    point.z -= center.z;
}

static void add_center_coords(point &point, struct point &center)
{
    point.x += center.x;
    point.y += center.y;
    point.z += center.z;
}


static void move_point(point &point, struct Move &mo)
{
    point.x += mo.dx;
    point.y += mo.dy;
    point.z += mo.dz;
}


int move_points(points_t &object_points, struct Move &mo)
{
    for (int i = 0; i < object_points.count_points; i++)
        move_point(object_points.array[i], mo);
    return OK;
}

int move_object(object_t &object, struct Move &mo)
{
    int err = move_points(object.object_points, mo);
    return err;
}

static void scale_point(point &point, struct Scale &sc)
{
    point.x *= sc.kx;
    point.y *= sc.ky;
    point.z *= sc.kz;
}

int scale_points(points_t &object_points, struct Scale &sc)
{
    for (int i = 0; i < object_points.count_points; i++)
    {
        substract_center_coords(object_points.array[i], sc.center);
        scale_point(object_points.array[i], sc);
        add_center_coords(object_points.array[i], sc.center);
    }
    return OK;
}

int scale_object(object_t &object, struct Scale &sc)
{
    int err = scale_points(object.object_points, sc);
    return err;
}
static struct trig count_trig(struct Rotate &ro)
{
    struct trig tg;
    tg.cos_x = cos(ro.dgx * PI / 180);
    tg.cos_y = cos(ro.dgy * PI / 180);
    tg.cos_z = cos(ro.dgz * PI / 180);
    tg.sin_x = sin(ro.dgx * PI / 180);
    tg.sin_y = sin(ro.dgy * PI / 180);
    tg.sin_z = sin(ro.dgz * PI / 180);
    return tg;
}

static void rotate_point_x(point &point, trig &tg)
{
    double temp = point.y;
    point.y = temp * tg.cos_x + point.z * tg.sin_x;
    point.z = -temp * tg.sin_x + point.z * tg.cos_x;
}

static void rotate_point_y(point &point, trig &tg)
{
    double temp = point.x;
    point.x = temp * tg.cos_y + point.z * tg.sin_y;
    point.z = -temp * tg.sin_y + point.z * tg.cos_y;
}

static void rotate_point_z(point &point, trig &tg)
{
    double temp = point.x;
    point.x = temp * tg.cos_z + point.y * tg.sin_z;
    point.y = -temp * tg.sin_z + point.y * tg.cos_z;
}

static void rotate_point(point &point, trig &tg)
{
    rotate_point_x(point, tg);
    rotate_point_y(point, tg);
    rotate_point_z(point, tg);
}

int rotate_points(points_t &object_points, struct Rotate &ro)
{
    struct trig tg = count_trig(ro);
    for (int i = 0; i < object_points.count_points; i++)
    {
        substract_center_coords(object_points.array[i], ro.center);
        rotate_point(object_points.array[i], tg);
        add_center_coords(object_points.array[i], ro.center);
    }
    return OK;
}

int rotate_object(object_t &object, struct Rotate &ro)
{
    int err = rotate_points(object.object_points, ro);
    return err;
}
