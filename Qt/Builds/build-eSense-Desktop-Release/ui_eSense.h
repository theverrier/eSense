/********************************************************************************
** Form generated from reading UI file 'eSense.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESENSE_H
#define UI_ESENSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eSense
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *hostInfo;
    QLabel *serialPortInfo;
    QLabel *lbl_receive;
    QLabel *lbl_sending;
    QTextBrowser *log;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *eSense)
    {
        if (eSense->objectName().isEmpty())
            eSense->setObjectName(QStringLiteral("eSense"));
        eSense->resize(400, 300);
        centralWidget = new QWidget(eSense);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hostInfo = new QLabel(gridLayoutWidget);
        hostInfo->setObjectName(QStringLiteral("hostInfo"));

        gridLayout->addWidget(hostInfo, 1, 1, 1, 1);

        serialPortInfo = new QLabel(gridLayoutWidget);
        serialPortInfo->setObjectName(QStringLiteral("serialPortInfo"));

        gridLayout->addWidget(serialPortInfo, 0, 1, 1, 1);

        lbl_receive = new QLabel(gridLayoutWidget);
        lbl_receive->setObjectName(QStringLiteral("lbl_receive"));

        gridLayout->addWidget(lbl_receive, 0, 0, 1, 1);

        lbl_sending = new QLabel(gridLayoutWidget);
        lbl_sending->setObjectName(QStringLiteral("lbl_sending"));

        gridLayout->addWidget(lbl_sending, 1, 0, 1, 1);

        log = new QTextBrowser(gridLayoutWidget);
        log->setObjectName(QStringLiteral("log"));

        gridLayout->addWidget(log, 2, 0, 1, 2);

        eSense->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(eSense);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        eSense->setMenuBar(menuBar);
        mainToolBar = new QToolBar(eSense);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        eSense->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(eSense);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        eSense->setStatusBar(statusBar);

        retranslateUi(eSense);

        QMetaObject::connectSlotsByName(eSense);
    } // setupUi

    void retranslateUi(QMainWindow *eSense)
    {
        eSense->setWindowTitle(QApplication::translate("eSense", "eSense", Q_NULLPTR));
        hostInfo->setText(QApplication::translate("eSense", "NaN", Q_NULLPTR));
        serialPortInfo->setText(QApplication::translate("eSense", "NaN", Q_NULLPTR));
        lbl_receive->setText(QApplication::translate("eSense", "Receiving on: ", Q_NULLPTR));
        lbl_sending->setText(QApplication::translate("eSense", "Sending to: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class eSense: public Ui_eSense {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESENSE_H
