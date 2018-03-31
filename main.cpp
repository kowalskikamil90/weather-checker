#include <QtGui>
#include <QApplication>
#include "mainwindow.h"
#include "weatherchecker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WeatherChecker *wc = new WeatherChecker(&app);
    MainWindow myWindow(wc);
    myWindow.show();

    return app.exec();
}
