#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

#include <weatherchecker.h>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void checkWeather();

private:
    QLabel *_labelCountry;
    QLabel *_labelCity;
    QLabel *_labelStatus;
    QLineEdit *_editCountry;
    QLineEdit *_editCity;
    QPushButton *_buttonCheck;
    QVBoxLayout *_mainLayout;
    WeatherChecker *_weatherChecker;
};

#endif // MAINWINDOW_H
