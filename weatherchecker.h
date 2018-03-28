#ifndef WEATHERCHECKER_H
#define WEATHERCHECKER_H

#include <QObject>
#include "weatherquerry.h"

class WeatherChecker : public QObject
{
    Q_OBJECT

public:
    explicit WeatherChecker(WeatherQuerry& querry, QObject *parent = nullptr);

signals:

public slots:

private:
    WeatherQuerry _querry;
};

#endif // WEATHERCHECKER_H
