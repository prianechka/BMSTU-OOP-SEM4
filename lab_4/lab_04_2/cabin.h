#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QTimer>
#include "direction.h"
#include "doors.h"

enum cabin_state
{
    MOVING,
    STAYING,
    READY,
    CHANGED_FLOOR,
};

class cabin : public QObject
{
    Q_OBJECT

public:
    explicit cabin(QObject *parent = nullptr);

protected:
    int curFloor;
    int nextFloor;
    cabin_state state;

    QTimer movingTime;
    QTimer stopTime;
    doors cabin_doors;

signals:
    void elevatorMoving();
    void elevatorStoped();
    void reachedFloor(int floor);
    void elevatorReady();

public slots:
    void moveElevator(int direction);
    void stopElevator();
    void changedFloor();
    void floorCompleted();
};

#endif // CABIN_H
