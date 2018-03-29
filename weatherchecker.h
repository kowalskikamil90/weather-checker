#ifndef WEATHERCHECKER_H
#define WEATHERCHECKER_H

#include <QObject>
#include "weatherquerry.h"
#include "weatherresult.h"

class WeatherChecker : public QObject
{
    Q_OBJECT

public:
    explicit WeatherChecker(WeatherQuerry querry, QObject *parent = nullptr);
    explicit WeatherChecker(QObject *parent = nullptr);
    void setQuerry(WeatherQuerry querry);
    WeatherResult sendQuerry();

signals:

public slots:

private:
    WeatherQuerry _querry;
};

#endif // WEATHERCHECKER_H
