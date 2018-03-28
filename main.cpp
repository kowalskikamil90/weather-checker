#include <QtGui>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow myWindow;
    myWindow.show();

    return a.exec();
}
