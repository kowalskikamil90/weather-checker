#ifndef WEATHERCHECKER_H
#define WEATHERCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include "weatherquerry.h"
#include "weatherresult.h"

class WeatherChecker : public QObject
{
    Q_OBJECT

public:
    explicit WeatherChecker(WeatherQuerry querry, QObject *parent = nullptr);
    explicit WeatherChecker(QObject *parent = nullptr);
    void setQuerry(WeatherQuerry querry);
    WeatherResult getResponse();
    void sendQuerrySetResponse();

signals:

public slots:
    void onResult(QNetworkReply* reply);

private:
    WeatherQuerry _querry;
    WeatherResult _result;
    QUrl createUrl();
};

#endif // WEATHERCHECKER_H
