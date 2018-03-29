#include "weatherchecker.h"
#include <QtNetwork>
#include <QTextStream>

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

void WeatherChecker::sendQuerrySetResponse()
{
    QNetworkAccessManager networkManager;
    QUrl url = createUrl();
    QNetworkRequest request;
    request.setUrl(url);
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
    networkManager.get(request);  // GET method
}

QUrl WeatherChecker::createUrl()
{
    QString protocol("http://");
    QString endpoint("api.openweathermap.org/data/2.5/weather?");
    QString city(QString("q=") + _querry.getCity());
    QString metricCelcious("&units=metric");
    QString apiKey("&APPID=14104519d0638a4e71f051d605519685");
    QString finalUrl(protocol + endpoint + city + metricCelcious + apiKey);
    QTextStream out(stdout);
    out << "CREATE URL: " << endl << finalUrl << endl;
    return  finalUrl;
}

void WeatherChecker::onResult(QNetworkReply* reply)
{
    _result.data = (QString) reply->readAll();
    QTextStream out(stdout);
    out << "ON RESULT: " << endl << _result.data << endl;
}

WeatherResult WeatherChecker::getResponse()
{
    return _result;
}
