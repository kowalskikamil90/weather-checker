#ifndef WEATHERCHECKER_H
#define WEATHERCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>

//class WeatherQuerry;
//class WeatherResult;

class WeatherChecker : public QObject
{
    Q_OBJECT

public:

    class WeatherQuerry
    {
        QString _city;
    public:
        WeatherQuerry(): _city("Unknown") {}
        WeatherQuerry(QString city): _city(city) {}
        QString getCity() {return _city;}
    };

    class WeatherResult
    {
        QString _result;
    public:
        WeatherResult(): _result("Unknown") {}
        WeatherResult(QString result): _result(result) {}
        QString getResult() {return _result;}
        void setResult(QString result) {_result = result;}
    };

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
    QNetworkReply *_currentReply;
    QNetworkAccessManager *_networkManager;
    QUrl createUrl();
};

#endif // WEATHERCHECKER_H
