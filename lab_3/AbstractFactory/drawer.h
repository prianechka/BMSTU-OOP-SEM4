#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>
#include "../objects/point.h"
#include "../Mathobj/pixel.h"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    ~BaseDrawer() = default;

    virtual void clear() = 0;
    virtual void add_line(const Pixel &fst, const Pixel &scd) = 0;
};

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;
    ~QtDrawer() = default;

    QtDrawer(std::shared_ptr<QGraphicsScene> _scene) : scene(_scene) {};


    virtual void clear() override;
    virtual void add_line(const Pixel &fst, const Pixel &scd) override;

private:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif // DRAWER_H
