#include "weatherchecker.h"

WeatherChecker::WeatherChecker(WeatherQuerry querry, QObject *parent) :
    QObject(parent),
    _querry(querry)
{

}

WeatherChecker::WeatherChecker(QObject *parent) :
    QObject(parent)
{

}

void WeatherChecker::setQuerry(WeatherQuerry querry)
{
    _querry = querry;
}

WeatherResult WeatherChecker::sendQuerry()
{
    WeatherResult result;
    return result;
}
