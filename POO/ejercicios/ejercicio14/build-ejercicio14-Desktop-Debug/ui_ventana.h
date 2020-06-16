/********************************************************************************
** Form generated from reading UI file 'ventana.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_H
#define UI_VENTANA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *Rotar;
    QLabel *Limagen;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName(QString::fromUtf8("Ventana"));
        Ventana->resize(800, 600);
        centralwidget = new QWidget(Ventana);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        Rotar = new QPushButton(centralwidget);
        Rotar->setObjectName(QString::fromUtf8("Rotar"));

        gridLayout->addWidget(Rotar, 0, 1, 1, 1);

        Limagen = new QLabel(centralwidget);
        Limagen->setObjectName(QString::fromUtf8("Limagen"));

        gridLayout->addWidget(Limagen, 1, 0, 1, 2);

        Ventana->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Ventana);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Ventana->setMenuBar(menubar);
        statusbar = new QStatusBar(Ventana);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Ventana->setStatusBar(statusbar);

        retranslateUi(Ventana);

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QMainWindow *Ventana)
    {
        Ventana->setWindowTitle(QCoreApplication::translate("Ventana", "Ventana", nullptr));
        pushButton->setText(QCoreApplication::translate("Ventana", "Buscar Archivo", nullptr));
        Rotar->setText(QCoreApplication::translate("Ventana", "Rotar", nullptr));
        Limagen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
