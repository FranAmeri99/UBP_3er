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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "my_qlabel.h"

QT_BEGIN_NAMESPACE

class Ui_Ventana
{
public:
    QGridLayout *gridLayout;
    my_qlabel *lblMouse;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *lblMouse_Current_Pos;
    QLabel *lblMouse_Current_Event;

    void setupUi(QWidget *Ventana)
    {
        if (Ventana->objectName().isEmpty())
            Ventana->setObjectName(QString::fromUtf8("Ventana"));
        Ventana->setEnabled(false);
        Ventana->resize(642, 229);
        gridLayout = new QGridLayout(Ventana);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lblMouse = new my_qlabel(Ventana);
        lblMouse->setObjectName(QString::fromUtf8("lblMouse"));
        lblMouse->setCursor(QCursor(Qt::ArrowCursor));
        lblMouse->setMouseTracking(true);
        lblMouse->setFrameShape(QFrame::Box);

        gridLayout->addWidget(lblMouse, 0, 0, 1, 1);

        groupBox = new QGroupBox(Ventana);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblMouse_Current_Pos = new QLabel(groupBox);
        lblMouse_Current_Pos->setObjectName(QString::fromUtf8("lblMouse_Current_Pos"));
        lblMouse_Current_Pos->setFrameShape(QFrame::Box);
        lblMouse_Current_Pos->setFrameShadow(QFrame::Plain);
        lblMouse_Current_Pos->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblMouse_Current_Pos, 0, 0, 1, 1);

        lblMouse_Current_Event = new QLabel(groupBox);
        lblMouse_Current_Event->setObjectName(QString::fromUtf8("lblMouse_Current_Event"));
        lblMouse_Current_Event->setFrameShape(QFrame::Box);
        lblMouse_Current_Event->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblMouse_Current_Event, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);


        retranslateUi(Ventana);

        QMetaObject::connectSlotsByName(Ventana);
    } // setupUi

    void retranslateUi(QWidget *Ventana)
    {
        Ventana->setWindowTitle(QCoreApplication::translate("Ventana", "Ventana", nullptr));
        lblMouse->setText(QCoreApplication::translate("Ventana", "Area del Mouse", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Ventana", "Mouse Event", nullptr));
        lblMouse_Current_Pos->setText(QCoreApplication::translate("Ventana", "X=0; Y=0", nullptr));
        lblMouse_Current_Event->setText(QCoreApplication::translate("Ventana", "Mouse Current Event?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ventana: public Ui_Ventana {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_H
