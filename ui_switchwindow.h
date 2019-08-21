/********************************************************************************
** Form generated from reading UI file 'switchwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHWINDOW_H
#define UI_SWITCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_Sync;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SwitchWindow)
    {
        if (SwitchWindow->objectName().isEmpty())
            SwitchWindow->setObjectName(QStringLiteral("SwitchWindow"));
        SwitchWindow->resize(367, 161);
        centralwidget = new QWidget(SwitchWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 101, 71));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(20, 90, 101, 71));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 10, 101, 71));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 90, 101, 41));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(280, 10, 61, 71));
        pushButton_Sync = new QPushButton(centralwidget);
        pushButton_Sync->setObjectName(QStringLiteral("pushButton_Sync"));
        pushButton_Sync->setGeometry(QRect(160, 90, 61, 41));
        SwitchWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SwitchWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 367, 23));
        SwitchWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SwitchWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SwitchWindow->setStatusBar(statusbar);

        retranslateUi(SwitchWindow);

        QMetaObject::connectSlotsByName(SwitchWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SwitchWindow)
    {
        SwitchWindow->setWindowTitle(QApplication::translate("SwitchWindow", "\347\263\273\347\273\237\351\200\211\346\213\251", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SwitchWindow", "\345\267\246\347\263\273\347\273\237", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("SwitchWindow", "\351\243\236\346\216\247\347\263\273\347\273\237", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SwitchWindow", "\345\217\263\347\263\273\347\273\237", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("SwitchWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("SwitchWindow", "\350\276\205\345\212\251\345\217\202\346\225\260", Q_NULLPTR));
        pushButton_Sync->setText(QApplication::translate("SwitchWindow", "\345\220\214\346\255\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SwitchWindow: public Ui_SwitchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHWINDOW_H
