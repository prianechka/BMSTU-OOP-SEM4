#include "figurefileloader.h"

FigureFileLoader::FigureFileLoader()
{
    stream = shared_ptr<ifstream>(new ifstream);
}


FigureFileLoader::FigureFileLoader(const shared_ptr<ifstream> &_stream)
{
    stream = _stream;
}

void FigureFileLoader::open(const string &file_name)
{
    if (stream->is_open())
        close();
    stream->open(file_name);

    if (!stream)
    {
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        throw file_exception(ctime(&timenow), __FILE__, typeid(BaseSourceLoader).name(), __FUNCTION__);
    }
}

void FigureFileLoader::close()
{
    stream->close();
}

shared_ptr<Object> FigureFileLoader::load()
{
    shared_ptr<BaseFigureBuilder> builder = shared_ptr<BaseFigureBuilder>(new FigureBuilder);
    builder->reset();
    Point center;
    vector<Point> points;
    vector<Edge> edges;
    if (stream->is_open())
    {
        center = read_point();
        builder->build_center(center);

        points = read_points();
        builder->build_points(points);

        edges = read_edges();
        builder->build_edges(edges);
    }
    else
    {
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
        throw file_exception(ctime(&timenow), __FILE__, typeid(FigureFileLoader).name(), __FUNCTION__);
    }

    return builder->get_result();
}
