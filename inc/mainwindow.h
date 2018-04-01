#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableWidget>
#include <weatherchecker.h>

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
    QTableWidget* _table;
    WeatherChecker *_weatherChecker;
};

#endif // MYMAINWINDOW_H
