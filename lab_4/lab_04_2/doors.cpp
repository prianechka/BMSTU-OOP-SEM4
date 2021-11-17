#include "doors.h"
#include <QDebug>
#include <iostream>

doors::doors(QObject *parent) : QObject(parent), state(CLOSED)
{
    openingTimer.setSingleShot(true);
    openingTimer.setInterval(2000);
    QObject::connect(&openingTimer, SIGNAL(timeout()), this, SLOT(finishOpening()));

    closingTimer.setSingleShot(true);
    closingTimer.setInterval(2000);
    QObject::connect(&closingTimer, SIGNAL(timeout()), this, SLOT(finishClosing()));

    waitingTimer.setSingleShot(true);
    waitingTimer.setInterval(2000);
    QObject::connect(this, SIGNAL(doorsOpened()), &waitingTimer, SLOT(start()));
    QObject::connect(&waitingTimer, SIGNAL(timeout()), this, SLOT(closeDoors()));
}

void doors::openDoors()
{
    if (state == CLOSED)
    {
        std::cout << "Двери открываются" << std::endl;
        state = OPENING;
        openingTimer.start();
    }
}

void doors::finishOpening()
{
    if (state == OPENING)
    {
        std::cout << "Двери открыты. Ожидание." << std::endl;
        state = OPENED;
        emit doorsOpened();
    }
}

void doors::closeDoors()
{
    if (state == OPENED)
    {
        std::cout << "Двери закрываются"  << std::endl;
        state = CLOSING;
        closingTimer.start();
    }
}

void doors::finishClosing()
{
    if (state == CLOSING)
    {
        std::cout << "Двери закрыты."  << std::endl;
        state = CLOSED;
        emit doorsClosed();
    }
}
