#include "edge.h"

Edge::Edge(int fst, int scd)
{
    first = fst;
    second = scd;
};

int Edge::get_first() const
{
    return first;
};

int Edge::get_second() const
{
    return second;
};
