#include "frontend.h"
#include "ui_frontend.h"

frontEnd::frontEnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frontEnd)
{
    ui->setupUi(this);

    // Connections
    connect(ui->serialButton, SIGNAL(clicked(bool)), this, SLOT(displayAvailablePorts()));  // Button for getting all available serial ports
    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(beginTelemetry()));          // Button for starting telemetry data communication

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
        // Getting the correct port from the list of ports in order to
        // set the QSerialPort object to the correct port for communication.
        Q_FOREACH(QSerialPortInfo port, ports) {
            if(port.portName() == ui->portsComboBox->currentText()) {
                xbee = port;
                changePort(port);
            }
        }
        // Minimizes the - now - unnecessary window
        this->showMinimized();
        // Notifies the back end window to start working on telemetry communication
        startBackEnd();
    }
}

frontEnd::~frontEnd()
{
    delete ui;
}
