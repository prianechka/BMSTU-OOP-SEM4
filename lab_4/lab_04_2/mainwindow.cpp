#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_floor_1_clicked()
{
    std::cout << "Нажата кнопка на 1 этаже" << std::endl;
    elevator.buttonClicked(1);
}

void MainWindow::on_floor_2_clicked()
{
    std::cout << "Нажата кнопка на 2 этаже" << std::endl;
    elevator.buttonClicked(2);
}

void MainWindow::on_floor_3_clicked()
{
    std::cout << "Нажата кнопка на 3 этаже" << std::endl;
    elevator.buttonClicked(3);
}

void MainWindow::on_floor_4_clicked()
{
    std::cout << "Нажата кнопка на 4 этаже" << std::endl;
    elevator.buttonClicked(4);
}

void MainWindow::on_floor_5_clicked()
{
    std::cout << "Нажата кнопка на 5 этаже" << std::endl;
    elevator.buttonClicked(5);
}

void MainWindow::on_floor_6_clicked()
{
    std::cout << "Нажата кнопка на 6 этаже" << std::endl;
    elevator.buttonClicked(6);
}

void MainWindow::on_floor_7_clicked()
{
    std::cout << "Нажата кнопка на 7 этаже" << std::endl;
    elevator.buttonClicked(7);
}

void MainWindow::on_floor_8_clicked()
{
    std::cout << "Нажата кнопка на 8 этаже" << std::endl;
    elevator.buttonClicked(8);
}

void MainWindow::on_floor_9_clicked()
{
    std::cout << "Нажата кнопка на 9 этаже" << std::endl;
    elevator.buttonClicked(9);
}

void MainWindow::on_elevator_1_clicked()
{
    std::cout << "Выбран 1 этаж" << std::endl;
    elevator.buttonClicked(1);
}

void MainWindow::on_elevator_2_clicked()
{
    std::cout << "Выбран 2 этаж" << std::endl;
    elevator.buttonClicked(2);
}

void MainWindow::on_elevator_3_clicked()
{
    std::cout << "Выбран 3 этаж" << std::endl;
    elevator.buttonClicked(3);
}

void MainWindow::on_elevator_4_clicked()
{
    std::cout << "Выбран 4 этаж" << std::endl;
    elevator.buttonClicked(4);
}

void MainWindow::on_elevator_5_clicked()
{
    std::cout << "Выбран 5 этаж" << std::endl;
    elevator.buttonClicked(5);
}

void MainWindow::on_elevator_6_clicked()
{
    std::cout << "Выбран 6 этаж" << std::endl;
    elevator.buttonClicked(6);
}

void MainWindow::on_elevator_7_clicked()
{
    std::cout << "Выбран 7 этаж" << std::endl;
    elevator.buttonClicked(7);
}

void MainWindow::on_elevator_8_clicked()
{
    std::cout << "Выбран 8 этаж" << std::endl;
    elevator.buttonClicked(8);
}

void MainWindow::on_elevator_9_clicked()
{
    std::cout << "Выбран 9 этаж" << std::endl;
    elevator.buttonClicked(9);
}
