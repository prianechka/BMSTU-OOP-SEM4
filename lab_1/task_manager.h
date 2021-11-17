#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "object.h"
#include "defines.h"
#include "cdio.h"
#include "draw.h"
#include "operations.h"

enum task_num
{
    Init,
    Load,
    Draw,
    Move,
    Scale,
    Rotate,
    Quit
};

struct request
{
    task_num act;
    union
    {
        struct Load lf;
        struct Draw dr;
        struct Move mo;
        struct Scale sc;
        struct Rotate ro;
    };
};

int task_manager(request task);

#endif // TASK_MANAGER_H
