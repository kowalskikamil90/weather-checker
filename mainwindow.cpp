#include "mainwindow.h"
#include "weatherquerry.h"
#include "weatherresult.h"
//#include <QTextStream>

MainWindow::MainWindow():
    _labelCountry(new QLabel("Enter country name:")),
    _labelCity(new QLabel("Enter city name:")),
    _labelStatus(new QLabel("READY")),
    _editCountry(new QLineEdit()),
    _editCity(new QLineEdit()),
    _buttonCheck(new QPushButton("CHECK!")),
    _mainLayout(new QVBoxLayout()),
    _weatherChecker(new WeatherChecker())
{
    setWindowTitle("Weather checker");

    connect(_buttonCheck, SIGNAL(clicked()), this, SLOT(checkWeather()));

    _mainLayout->addWidget(_labelCountry);
    _mainLayout->addWidget(_editCountry);
    _mainLayout->addWidget(_labelCity);
    _mainLayout->addWidget(_editCity);
    _mainLayout->addWidget(_buttonCheck);
    _mainLayout->addWidget(_labelStatus);
    setLayout(_mainLayout);

}

MainWindow::~MainWindow()
{
    delete _labelCountry;
    delete _labelCity;
    delete _labelStatus;
    delete _editCountry;
    delete _editCity;
    delete _buttonCheck;
    delete _mainLayout;
    delete _weatherChecker;
}

void MainWindow::checkWeather()
{
    QString country(_editCountry->text());
    QString city(_editCity->text());

//    QTextStream out(stdout);
//    out << "Country" << editCountry->text() << endl;
//    out << "city" << editCity->text() << endl;

    if (!country.isEmpty() && !city.isEmpty())
    {
        // Fields are filled, the querry may be processed
        _labelStatus->setText("Processing request...");
        _labelStatus->setStyleSheet("QLabel { color: green;}");

        WeatherQuerry weatherQuerry(country, city);
        _weatherChecker->setQuerry(weatherQuerry);

        // This actually sends HTTP GET request
        WeatherResult weatherResult = _weatherChecker->sendQuerry();

        // Parsing of the results
        _labelStatus->setText("Service not available!");
        _labelStatus->setStyleSheet("QLabel { color: red;}");
    }
    else {
        // Fields are not filled, do nothing apart from changing the status
        _labelStatus->setText("Fill both country and city!");
        _labelStatus->setStyleSheet("QLabel { color: red;}");
    }
}
