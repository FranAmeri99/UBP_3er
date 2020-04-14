/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QPushButton *pbNuevo;
    QPushButton *pbActualizar;
    QPushButton *pbBorrar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(884, 501);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 4);

        pbNuevo = new QPushButton(Widget);
        pbNuevo->setObjectName(QString::fromUtf8("pbNuevo"));

        gridLayout->addWidget(pbNuevo, 1, 0, 1, 1);

        pbActualizar = new QPushButton(Widget);
        pbActualizar->setObjectName(QString::fromUtf8("pbActualizar"));

        gridLayout->addWidget(pbActualizar, 1, 1, 1, 1);

        pbBorrar = new QPushButton(Widget);
        pbBorrar->setObjectName(QString::fromUtf8("pbBorrar"));

        gridLayout->addWidget(pbBorrar, 1, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pbNuevo->setText(QCoreApplication::translate("Widget", "Nuevo", nullptr));
        pbActualizar->setText(QCoreApplication::translate("Widget", "Actualizar", nullptr));
        pbBorrar->setText(QCoreApplication::translate("Widget", "Borrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
