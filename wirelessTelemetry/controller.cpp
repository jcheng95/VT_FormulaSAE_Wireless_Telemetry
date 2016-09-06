#include "controller.h"

controller::controller()
{
    // Make all connections here
    connect(&FEW, SIGNAL(startBackEnd()), &BEW, SLOT(beginCommunication()));    // Connection for the front end to initiate the work of the back end
    connect(&FEW, SIGNAL(changePort(QSerialPortInfo)), &BEW, SLOT(changePort(QSerialPortInfo)));    // Connection to pass around the instance of the serial port
}

void controller::start()
{
    FEW.show();
    BEW.show();
}

