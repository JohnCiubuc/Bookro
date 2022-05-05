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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bookro
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Bookro)
    {
        if (Bookro->objectName().isEmpty())
            Bookro->setObjectName(QString::fromUtf8("Bookro"));
        Bookro->resize(201, 212);
        centralwidget = new QWidget(Bookro);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setReadOnly(false);

        verticalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(pushButton);

        Bookro->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Bookro);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 201, 23));
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
        label->setText(QCoreApplication::translate("Bookro", "Trigger Macro For:", nullptr));
        label_2->setText(QCoreApplication::translate("Bookro", "And type this text:", nullptr));
        pushButton->setText(QCoreApplication::translate("Bookro", "Set Macro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bookro: public Ui_Bookro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRO_H
