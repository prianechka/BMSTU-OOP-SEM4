#include "drawer.h"

void QtDrawer::clear()
{
    scene->clear();
};

void QtDrawer::add_line(const Pixel &fst, const Pixel &scd)
{
    scene->addLine(fst.get_x(), fst.get_y(), scd.get_x(), scd.get_y());
}
