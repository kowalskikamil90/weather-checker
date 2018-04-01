#include <QtNetwork>
#include <QMap>
#include <weatherchecker.h>
#include <mainwindow.h>

WeatherChecker::WeatherChecker(QObject *parent) :
    QObject(parent),
    _networkManager(new QNetworkAccessManager(this))
{
    connect(_networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
}

void WeatherChecker::setQuerry(const WeatherQuerry querry)
{
    _querry = querry;
}

void WeatherChecker::sendQuerrySetResponse() const
{
    QUrl url = createUrl();
    QNetworkRequest request;
    request.setUrl(url);

    /* HTTP GET method, send request to the server.
     * This will emit the 'finished' signal when done */
    _networkManager->get(request);
}

QUrl WeatherChecker::createUrl() const
{
    QString protocol("http://");

    // This is the server REST API endpoint
    QString endpoint("api.openweathermap.org/data/2.5/weather?");

    QString city(QString("q=") + _querry.getCity());

    // We will get temperature in Celcious degrees thanks to this
    QString metricCelcious("&units=metric");

    // Unique key is generated for each account on openweathermap.org
    QString apiKey("&APPID=14104519d0638a4e71f051d605519685");

    QString finalUrl(protocol + endpoint + city + metricCelcious + apiKey);

    return  (QUrl)finalUrl;
}

void WeatherChecker::onResult(QNetworkReply* reply)
{
    // Parse the JSON HTTP server response
    QString jsonString = (QString) reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();

    QJsonValue weather = jsonObject["weather"];
    QJsonArray weatherArray = weather.toArray();
    QJsonValue main = jsonObject["main"];
    QJsonValue wind = jsonObject["wind"];
    QJsonValue clouds = jsonObject["clouds"];

    // Write down values in the result struct
    WeatherChecker::WeatherResult *result = new WeatherChecker::WeatherResult();
    result->weatherMain = weatherArray[0].toObject().value("main").toString();
    result->weatherDescr = weatherArray[0].toObject().value("description").toString();
    result->mainTemp = main.toObject().value("temp").toDouble();
    result->mainTempMin = main.toObject().value("temp_min").toDouble();
    result->mainTempMax = main.toObject().value("temp_max").toDouble();
    result->mainPressure = main.toObject().value("pressure").toInt();
    result->mainHumidity = main.toObject().value("humidity").toInt();
    result->windSpeed = wind.toObject().value("speed").toInt();
    result->cloudsAll = clouds.toObject().value("all").toInt();

    // Update all values in GUI widgets based on results
    _myWindow->updateGui(result);

    /* According to QT documentation this object shouldn't be deleted
     * here directly. Instead, deleteLater() function should be called
     * to delete the object automatically when control is returned to
     * the event loop */
    reply->deleteLater();
}

WeatherChecker::WeatherResult WeatherChecker::getResponse() const
{
    return _result;
}

void WeatherChecker::setGui(MyMainWindow* myWindow)
{
    _myWindow = myWindow;
}
