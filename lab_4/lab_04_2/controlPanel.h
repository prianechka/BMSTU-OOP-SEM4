#ifndef ELEVATOR_CONTROL_H
#define ELEVATOR_CONTROL_H

#include <QObject>
#include <QVector>
#include "direction.h"

enum target_state
{
    NO_TARGET,
    HAS_TARGET,
    GO_TO_TARGET,
    NEW_FLOOR,
};

class controlPanel : public QObject
{
    Q_OBJECT

public:
    explicit controlPanel(QObject *parent);
    void addFloor(int number);

protected:
    bool findTarget();

    const int floorsAmount;
    QVector<bool> floorVector;
    target_state state;

    int currentFloor;
    int currentTarget;
    direction moving;

signals:
    void newTarget(int floor);
    void moveCommand(int moving);
    void stopCommand();
    void targetGo();

public slots:
    void checkTarget(int floor);
    void solveTarget();
    void onFloor(int floor);
    void nextTarget();
};

#endif // ELEVATOR_CONTROL_H
