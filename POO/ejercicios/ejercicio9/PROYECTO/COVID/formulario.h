﻿#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include "admindb.h"
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>
#include <QDateTime>
#include <QTableWidget>
#include "grafico.h"
class Formulario : public QWidget
{
    Q_OBJECT
public:
    explicit Formulario(QWidget *parent = nullptr);
    void cargarCB(QComboBox * combo);
    void graficaProvinvia(QString provincia);
    void mostrar( QString provincia ,QString provincia2 , QString fecha);
//    QComboBox * cbprov;
    QString get_provinvia();
private:

    QLineEdit * le_paginaweb;
    QGridLayout * layout;
    QPushButton * pbBuscar;
    QComboBox * cbprov;
    QDateEdit * defecha;
    QTableWidget * teSelect;
    AdminDB * db;
    Grafico * graficador;

    QCheckBox * cbinfectadosT;
    QCheckBox * cbinfectadosD;
    QCheckBox * cbMuertosT;
    QCheckBox * cbMuertosD;

    QComboBox * cbprov2;
private slots:
    void slot_mostra();
};
#endif // FORMULARIO_H
