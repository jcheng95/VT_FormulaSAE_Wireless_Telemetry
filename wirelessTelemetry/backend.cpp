#include "backend.h"
#include "ui_backend.h"

backEnd::backEnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::backEnd)
{
    ui->setupUi(this);
    this->showFullScreen();
    this->showMaximized();
}

backEnd::~backEnd()
{
    delete ui;
}
