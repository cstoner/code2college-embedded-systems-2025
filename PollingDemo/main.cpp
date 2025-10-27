#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

#include "wiringPi.h"
using namespace std;

int buttonPin = 29;

void checkButton() {
    if (digitalRead(buttonPin) == 1) {
        qDebug() << "The button is pressed";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    wiringPiSetup();
    pinMode(buttonPin, INPUT);

    wiringPiISR(buttonPin, INT_EDGE_RISING, &checkButton);

    //QTimer *timer = new QTimer(&a);
    //QObject::connect(timer, &QTimer::timeout, &checkButton);
    //timer->start(100);

    return a.exec();
}
