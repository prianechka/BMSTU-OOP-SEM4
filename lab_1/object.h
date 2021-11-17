#ifndef OBJECT_H
#define OBJECT_H

#include <cstdlib>
#include "defines.h"

struct point
{
    float x;
    float y;
    float z;
};

struct line
{
    int p_1;
    int p_2;
};

struct points_t
{
	int count_points = 0;
	point *array;
};

struct lines_t
{
    int count_lines = 0;
    line *array;
};

struct object_t
{
	points_t object_points;
	lines_t object_lines;
};

int init_point(point &one_point);
int copy_point(point &destiny_point, point &source_point);
int init_array_points(points_t &array_all_points);
int allocate_array_points(points_t &array_all_points, int count_points);
int copy_array_points(points_t &destiny_array, points_t &source_array);
int free_array_points(points_t &array_all_points);

int init_line(line &one_line);
int copy_line(line &destiny_line, line &source_line);
int init_array_lines(lines_t &array_all_lines);
int allocate_array_lines(lines_t &lines, int count_lines);
int copy_array_lines(lines_t &destiny_array, lines_t &source_array);
int free_array_lines(lines_t &array_all_lines);

object_t &init_object(void);
int free_object(object_t &my_model);
int copy_object(object_t &destiny_model, object_t &source_model);


#endif // OBJECT_H
