#include "mainwindow.h"

MyMainWindow::MyMainWindow(WeatherChecker *wc):
    _labelCity(new QLabel("Enter city name:")),
    _labelStatus(new QLabel("READY")),
    _editCity(new QLineEdit()),
    _buttonCheck(new QPushButton("CHECK!")),
    _mainLayout(new QVBoxLayout()),
    _table(new QTableWidget()),
    _weatherChecker(wc)
{
    setWindowTitle("Weather checker");

    connect(_buttonCheck, SIGNAL(clicked()), this, SLOT(checkWeather()));

    _mainLayout->addWidget(_labelCity);
    _mainLayout->addWidget(_editCity);
    _mainLayout->addWidget(_buttonCheck);
    _mainLayout->addWidget(_labelStatus);
    _mainLayout->addWidget(_table);
    _mainLayout->setGeometry(QRect(0, 0, 390, 440));

    _labelStatus->setAlignment(Qt::AlignHCenter);

    // Set initial status as: READY
    _labelStatus->setText("READY");
    _labelStatus->setStyleSheet("QLabel { color: green;}");

    this->setGeometry(QRect(0, 0, 390, 440));
    this->setLayout(_mainLayout);

    // 9 rows and 2 columns
    _table->setRowCount(9);
    _table->setColumnCount(3);

    _table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    // Set header Labels here
    _table->setHorizontalHeaderLabels(QString("Property;Description;Unit").split(";"));

    // Set first table column here
    _table->setItem(0,0,new QTableWidgetItem("GENERAL"));
    _table->setItem(1,0,new QTableWidgetItem("DESCRIPTION"));
    _table->setItem(2,0,new QTableWidgetItem("TEMPERATURE"));
    _table->setItem(3,0,new QTableWidgetItem("MIN TEMPERATURE"));
    _table->setItem(4,0,new QTableWidgetItem("MAX TEMPERATURE"));
    _table->setItem(5,0,new QTableWidgetItem("PRESSURE"));
    _table->setItem(6,0,new QTableWidgetItem("HUMIDITY"));
    _table->setItem(7,0,new QTableWidgetItem("WIND SPEED"));
    _table->setItem(8,0,new QTableWidgetItem("CLOUDS"));

    // Set last table column here
    _table->setItem(0,2,new QTableWidgetItem("N/A"));
    _table->setItem(1,2,new QTableWidgetItem("N/A"));
    _table->setItem(2,2,new QTableWidgetItem("C"));
    _table->setItem(3,2,new QTableWidgetItem("C"));
    _table->setItem(4,2,new QTableWidgetItem("C"));
    _table->setItem(5,2,new QTableWidgetItem("hPa"));
    _table->setItem(6,2,new QTableWidgetItem("%"));
    _table->setItem(7,2,new QTableWidgetItem("mph"));
    _table->setItem(8,2,new QTableWidgetItem("%"));

    _table->setColumnWidth(0, 160);
    _table->setColumnWidth(1, 150);
    _table->setColumnWidth(2, 40);

    _table->setGeometry(10, 100, 360, 360);

    // User is not able to modify the content of the table
    _table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MyMainWindow::~MyMainWindow()
{
    delete _labelCity;
    delete _labelStatus;
    delete _editCity;
    delete _buttonCheck;
    delete _mainLayout;
}

void MyMainWindow::checkWeather()
{
    QString city(_editCity->text());

    if (!city.isEmpty())
    {
        WeatherChecker::WeatherQuerry weatherQuerry(city);
        _weatherChecker->setQuerry(weatherQuerry);

        // This actually sends HTTP GET request
        _weatherChecker->sendQuerrySetResponse();

        // Status: In progress
        _labelStatus->setText("...IN PROGRESS...");
        _labelStatus->setStyleSheet("QLabel { color: blue;}");
    }
    else
    {
        // Field is not filled, do nothing apart from changing the status
        _labelStatus->setText("PLEASE, TYPE THE CITY NAME!");
        _labelStatus->setStyleSheet("QLabel { color: red;}");
    }
}

void MyMainWindow::updateGui(WeatherChecker::WeatherResult *result)
{
    // Status: Done
    _labelStatus->setText("DONE!");
    _labelStatus->setStyleSheet("QLabel { color: green;}");

    // Set values in the table
    _table->setItem(0,1,new QTableWidgetItem(QString(result->weatherMain)));
    _table->setItem(1,1,new QTableWidgetItem(QString(result->weatherDescr)));
    _table->setItem(2,1,new QTableWidgetItem(QString::number(result->mainTemp)));
    _table->setItem(3,1,new QTableWidgetItem(QString::number(result->mainTempMin)));
    _table->setItem(4,1,new QTableWidgetItem(QString::number(result->mainTempMax)));
    _table->setItem(5,1,new QTableWidgetItem(QString::number(result->mainPressure)));
    _table->setItem(6,1,new QTableWidgetItem(QString::number(result->mainHumidity)));
    _table->setItem(7,1,new QTableWidgetItem(QString::number(result->windSpeed)));
    _table->setItem(8,1,new QTableWidgetItem(QString::number(result->netAccess)));

    // Free the memory allocated in WeatherChecker class
    delete result;
}
