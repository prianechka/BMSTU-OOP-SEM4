#include "task_manager.h"
//#include "defines.h"
//#include "cdio.h"
//#include "error_output.h"
//#include "draw.h"
//#include "operations.h"

int task_manager(request task)
{
    int err = OK;
    static object_t object = init_object();

    switch (task.act)
    {
        case Init:
            break;
        case Load:
            err = load_object(object, task.lf);
            break;
        case Draw:
            err = draw_object(object, task.dr);
            break;
        case Move:
            err = move_object(object, task.mo);
            break;
        case Scale:
            err = scale_object(object, task.sc);
            break;
        case Rotate:
            err = rotate_object(object, task.ro);
            break;
        case Quit:
            free_object(object);
            break;
        default:
            err = UNKNOWN_COMMAND;
    }

    return err;
}
