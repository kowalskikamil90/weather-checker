#ifndef WEATHERCHECKER_H
#define WEATHERCHECKER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>

class MyMainWindow;

class WeatherChecker : public QObject
{
    Q_OBJECT

public:

    class WeatherQuerry
    {
        QString _city;
    public:
        WeatherQuerry(): _city("Unknown") {}
        WeatherQuerry(const QString city): _city(city) {}
        QString getCity() const {return _city;}
    };

    struct WeatherResult
    {
        QString weatherMain;
        QString weatherDescr;
        double mainTemp;
        double mainTempMin;
        double mainTempMax;
        int mainPressure;
        int mainHumidity;
        int windSpeed;
        int cloudsAll;
        bool netAccess;
    };

    explicit WeatherChecker(QObject *parent = nullptr);
    void setQuerry(const WeatherQuerry querry);
    void setGui(MyMainWindow *myWindow);
    void sendQuerrySetResponse() const;
    WeatherResult getResponse() const;

signals:

public slots:
    void onResult(QNetworkReply* reply);

private:
    WeatherQuerry _querry;
    WeatherResult _result;
    MyMainWindow *_myWindow;
    QNetworkAccessManager *_networkManager;
    QUrl createUrl() const;
};

#endif // WEATHERCHECKER_H
