#include <QtNetwork>
#include <QTextStream> //for debugging
#include <QDebug>
#include "weatherchecker.h"

WeatherChecker::WeatherChecker(QObject *parent) :
    QObject(parent),
    _networkManager(new QNetworkAccessManager(this))
{

}

void WeatherChecker::setQuerry(WeatherQuerry querry)
{
    _querry = querry;
}

void WeatherChecker::sendQuerrySetResponse()
{
    QUrl url = createUrl();
    QNetworkRequest request;
    request.setUrl(url);
    connect(_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));

    // HTTP GET method, send request to the server
    _currentReply = _networkManager->get(request);
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

    return  (QUrl)finalUrl;
}

void WeatherChecker::onResult(QNetworkReply* reply)
{
    // Parse JSON response
    QString jsonString = (QString) reply->readAll();
    QByteArray jsonBytes = jsonString.toLocal8Bit();

    auto jsonDoc = QJsonDocument::fromJson(jsonBytes);

    if(jsonDoc.isNull()){
        qDebug()<<"Failed to create JSON doc.";
        exit(2);
    }
    if(!jsonDoc.isObject()){
        qDebug()<<"JSON is not an object.";
        exit(3);
    }

    QJsonObject jsonObj=jsonDoc.object();

    if(jsonObj.isEmpty()){
        qDebug()<<"JSON object is empty.";
        exit(4);
    }

    QVariantMap jsonMap = jsonObj.toVariantMap();
    QVariant weatherVariant = jsonMap["weather"];

    qDebug()<< "VISIBILITY: " << jsonMap["visibility"].toInt();

    QTextStream out(stdout);
    out << "ON RESULT: " << endl << _result.getResult() << endl;
}

WeatherChecker::WeatherResult WeatherChecker::getResponse()
{
    return _result;
}
