#ifndef BACKEND_H
#define BACKEND_H

#include <QMainWindow>

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

signals:

private:
    Ui::backEnd *ui;
};

#endif // BACKEND_H
