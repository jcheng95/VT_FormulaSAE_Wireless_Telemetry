#ifndef BACKEND_H
#define BACKEND_H

#include <QMainWindow>

#include <QSerialPort>
#include <QSerialPortInfo>
#include "xbeemessenger.h"

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

namespace Ui {
class backEnd;
}

class backEnd : public QMainWindow
{
    Q_OBJECT

public:
    explicit backEnd(QWidget *parent = 0);
    ~backEnd();

public slots:
    void changePort(QSerialPortInfo newPort);
    void beginCommunication();
    void endCommunication();

signals:
    void startRunning();
    void stopRunning();

private:
    Ui::backEnd *ui;
    QSerialPortInfo xbee;
    xbeeMessenger childThread;
};

#endif // BACKEND_H
