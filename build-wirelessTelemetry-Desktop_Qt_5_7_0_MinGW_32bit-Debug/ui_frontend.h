/********************************************************************************
** Form generated from reading UI file 'frontend.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRONTEND_H
#define UI_FRONTEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frontEnd
{
public:
    QWidget *centralWidget;
    QPushButton *serialButton;
    QComboBox *portsComboBox;
    QPushButton *startButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *frontEnd)
    {
        if (frontEnd->objectName().isEmpty())
            frontEnd->setObjectName(QStringLiteral("frontEnd"));
        frontEnd->resize(1312, 638);
        centralWidget = new QWidget(frontEnd);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        serialButton = new QPushButton(centralWidget);
        serialButton->setObjectName(QStringLiteral("serialButton"));
        serialButton->setGeometry(QRect(370, 310, 221, 41));
        portsComboBox = new QComboBox(centralWidget);
        portsComboBox->setObjectName(QStringLiteral("portsComboBox"));
        portsComboBox->setGeometry(QRect(490, 250, 221, 41));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(610, 310, 231, 41));
        frontEnd->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(frontEnd);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1312, 26));
        frontEnd->setMenuBar(menuBar);
        mainToolBar = new QToolBar(frontEnd);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        frontEnd->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(frontEnd);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        frontEnd->setStatusBar(statusBar);

        retranslateUi(frontEnd);

        QMetaObject::connectSlotsByName(frontEnd);
    } // setupUi

    void retranslateUi(QMainWindow *frontEnd)
    {
        frontEnd->setWindowTitle(QApplication::translate("frontEnd", "VT Motorsports Formula SAE Wireless Telemetry", 0));
        serialButton->setText(QApplication::translate("frontEnd", "Get Available Serial (COM) Ports", 0));
        startButton->setText(QApplication::translate("frontEnd", "Begin Telemetry", 0));
    } // retranslateUi

};

namespace Ui {
    class frontEnd: public Ui_frontEnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONTEND_H
