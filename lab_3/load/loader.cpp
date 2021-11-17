#include "loader.h"

Point BaseSourceLoader::read_point()
{
    double x, y, z;

    if (!(*stream >> x >> y >> z))
    {
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        throw file_exception(ctime(&timenow), __FILE__, typeid(BaseSourceLoader).name(), __FUNCTION__);
    }

    return Point(x, y, z);
}

Edge BaseSourceLoader::read_edge()
{
    int fst, scd;

    if (!(*stream >> fst >> scd))
    {
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        throw file_exception(ctime(&timenow), __FILE__, typeid(BaseSourceLoader).name(), __FUNCTION__);
    }

    return Edge(fst - 1, scd - 1);
}

int BaseSourceLoader::read_number()
{
    int num;

    if (!(*stream >> num))
    {
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        throw file_exception(ctime(&timenow), __FILE__, typeid(BaseSourceLoader).name(), __FUNCTION__);
    }

    return num;
}

vector<Point> BaseSourceLoader::read_points()
{
    vector<Point> points;

    int count = read_number();

    for (int i = 0; i < count; i++)
        points.push_back(read_point());
    return points;
}

vector<Edge> BaseSourceLoader::read_edges()
{
    vector<Edge> edges;

    int count = read_number();

    for (int i = 0; i < count; i++)
        edges.push_back(read_edge());

    return edges;
}
