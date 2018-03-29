#ifndef WEATHERQUERRY_H
#define WEATHERQUERRY_H

#include <QString>

class WeatherQuerry
{
    QString _country;
    QString _city;

public:
    WeatherQuerry(QString country, QString city);
    WeatherQuerry();
    QString getCountry();
    QString getCity();
};

#endif // WEATHERQUERRY_H
