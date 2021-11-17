#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "lift.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_floor_1_clicked();

    void on_floor_2_clicked();

    void on_floor_3_clicked();

    void on_floor_4_clicked();

    void on_floor_5_clicked();

    void on_floor_6_clicked();

    void on_floor_7_clicked();

    void on_floor_8_clicked();

    void on_floor_9_clicked();

    void on_elevator_1_clicked();

    void on_elevator_2_clicked();

    void on_elevator_3_clicked();

    void on_elevator_4_clicked();

    void on_elevator_5_clicked();

    void on_elevator_6_clicked();

    void on_elevator_7_clicked();

    void on_elevator_8_clicked();

    void on_elevator_9_clicked();

private:
    Ui::MainWindow *ui;
    lift elevator;
};
#endif // MAINWINDOW_H
