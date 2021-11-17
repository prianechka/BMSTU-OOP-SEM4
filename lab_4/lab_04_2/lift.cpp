#include "lift.h"

lift::lift(QObject* parent) : lift_cabin(parent), lift_control(parent)
{
    QObject::connect(&lift_cabin, SIGNAL(reachedFloor(int)), &lift_control, SLOT(onFloor(int)));
    QObject::connect(&lift_cabin, SIGNAL(elevatorReady()), &lift_control, SLOT(nextTarget()));

    QObject::connect(&lift_control, SIGNAL(moveCommand(int)), &lift_cabin, SLOT(moveElevator(int)));
    QObject::connect(&lift_control, SIGNAL(stopCommand()), &lift_cabin, SLOT(stopElevator()));
}

void lift::buttonClicked(int floor)
{
    lift_control.addFloor(floor);
}
