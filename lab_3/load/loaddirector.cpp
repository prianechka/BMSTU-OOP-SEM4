#include "loaddirector.h"
#include <iostream>

shared_ptr<Scene> SceneDirector::load(const string &file_name)
{
    shared_ptr<BaseSceneLoader> loader = SceneLoadSolution().get_creator()->create();

    loader->open(file_name);

    vector<shared_ptr<Object>> objects = loader->load();

    loader->close();

    shared_ptr<BaseSceneBuilder> builder = shared_ptr<BaseSceneBuilder> (new SceneBuilder);

    builder->reset();

    builder->build_objects(objects);

    shared_ptr<Scene> scene = builder->get_result();

    return scene;
}

shared_ptr<Object> CameraDirector::load(const string &file_name)
{
    loader = CameraLoadSolution().get_creator()->create();

    loader->open(file_name);

    Point position, direction;

    position = loader->read_point();
    direction = loader->read_point();

    loader->close();

    shared_ptr<BaseCameraBuilder> builder = shared_ptr<BaseCameraBuilder>(new CameraBuilder);

    builder->reset();

    builder->build_position(position);
    builder->build_direction(direction);

    shared_ptr<Object> camera = builder->get_result();

    return camera;
}


shared_ptr<Object> FigureDirector::load(const string &file_name)
{
    loader = FigureLoadSolution().get_creator()->create();

    loader->open(file_name);
    Point center;
    vector<Point> points;
    vector<Edge> edges;

    center = loader->read_point();
    points = loader->read_points();
    edges = loader->read_edges();

    loader->close();
    shared_ptr<BaseFigureBuilder> builder = shared_ptr<BaseFigureBuilder>(new FigureBuilder);
    builder->reset();
    builder->build_center(center);
    builder->build_points(points);
    builder->build_edges(edges);

    shared_ptr<Object> figure = builder->get_result();

    return figure;
}

