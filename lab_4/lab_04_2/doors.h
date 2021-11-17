#ifndef ELEVATOR_DOORS_H
#define ELEVATOR_DOORS_H

#include <QObject>
#include <QTimer>

enum doors_state
{
    OPENED,
    CLOSED,
    OPENING,
    CLOSING
};

class doors : public QObject
{
    Q_OBJECT

public:
    explicit doors(QObject *parent = nullptr);

protected:
    doors_state state;
    QTimer openingTimer;
    QTimer closingTimer;
    QTimer waitingTimer;

signals:
    void doorsClosed();
    void doorsOpened();

public slots:
    void closeDoors();
    void openDoors();
    void finishClosing();
    void finishOpening();
};

#endif // ELEVATOR_DOORS_H
