#ifndef FRONTEND_H
#define FRONTEND_H

#include <QMainWindow>

#include <QPushButton>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
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

private:
    Ui::frontEnd *ui;
    QList<QSerialPortInfo> ports;
};

#endif // FRONTEND_H
