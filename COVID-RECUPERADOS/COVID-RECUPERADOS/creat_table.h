﻿#ifndef CREAT_TABLE_H
#define CREAT_TABLE_H

#include "ventana.h"
#include <QDateTime>
void ventana::CrearTablaUsuario()
{

    QDate inicio(2020,1,22);
    QDate actual2;
    QDate actual = actual2.currentDate();
    int a = inicio.daysTo(actual);

    qDebug()<<"\n CREAR TABLA RECUPERADOS";

    QByteArray consulta= "CREATE TABLE RECUPERADOS ("
            " Province VARCHAR NULL ,"
            " Country VARCHAR NULL ,"
            " Lat VARCHAR NULL ,"
            " Lon VARCHAR NULL ";
    int mes = actual.month();

    for (int i=1; i<=mes ;i++) {
        QDate principo(2020,i,1);

        for (int j=1;j<=principo.daysInMonth();j++) {
            if (i==1 and j<22) {
                continue;
            }
               QString fecha;
               int anio = 20;
               char d = 'd';
               char m = 'm';
               char y = 'y';
               QString coma = ",";
               QString text = " VARCHAR NULL ";
               fecha = QString("%1 %2%3%4%5%6%7%8").arg(coma).arg(d).arg(j).arg(m).arg(i).arg(y).arg(anio).arg(text);
              // qDebug()<<fecha;
               consulta.append(fecha);
        }

    }
    QString final = " );";
    consulta.append(final);
    QFile query;
    query.setFileName("../db/consulta.txt");
    query.open(QIODevice::WriteOnly|QIODevice::Text);
    query.write(consulta);
    query.close();
    query.flush();

    QSqlQuery crear;
    crear.prepare(consulta);
    if(!crear.exec()){
        qDebug()<<"\n NO Insertado "<<crear.lastError();
    }


}


#endif // CREAT_TABLE_H


