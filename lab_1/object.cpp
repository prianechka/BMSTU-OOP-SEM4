#include "object.h"
//#include <cstdlib>
//#include "defines.h"

int init_point(point &one_point)
{
    one_point.x = 0;
    one_point.y = 0;
    one_point.z = 0;
    return OK;
}

int copy_point(point &destiny_point, point &source_point)
{
    destiny_point.x = source_point.x;
    destiny_point.y = source_point.y;
    destiny_point.z = source_point.z;
    return OK;
}


int init_array_points(points_t &array_all_points)
{
    array_all_points.array = nullptr;
    array_all_points.count_points = 0;
    return OK;
}

int allocate_array_points(points_t &array_all_points, int count_points)
{
    int err = OK;
    array_all_points.count_points = count_points;
    array_all_points.array = (point *)malloc(sizeof(point) * count_points);
    if (array_all_points.array == nullptr)
        err = MEMORY_ERR;
    return err;
}

int copy_array_points(points_t &destiny_array, points_t &source_array)
{
    destiny_array.count_points = source_array.count_points;
    destiny_array.array = source_array.array;
    return OK;
}

int free_array_points(points_t &array_all_points)
{
    if (array_all_points.array != nullptr)
        free(array_all_points.array);
    init_array_points(array_all_points);
    return OK;
}

int init_line(line &one_line)
{
    one_line.p_1 = 0;
    one_line.p_2 = 0;
    return OK;
}

int copy_line(line &destiny_line, line &source_line)
{
    destiny_line.p_1 = source_line.p_1;
    destiny_line.p_2 = source_line.p_2;
    return OK;
}


int init_array_lines(lines_t &array_all_lines)
{
    array_all_lines.count_lines = 0;
    array_all_lines.array = nullptr;
    return OK;
}

int allocate_array_lines(lines_t &lines, int count_lines)
{
    int err = OK;
    lines.count_lines = count_lines;
    lines.array = (line *)malloc(sizeof(line) * count_lines);
    if (lines.array == nullptr)
        err = MEMORY_ERR;
    return err;
}


int copy_array_lines(lines_t &destiny_array, lines_t &source_array)
{
    destiny_array.count_lines = source_array.count_lines;
    destiny_array.array = source_array.array;
    return OK;
}

int free_array_lines(lines_t &array_all_lines)
{
    if (array_all_lines.array != nullptr)
        free(array_all_lines.array);
    init_array_lines(array_all_lines);
    return OK;
}

object_t& init_object()
{
    static object_t my_object;
    init_array_points(my_object.object_points);
    init_array_lines(my_object.object_lines);
    return my_object;
}

int free_object(object_t &my_model)
{
    free_array_points(my_model.object_points);
    free_array_lines(my_model.object_lines);
    return OK;
}

int copy_object(object_t &destiny_model, object_t &source_model)
{
    copy_array_points(destiny_model.object_points, source_model.object_points);
    copy_array_lines(destiny_model.object_lines, source_model.object_lines);
    return OK;
}
