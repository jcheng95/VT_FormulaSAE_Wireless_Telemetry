/********************************************************************************
** Form generated from reading UI file 'backend.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKEND_H
#define UI_BACKEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_backEnd
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *backEnd)
    {
        if (backEnd->objectName().isEmpty())
            backEnd->setObjectName(QStringLiteral("backEnd"));
        backEnd->resize(1311, 638);
        centralwidget = new QWidget(backEnd);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        backEnd->setCentralWidget(centralwidget);
        menubar = new QMenuBar(backEnd);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1311, 26));
        backEnd->setMenuBar(menubar);
        statusbar = new QStatusBar(backEnd);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        backEnd->setStatusBar(statusbar);

        retranslateUi(backEnd);

        QMetaObject::connectSlotsByName(backEnd);
    } // setupUi

    void retranslateUi(QMainWindow *backEnd)
    {
        backEnd->setWindowTitle(QApplication::translate("backEnd", "VT Motorsports Formula SAE Wireless Telemetry", 0));
    } // retranslateUi

};

namespace Ui {
    class backEnd: public Ui_backEnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKEND_H
