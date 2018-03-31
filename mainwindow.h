#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <weatherchecker.h>

//class WeatherChecker;
//class WeatherChecker::WeatherResult;

class MyMainWindow : public QDialog
{
    Q_OBJECT

public:
    MyMainWindow(WeatherChecker *wc);
    ~MyMainWindow();
    void updateGui(WeatherChecker::WeatherResult *result);

private slots:
    void checkWeather();

private:
    QLabel *_labelCity;
    QLabel *_labelStatus;
    QLineEdit *_editCity;
    QPushButton *_buttonCheck;
    QVBoxLayout *_mainLayout;
    WeatherChecker *_weatherChecker;
};

#endif // MYMAINWINDOW_H
