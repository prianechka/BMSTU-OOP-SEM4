#ifndef EDGE_H
#define EDGE_H


class Edge
{
private:
    int first, second;
public:
    Edge() = default;
    Edge(int fst, int scd);

    int get_first() const;
    int get_second() const;
};

#endif // EDGE_H
