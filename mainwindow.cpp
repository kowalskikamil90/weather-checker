#include "mainwindow.h"
#include <QTextStream>

MainWindow::MainWindow(WeatherChecker *wc):
    _labelCity(new QLabel("Enter city name:")),
    _labelStatus(new QLabel("READY")),
    _editCity(new QLineEdit()),
    _buttonCheck(new QPushButton("CHECK!")),
    _mainLayout(new QVBoxLayout()),
    _weatherChecker(wc)
{
    setWindowTitle("Weather checker");

    connect(_buttonCheck, SIGNAL(clicked()), this, SLOT(checkWeather()));

    _mainLayout->addWidget(_labelCity);
    _mainLayout->addWidget(_editCity);
    _mainLayout->addWidget(_buttonCheck);
    _mainLayout->addWidget(_labelStatus);
    setLayout(_mainLayout);
}

MainWindow::~MainWindow()
{
    delete _labelCity;
    delete _labelStatus;
    delete _editCity;
    delete _buttonCheck;
    delete _mainLayout;
}

void MainWindow::checkWeather()
{
    QString city(_editCity->text());

    if (!city.isEmpty())
    {
        // Field is filled, the querry may be processed
        _labelStatus->setText("Processing request...");
        _labelStatus->setStyleSheet("QLabel { color: green;}");

        WeatherChecker::WeatherQuerry weatherQuerry(city);
        _weatherChecker->setQuerry(weatherQuerry);

        // This actually sends HTTP GET request
        _weatherChecker->sendQuerrySetResponse();

        // Status: In progress
        _labelStatus->setText("In progress!");
        _labelStatus->setStyleSheet("QLabel { color: blue;}");
    }
    else
    {
        // Field is not filled, do nothing apart from changing the status
        _labelStatus->setText("Fill both country and city!");
        _labelStatus->setStyleSheet("QLabel { color: red;}");
    }
}
