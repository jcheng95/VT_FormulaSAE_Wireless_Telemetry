#include "frontend.h"
#include "ui_frontend.h"

frontEnd::frontEnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frontEnd)
{
    ui->setupUi(this);

    connect(ui->serialButton, SIGNAL(clicked(bool)), this, SLOT(displayAvailablePorts()));
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(beginTelemetry()));

    this->showFullScreen();
    this->showMaximized();
}

void frontEnd::displayAvailablePorts()
{
    ports = QSerialPortInfo::availablePorts();
    Q_FOREACH(QSerialPortInfo port, ports) {
        ui->portsComboBox->addItem(port.portName());
    }
}

void frontEnd::beginTelemetry()
{
    // Hides the front end to begin data logging and telemetry
    if(ui->portsComboBox->count() != 0) {
        this->showMinimized();
    }
}

frontEnd::~frontEnd()
{
    delete ui;
}
