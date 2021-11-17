#include "facade.h"

void Facade::execute(shared_ptr<BaseCommand> command)
{
    command->execute();
};
