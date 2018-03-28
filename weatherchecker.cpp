#include "weatherchecker.h"

WeatherChecker::WeatherChecker(WeatherQuerry &querry, QObject *parent) :
    QObject(parent),
    _querry(querry)
{

}
