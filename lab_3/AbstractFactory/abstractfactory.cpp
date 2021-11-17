#include "abstractfactory.h"

shared_ptr<BaseDrawer> QtFactory::create()
{
    return shared_ptr<BaseDrawer>(new QtDrawer(scene));
};
