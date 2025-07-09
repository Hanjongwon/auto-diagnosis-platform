#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QPushButton>
#include <qwidget.h>
#include <QDesktopWidget>
#include <pigpio.h>
#include <QtSql>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    //w.setWindowFlags(Qt::Widget | QT::FramelessWindowHint);
    gpioInitialise();

        if (gpioInitialise() < 0)
           {
              fprintf(stderr, "pigpio initialisation failed\n");
              return 1;
           }
        else
        {
            fprintf(stderr, "pigpio initialisation passed\n");
        }

        gpioSetMode(23, PI_OUTPUT);
        gpioSetPWMfrequency(23,200);
        gpioSetPWMrange(23,2500);
        gpioServo(23,2100);
        time_sleep(9);

    return a.exec();
}
