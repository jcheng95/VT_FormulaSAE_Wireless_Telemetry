#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "frontend.h"
#include "backend.h"

class controller : public QWidget
{
public:
    controller();
    void start();
private:
    backEnd BEW;
    frontEnd FEW;
};

#endif // CONTROLLER_H
