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

xbeeMessenger::xbeeMessenger()
{
    running = false;
}

xbeeMessenger::xbeeMessenger(QSerialPortInfo newPort)
{
    port.setPort(newPort);
    connect(&port, SIGNAL(readyRead()), this, SLOT());  // This needs a read slot
    running = false;
}

void xbeeMessenger::setPortData(QSerialPortInfo newPort)
{
    // Takes the QSerialPortInfo and converts it into QSerialPort
    port.setPort(newPort);
    connect(&port, SIGNAL(readyRead()), this, SLOT());  // This needs a read slot
}

void xbeeMessenger::startRunning()
{
    running = true;
}

void xbeeMessenger::stopRunning()
{
    running = false;
}

void xbeeMessenger::closePort()
{
    if(port.isOpen()) {
        port.close();
    }
}

void xbeeMessenger::run()
{
    // Opens the port
    if(port.open(QIODevice::ReadWrite)) {
        // Run forever or until told to stop
        while(running) {
            // Do the communication here
            /*if() {

            }*/
        }
    } else {
        // Print out some error message and end program
    }
}
