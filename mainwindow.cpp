#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("Weather checker");

    labelCountry = new QLabel("Enter country name:");
    labelCity = new QLabel("Enter city name:");
    buttonCheck = new QPushButton("CHECK!");
    editCountry = new QLineEdit();
    editCity = new QLineEdit();
    labelStatus = new QLabel("READY");

    connect(buttonCheck, SIGNAL(clicked()), this, SLOT(checkWeather()));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(labelCountry);
    mainLayout->addWidget(editCountry);
    mainLayout->addWidget(labelCity);
    mainLayout->addWidget(editCity);
    mainLayout->addWidget(buttonCheck);
    mainLayout->addWidget(labelStatus);
    setLayout(mainLayout);

}

void MainWindow::checkWeather()
{
    labelStatus->setText("DONE");
}
