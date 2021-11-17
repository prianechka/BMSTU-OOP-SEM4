#ifndef CDIO_H
#define CDIO_H

#include "object.h"
#include "defines.h"
#include <cstdlib>
#include <cstdio>

struct Load
{
    char *file_name;
};

int load_object(object_t &object, struct Load &lf);

#endif // CDIO_H
