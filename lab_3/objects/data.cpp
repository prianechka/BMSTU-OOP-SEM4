#include "data.h"

void Data::add_point(double x, double y, double z)
{
    points.push_back(Point(x, y, z));
};

void Data::add_point(const Point &point)
{
    points.push_back(point);
};

void Data::add_edge(int first, int second)
{
    edges.push_back(Edge(first, second));
};

void Data::add_edge(const Edge &edge)
{
    edges.push_back(edge);
};

void Data::add_center(double x, double y, double z)
{
    center = Point(x, y, z);
};

void Data::add_center(const Point &point)
{
    center = point;
};

const vector<Point> &Data::get_points() const
{
    return points;
};

const vector<Edge> &Data::get_edges() const
{
    return edges;
};

void Data::transfer(const Point &transfer)
{
    center.transfer(transfer);
    for (auto &point : points)
        point.transfer(transfer);
}


void Data::rotate(const Angle &angle)
{
    for (auto &point : points)
        point.rotate(center, angle);
}

void Data::scale(const ScaleCoef &scale)
{
    for (auto &point : points)
        point.scale(center, scale);
}

void Data::clear()
{
    points.clear();
    edges.clear();
};
