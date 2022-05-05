/********************************************************************************
** Form generated from reading UI file 'Bookro.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKRO_H
#define UI_BOOKRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bookro
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Bookro)
    {
        if (Bookro->objectName().isEmpty())
            Bookro->setObjectName(QString::fromUtf8("Bookro"));
        Bookro->resize(800, 600);
        centralwidget = new QWidget(Bookro);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Bookro->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Bookro);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Bookro->setMenuBar(menubar);
        statusbar = new QStatusBar(Bookro);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Bookro->setStatusBar(statusbar);

        retranslateUi(Bookro);

        QMetaObject::connectSlotsByName(Bookro);
    } // setupUi

    void retranslateUi(QMainWindow *Bookro)
    {
        Bookro->setWindowTitle(QCoreApplication::translate("Bookro", "Bookro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bookro: public Ui_Bookro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRO_H
