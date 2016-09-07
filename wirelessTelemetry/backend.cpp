#include "backend.h"
#include "ui_backend.h"

/*
 * API Mode
 Byte #     Value       Byte detail
________________________________________
 Byte 1     0x7E        Start delimiter
 Byte 2     MSB         Message length
 Byte 3     LSB         Message length
 Byte 4-n   Values      Frame data
 Byte n+1   1 Byte      Checksum
 ________________________________________

 * Escape characters
 Value      Byte detail
________________________________________
 0x7E       Frame delimiter
 0x7D       Escape
 0x11       XON
 0x13       XOFF
________________________________________

 * Checksum calculation:
0xFF - (all bytes without bytes 1-3)
 * Checksum verification:
Sum all bytes without bytes 1-3 (includes checksum) which should be equal to 0xFF
*/

backEnd::backEnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::backEnd)
{
    ui->setupUi(this);
    this->showFullScreen();
    this->showMaximized();

    connect(this, SIGNAL(stopRunning()), &childThread, SLOT(stopRunning()));            // Connection to enable the xbeeMessenger object
    connect(this, SIGNAL(startRunning()), &childThread, SLOT(startRunning()));          // Connection to disable the xbeeMessenger object
    connect(ui->playButton, SIGNAL(clicked(bool)), this, SLOT(beginCommunication()));   // Connection to use the play button to enable the xbeeMessenger object
    connect(ui->pauseButton, SIGNAL(clicked(bool)), this, SLOT(endCommunication()));    // Connection to use the pause button to disable the xbeeMessenger object
    connect(ui->stopButton, SIGNAL(clicked(bool)), &childThread, SLOT(closePort()));    // Connection to end communication entirely
}

void backEnd::changePort(QSerialPortInfo newPort)
{
    xbee = newPort;
    childThread.setPortData(newPort);
}

void backEnd::beginCommunication()
{
    startRunning(); // Signal to the xbeeMessenger object to enable message passing
    //childThread.run();    // Tells the xbeeMessenger to start running the algorithm for message passing
}

void backEnd::endCommunication()
{
    stopRunning();  // Signal to the xbeeMessenger object to disable message passing
}

backEnd::~backEnd()
{
    delete ui;
}
