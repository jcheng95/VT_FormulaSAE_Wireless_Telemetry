#ifndef FRONTEND_H
#define FRONTEND_H

#include <QMainWindow>

#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>

namespace Ui {
class frontEnd;
}

class frontEnd : public QMainWindow
{
    Q_OBJECT

public:
    explicit frontEnd(QWidget *parent = 0);
    ~frontEnd();

public slots:
    void displayAvailablePorts();
    void beginTelemetry();

signals:
    void startBackEnd();
    void changePort(QSerialPortInfo newPort);

private:
    Ui::frontEnd *ui;
    QList<QSerialPortInfo> ports;
    QSerialPortInfo xbee;
};

#endif // FRONTEND_H
