#ifndef XBEEMESSENGER_H
#define XBEEMESSENGER_H

#include <QObject>
#include <QWidget>

#include <QSerialPort>
#include <QSerialPortInfo>

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

class xbeeMessenger : public QWidget
{
public:
    xbeeMessenger();
    xbeeMessenger(QSerialPortInfo newPort);

    void run();
    void setPortData(QSerialPortInfo newPort);

public slots:
    void startRunning();
    void stopRunning();
    void closePort();

signals:

private:
    QSerialPort port;
    bool running;
};

#endif // XBEEMESSENGER_H
