#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include "cabin.h"
#include "controlPanel.h"

class lift : public QObject
{
    Q_OBJECT

public:
    lift(QObject *parent = nullptr);
    void buttonClicked(int floor);

private:
    cabin lift_cabin;
    controlPanel lift_control;
};

#endif // LIFT_H
