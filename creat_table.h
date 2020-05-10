#ifndef CREAT_TABLE_H
#define CREAT_TABLE_H

#include "ventana.h"
#include <QDateTime>
#include "insertar.h"
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
    QString final = " )";
    QString raro = "CREATE TABLE RECUPERADOS ( Province VARCHAR NULL , Country VARCHAR NULL , Lat VARCHAR NULL , Lon VARCHAR NULL , d22m1y20 VARCHAR NULL , d23m1y20 VARCHAR NULL , d24m1y20 VARCHAR NULL , d25m1y20 VARCHAR NULL , d26m1y20 VARCHAR NULL , d27m1y20 VARCHAR NULL , d28m1y20 VARCHAR NULL , d29m1y20 VARCHAR NULL , d30m1y20 VARCHAR NULL , d31m1y20 VARCHAR NULL , d1m2y20 VARCHAR NULL , d2m2y20 VARCHAR NULL , d3m2y20 VARCHAR NULL , d4m2y20 VARCHAR NULL , d5m2y20 VARCHAR NULL , d6m2y20 VARCHAR NULL , d7m2y20 VARCHAR NULL , d8m2y20 VARCHAR NULL , d9m2y20 VARCHAR NULL , d10m2y20 VARCHAR NULL , d11m2y20 VARCHAR NULL , d12m2y20 VARCHAR NULL , d13m2y20 VARCHAR NULL , d14m2y20 VARCHAR NULL , d15m2y20 VARCHAR NULL , d16m2y20 VARCHAR NULL , d17m2y20 VARCHAR NULL , d18m2y20 VARCHAR NULL , d19m2y20 VARCHAR NULL , d20m2y20 VARCHAR NULL , d21m2y20 VARCHAR NULL , d22m2y20 VARCHAR NULL , d23m2y20 VARCHAR NULL , d24m2y20 VARCHAR NULL , d25m2y20 VARCHAR NULL , d26m2y20 VARCHAR NULL , d27m2y20 VARCHAR NULL , d28m2y20 VARCHAR NULL , d29m2y20 VARCHAR NULL , d1m3y20 VARCHAR NULL , d2m3y20 VARCHAR NULL , d3m3y20 VARCHAR NULL , d4m3y20 VARCHAR NULL , d5m3y20 VARCHAR NULL , d6m3y20 VARCHAR NULL , d7m3y20 VARCHAR NULL , d8m3y20 VARCHAR NULL , d9m3y20 VARCHAR NULL , d10m3y20 VARCHAR NULL , d11m3y20 VARCHAR NULL , d12m3y20 VARCHAR NULL , d13m3y20 VARCHAR NULL , d14m3y20 VARCHAR NULL , d15m3y20 VARCHAR NULL , d16m3y20 VARCHAR NULL , d17m3y20 VARCHAR NULL , d18m3y20 VARCHAR NULL , d19m3y20 VARCHAR NULL , d20m3y20 VARCHAR NULL , d21m3y20 VARCHAR NULL , d22m3y20 VARCHAR NULL , d23m3y20 VARCHAR NULL , d24m3y20 VARCHAR NULL , d25m3y20 VARCHAR NULL , d26m3y20 VARCHAR NULL , d27m3y20 VARCHAR NULL , d28m3y20 VARCHAR NULL , d29m3y20 VARCHAR NULL , d30m3y20 VARCHAR NULL , d31m3y20 VARCHAR NULL , d1m4y20 VARCHAR NULL , d2m4y20 VARCHAR NULL , d3m4y20 VARCHAR NULL , d4m4y20 VARCHAR NULL , d5m4y20 VARCHAR NULL , d6m4y20 VARCHAR NULL , d7m4y20 VARCHAR NULL , d8m4y20 VARCHAR NULL , d9m4y20 VARCHAR NULL , d10m4y20 VARCHAR NULL , d11m4y20 VARCHAR NULL , d12m4y20 VARCHAR NULL , d13m4y20 VARCHAR NULL , d14m4y20 VARCHAR NULL , d15m4y20 VARCHAR NULL , d16m4y20 VARCHAR NULL , d17m4y20 VARCHAR NULL , d18m4y20 VARCHAR NULL , d19m4y20 VARCHAR NULL , d20m4y20 VARCHAR NULL , d21m4y20 VARCHAR NULL , d22m4y20 VARCHAR NULL , d23m4y20 VARCHAR NULL , d24m4y20 VARCHAR NULL , d25m4y20 VARCHAR NULL , d26m4y20 VARCHAR NULL , d27m4y20 VARCHAR NULL , d28m4y20 VARCHAR NULL , d29m4y20 VARCHAR NULL , d30m4y20 VARCHAR NULL , d1m5y20 VARCHAR NULL , d2m5y20 VARCHAR NULL , d3m5y20 VARCHAR NULL , d4m5y20 VARCHAR NULL , d5m5y20 VARCHAR NULL , d6m5y20 VARCHAR NULL , d7m5y20 VARCHAR NULL , d8m5y20 VARCHAR NULL , d9m5y20 VARCHAR NULL , d10m5y20 VARCHAR NULL , d11m5y20 VARCHAR NULL , d12m5y20 VARCHAR NULL , d13m5y20 VARCHAR NULL , d14m5y20 VARCHAR NULL , d15m5y20 VARCHAR NULL , d16m5y20 VARCHAR NULL , d17m5y20 VARCHAR NULL , d18m5y20 VARCHAR NULL , d19m5y20 VARCHAR NULL , d20m5y20 VARCHAR NULL , d21m5y20 VARCHAR NULL , d22m5y20 VARCHAR NULL , d23m5y20 VARCHAR NULL , d24m5y20 VARCHAR NULL , d25m5y20 VARCHAR NULL , d26m5y20 VARCHAR NULL , d27m5y20 VARCHAR NULL , d28m5y20 VARCHAR NULL , d29m5y20 VARCHAR NULL , d30m5y20 VARCHAR NULL , d31m5y20 VARCHAR NULL  )";
    consulta.append(final);
    //qDebug()<<consulta;
    QFile query;
    query.setFileName("../db/consulta.txt");
    query.open(QIODevice::WriteOnly|QIODevice::Text);
    query.write(consulta);
    query.close();
    query.flush();
    QString borrar = "DROP TABLE IF EXISTS RECUPERADOS";
    QSqlQuery crear;
    crear.exec(borrar);
    if(crear.exec(borrar)){
        qDebug()<<"\n Borrado";
    }
    else{

        qDebug()<<"\n NO Borrado "<<crear.lastError();
    }
    //crear.exec(raro);
    if(crear.exec(raro)){
        qDebug()<<"\n creado";
    }
    else{

        qDebug()<<"\n"<<raro;
        qDebug()<<" NO creado "<<crear.lastError();
    }
    InsertarPais();

}


#endif // CREAT_TABLE_H


