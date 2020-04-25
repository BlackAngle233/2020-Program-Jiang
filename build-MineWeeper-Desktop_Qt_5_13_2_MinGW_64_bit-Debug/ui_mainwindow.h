/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 240, 121, 41));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 300, 121, 41));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 362, 121, 41));
        pushButton_3->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 100, 361, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        font1.setPointSize(37);
        label->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(600, 40, 131, 41));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 40, 131, 41));
        label_3->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 100, 741, 401));
        MainWindow->setCentralWidget(centralwidget);
        widget->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "MineWeeper V0.01", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\211\251\344\275\231\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
