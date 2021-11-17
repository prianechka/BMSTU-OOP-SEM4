#include "cabin.h"
#include <QDebug>
#include <iostream>

cabin::cabin(QObject *parent) : QObject(parent), \
                                curFloor(1), state(READY)
{
    QObject::connect(&cabin_doors, SIGNAL(doorsClosed()), this, SLOT(floorCompleted()));
    QObject::connect(this, SIGNAL(elevatorStoped()), &cabin_doors, SLOT(openDoors()));

    movingTime.setSingleShot(true);
    movingTime.setInterval(3000);
    QObject::connect(this, SIGNAL(elevatorMoving()), &movingTime, SLOT(start()));
    QObject::connect(&movingTime, SIGNAL(timeout()), this, SLOT(changedFloor()));
}

void cabin::stopElevator()
{
    if (state == CHANGED_FLOOR || state == READY)
    {
        if (state == CHANGED_FLOOR)
            std::cout << "Лифт остановился." << std::endl;
        state = STAYING;
        emit elevatorStoped();
    }
}

void cabin::moveElevator(int direction)
{
    if (state == CHANGED_FLOOR || state == READY)
    {
        if (direction == UP || direction == DOWN)
        {
            if (state == READY)
                std::cout << curFloor << " этаж. " << (direction == UP ? "Подъем." : "Спуск")  << std::endl;

            nextFloor = curFloor + direction;
            state = MOVING;
            emit elevatorMoving();
        }
    }
}

void cabin::changedFloor()
{
    if (state == MOVING)
    {
        std::cout << nextFloor << " этаж" << std::endl;
        curFloor = nextFloor;
        state = CHANGED_FLOOR;
        emit reachedFloor(curFloor);
    }
}

void cabin::floorCompleted()
{
    if (state == STAYING)
    {
        state = READY;
        emit elevatorReady();
    }
}
