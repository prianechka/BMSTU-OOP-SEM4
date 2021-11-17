#ifndef VISITOR_H
#define VISITOR_H

#include "../Mathobj/pixel.h"
#include "../objects/edge.h"
#include "../objects/point.h"
#include <memory>
#include <vector>
#include "objects/figure.h"
#include "objects/camera.h"
#include "../objects/data.h"
#include "./basevisitor.h"
#include "../AbstractFactory/drawer.h"
using namespace std;

class Figure;
class Camera;
class Composite;
class Scene;

class Visitor : public BaseVisitor
{
public:
    Visitor() = delete;
    Visitor(const shared_ptr<BaseDrawer> &_drawer, const shared_ptr<Camera> &_camera) : drawer(_drawer), camera(_camera) {};
    ~Visitor() = default;

    void visit(Figure &figure) override;
    void visit(const Composite &composite) override;
    void visit(const Scene &scene) override;

private:
    shared_ptr<BaseDrawer> drawer;
    shared_ptr<Camera> camera;
    Pixel proect_point(const Point &point);
};

#endif // VISITOR_H
