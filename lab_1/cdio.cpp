#include "cdio.h"
#include "object.h"
#include "defines.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>


FILE *open_file(const char *file_name)
{
    FILE *result;
    result = fopen(file_name, "r");
    return result;
}

int close_file(FILE *f)
{
    int err;
    err = fclose(f);
    return err;
}


int check_file(char *name)
{
	int err = OK;
	if (name == NULL)
		err = OPEN_FILE_ERR;
	else
	{
		FILE *f;
		f = fopen(name, "r");
		if (f != OK)
			err = OPEN_FILE_ERR;
		else
			fclose(f);
	}
    printf("I am herer!");
	return err;
}


static int read_one_point(struct point &my_point, FILE *file)
{
    int error = OK;
    if (file == NULL)
        error = OPEN_FILE_ERR;
    else if (fscanf(file, "%f %f %f", &my_point.x, &my_point.y, &my_point.z) != 3)
        error = FILE_INCORRECT;
    return error;
}

static int read_one_line(struct line &my_line, FILE *file)
{
    int error = OK;
    if (file == NULL)
    	error = OPEN_FILE_ERR;
    else if (fscanf(file, "%d %d", &my_line.p_1, &my_line.p_2) != 2)
        error = FILE_INCORRECT;
    return error;
}

static int read_count(int &number, FILE *file)
{
	int error = OK;
	if (file == NULL)
		error = OPEN_FILE_ERR;
    else if (fscanf(file, "%d", &number) != 1)
		error = FILE_INCORRECT;
	else if (number <= 0)
		error = INPUT_ERR;
	return error;
}

//////////////////////////////////////////////
static int check_args(points_t &object_points, FILE *f)
{
    int error = OK;
    if (f == nullptr)
        error = OPEN_FILE_ERR;
    else if (object_points.count_points <= 0)
        error = FILE_INCORRECT;
    else if (object_points.array == nullptr)
        error = MEMORY_ERR;
    return error;
}

static int check_args(lines_t &object_lines, FILE *f)
{
    int error = OK;
    if (f == nullptr)
        error = OPEN_FILE_ERR;
    else if (object_lines.count_lines <= 0)
        error = FILE_INCORRECT;
    else if (object_lines.array == nullptr)
        error = MEMORY_ERR;
    return error;
}

static int read_array_lines(lines_t &object_lines, FILE *f)
{
    int error = check_args(object_lines, f);
    if (error == OK)
        for (int i = 0; i < object_lines.count_lines && error == OK; i++)
            error = read_one_line(object_lines.array[i], f);
    return error;
}

static int read_array_points(points_t &object_points, FILE *f)
{
    int error = check_args(object_points, f);
    if (error == OK)
        for (int i = 0; i < object_points.count_points && error == OK; i++)
            error = read_one_point(object_points.array[i], f);
    return error;
}

static int read_object_points(points_t &object_points, FILE *f)
{
    int error = OK;
    int count_points = 0;
    error = read_count(count_points, f);
    if (error == OK)
    {
        error = allocate_array_points(object_points, count_points);
        if (error == OK)
        {
            error = read_array_points(object_points, f);
            if (error != OK)
                free_array_points(object_points);
        }
    }
    return error;
}

static int read_object_lines(lines_t &object_lines, FILE *f)
{
    int error = OK;
    int count_lines = 0;
    error = read_count(count_lines, f);
    if (error == OK)
    {
        error = allocate_array_lines(object_lines, count_lines);
        if (error == OK)
        {
            error = read_array_lines(object_lines, f);
            if (error != OK)
                free_array_lines(object_lines);
        }
    }
    return error;
}

int read_object_from_file(object_t &object, char *file_name)
{
    int err = OK;
    err = check_file(file_name);
    if (err == OK)
    {
        FILE *f = open_file(file_name);
        if (f != OK)
            err = FILE_INCORRECT;
        else
        {
            err = read_object_points(object.object_points, f);
            if (err == OK)
            {
                err = read_object_lines(object.object_lines, f);
                if (err != OK)
                    free_array_points(object.object_points);
            }
            close_file(f);
        }
    }
    return err;
}

int check_points_in_line(line &one_line, int amount_of_points)
{
    int error = OK;
    if (one_line.p_1 < 0 || one_line.p_1 >= amount_of_points)
        error = LINKS_CONTAIN_INCORR_POINTS;
    else if (one_line.p_2 < 0 || one_line.p_2 >= amount_of_points)
        error = LINKS_CONTAIN_INCORR_POINTS;
    return error;
}

int check_lines(lines_t &object_lines, int amount_of_points)
{
    int error = OK;
    for (int i = 0; i < amount_of_points && error == OK; i++)
        error = check_points_in_line(object_lines.array[i], amount_of_points);
    return error;
}

int load_object(object_t &object, struct Load &lf)
{
	int err = OK;
	object_t temp_object = init_object();
	err = read_object_from_file(temp_object, lf.file_name);
	if (err == OK)
	{
        err = check_lines(temp_object.object_lines, temp_object.object_points.count_points);
		if (err == OK)
		{
			free_object(object);
            copy_object(object, temp_object);
		}

	}
	return err;
}

