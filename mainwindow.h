#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class MainWindow : public QDialog
{
      Q_OBJECT
public:
    MainWindow();

private slots:
    void checkWeather();

private:
    QLabel *labelCountry;
    QLabel *labelCity;
    QLabel *labelStatus;
    QLineEdit *editCountry;
    QLineEdit *editCity;
    QPushButton *buttonCheck;
    QVBoxLayout *mainLayout;
};

#endif // MAINWINDOW_H
