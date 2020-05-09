#ifndef INSERTAR_H
#define INSERTAR_H
#include "ventana.h"
#include<QTextStream>
void ventana::InsertarUsuario()
{
    qDebug()<<"\n Insertar";

    QDate inicio(2020,1,22);
    QDate actual2;
    QDate actual = actual2.currentDate();
//    int a = inicio.daysTo(actual);
    QByteArray consulta;
    consulta.append("INSERT INTO RECUPERADOS(Province , Country, Lat, Long");
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
               fecha = QString("%1 %2%3%4%5%6%7").arg(coma).arg(d).arg(j).arg(m).arg(i).arg(y).arg(anio);
              // qDebug()<<fecha;
               consulta.append(fecha);
        }
    }
    QFile query2;
    query2.setFileName("../db/insert.txt");
    query2.open(QIODevice::WriteOnly|QIODevice::Text);
    while (!archivo->atEnd()) {


        QByteArray line = archivo->readLine();
            if(!line.startsWith("Province")){
                QString std = QString(line);
                QString std2 = std.mid(1,(std.size()-2));
                QByteArray consulta2=" ";
                consulta2 = consulta;
                consulta2.append(" ) VALUES(");
                consulta2.append(std2);
                consulta2.append(");");
                qDebug()<<consulta2;
                query2.write(consulta2);
/*
                QSqlQuery insertar;
                insertar.prepare(consulta2);
                if(!insertar.exec()){
                    qDebug()<<"\n NO Insertado "<<insertar.lastError();
                }*/




            }

    }

    query2.close();
    query2.flush();
}

#endif // INSERTAR_H
