#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <memory>
#include "drawer.h"

using namespace std;

class AbstractFactory
{
public:
    AbstractFactory() = default;
    ~AbstractFactory() = default;

    virtual shared_ptr<BaseDrawer> create() = 0;
};

class QtFactory : public AbstractFactory
{
public:
    QtFactory(shared_ptr<QGraphicsScene> _scene) : scene(_scene) {};
    ~QtFactory() = default;

    virtual shared_ptr<BaseDrawer> create() override;
private:
    shared_ptr<QGraphicsScene> scene;
};

#endif // ABSTRACTFACTORY_H
