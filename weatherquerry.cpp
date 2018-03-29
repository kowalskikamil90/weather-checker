#include "weatherquerry.h"

WeatherQuerry::WeatherQuerry(QString country, QString city):
    _country(country),
    _city(city)
{

}

WeatherQuerry::WeatherQuerry()
{

}

QString WeatherQuerry::getCountry()
{
    return _country;
}

QString WeatherQuerry::getCity()
{
    return _city;
}
