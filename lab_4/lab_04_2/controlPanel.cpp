#include "controlPanel.h"
#include <QDebug>
#include <iostream>

controlPanel::controlPanel(QObject* parent) :
    QObject(parent), floorsAmount(9), floorVector(floorsAmount, false),
    state(NO_TARGET), currentFloor(1), currentTarget(1), moving(UP)
{
    QObject::connect(this, SIGNAL(newTarget(int)), this, SLOT(checkTarget(int)));
    QObject::connect(this, SIGNAL(targetGo()), this, SLOT(solveTarget()));
}


void controlPanel::addFloor(int number)
{
    if (number > 0 and number <= floorsAmount)
    {
        if (floorVector[number - 1])
            std::cout << "Этаж " << number << " уже был выбран"  << std::endl;
        else
        {
            floorVector[number - 1] = true;
            emit newTarget(number);
        }
    }
}

void controlPanel::checkTarget(int floor)
{
    if (state == NO_TARGET)
    {
        state = HAS_TARGET;
        currentTarget = floor;
        if (currentFloor < currentTarget)
            moving = UP;
        else if (currentFloor > currentTarget)
            moving = DOWN;
        emit targetGo();
    }
}

void controlPanel::solveTarget()
{
    if (state == HAS_TARGET || state == NEW_FLOOR)
    {
        state = GO_TO_TARGET;
        if (currentFloor == currentTarget)
        {
            floorVector[currentFloor - 1] = false;
            emit stopCommand();
        }
        else
            emit moveCommand(moving);
    }
}

void controlPanel::onFloor(int floor)
{
    if (state == GO_TO_TARGET)
    {
        state = NEW_FLOOR;
        currentFloor = floor;
        emit targetGo();
    }
}

void controlPanel::nextTarget()
{
    if (state == GO_TO_TARGET)
    {
        state = NO_TARGET;
        if (!findTarget())
            std::cout << "Ожидание вызовов." << std::endl;
        else
            emit newTarget(currentTarget);
    }
}


bool controlPanel::findTarget()
{
    bool found = false;
    if (floorVector[currentFloor - 1])
        found = true;

    int limit = moving == UP ? floorsAmount + 1: 0;
    for (int floor = currentFloor; floor != limit && !found; floor += moving)
    {
        if (floorVector[floor - 1])
        {
            currentTarget = floor;
            found = true;
        }
    }

    limit = limit == 0 ? floorsAmount + 1: 0;
    for (int floor = currentFloor; floor != limit && !found; floor -= moving)
    {
        if (floorVector[floor - 1])
        {
            currentTarget = floor;
            found = true;
        }
    }
    return found;
}
