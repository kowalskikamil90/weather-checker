#include "mainwindow.h"
#include "weatherquerry.h"

MainWindow::MainWindow():
    labelCountry(new QLabel("Enter country name:")),
    labelCity(new QLabel("Enter city name:")),
    labelStatus(new QLabel("READY")),
    editCountry(new QLineEdit()),
    editCity(new QLineEdit()),
    buttonCheck(new QPushButton("CHECK!")),
    mainLayout(new QVBoxLayout())
{
    setWindowTitle("Weather checker");

    connect(buttonCheck, SIGNAL(clicked()), this, SLOT(checkWeather()));

    mainLayout->addWidget(labelCountry);
    mainLayout->addWidget(editCountry);
    mainLayout->addWidget(labelCity);
    mainLayout->addWidget(editCity);
    mainLayout->addWidget(buttonCheck);
    mainLayout->addWidget(labelStatus);
    setLayout(mainLayout);

}

MainWindow::~MainWindow()
{
    delete labelCountry;
    delete labelCity;
    delete labelStatus;
    delete editCountry;
    delete editCity;
    delete buttonCheck;
    delete mainLayout;
    delete weatherChecker;
}

void MainWindow::checkWeather()
{
    WeatherQuerry weatherQuerry(labelCountry->text(), labelCity->text());
    weatherChecker = new WeatherChecker(weatherQuerry);
    labelStatus->setText("DONE");
}
