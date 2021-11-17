#ifndef DATA_H
#define DATA_H

#include "point.h"
#include "edge.h"

#include <vector>

using namespace std;

class Data
{
public:
    Data() = default;
    void add_point(double x, double y, double z);
    void add_point(const Point &point);
    void add_edge(int first, int second);
    void add_edge(const Edge &edge);
    void add_center(double x, double y, double z);
    void add_center(const Point &point);

    void transfer(const Point &transfer);
    void rotate(const Angle &angle);
    void scale(const ScaleCoef &scale);

    const vector<Point> &get_points() const;
    const vector<Edge> &get_edges() const;

    void clear();
private:
    vector<Point> points;
    vector<Edge> edges;
    Point center;
};

#endif // DATA_H
