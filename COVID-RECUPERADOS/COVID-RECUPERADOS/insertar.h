#ifndef INSERTAR_H
#define INSERTAR_H
#include "ventana.h"
#include<QTextStream>
#include <QChar>
void ventana::InsertarPais()
{
    qDebug()<<"\n Insertar";

    QDate inicio(2020,1,22);
    QDate actual2;
    QDate actual = actual2.currentDate();
//    int a = inicio.daysTo(actual);
    QByteArray consulta;
    consulta.append("INSERT INTO RECUPERADOS(Province , Country, Lat, Lon");
    int mes = actual.month();
    qDebug()<<"\n Insertar2";

    for (int i=1; i<=mes ;i++) {
        QDate principo(2020,i,1);

        for (int j=1;j<=principo.daysInMonth();j++) {
            if (i==1 and j<22) {
                continue;
            }
            if(i==mes and j==(actual.day())){
                break;
            }
               QString fecha;
               int anio = 20;
               char d = 'd';
               char m = 'm';
               char y = 'y';
               QString coma = ",";
               fecha = QString("%1 %2%3%4%5%6%7").arg(coma).arg(d).arg(j).arg(m).arg(i).arg(y).arg(anio);
               consulta.append(fecha);
        }
    }

    qDebug()<<"\n Insertar3";
    QFile query2;
    query2.setFileName("../db/insert.txt");
    query2.open(QIODevice::WriteOnly|QIODevice::Text);

    qDebug()<<"\n Insertar4";

    while (!archivo->atEnd()) {

    qDebug()<<"\n Insertar5";
    QByteArray line = archivo->readLine();
    if(!line.startsWith("Province")){
        QString std = QString(line);
        QString std2 = std.mid(1,(std.size()-2));
        int agregar = std2.count(',')+1;
        int arreglo[agregar];
        int j = 0;
        for (int i = 0; i<std2.size();i++) {
            if(std2[i]==','){
                arreglo[j]=i;
                j++;
            }
        }

        int ss = arreglo[0];

        QString st3 = QString(agregar);
        QString std4 = std.mid(ss+2,2);

        qDebug()<<"----------"<<std4<<"----------";

        for (int i = agregar-2;i>=0;i--) {

            std2.insert(arreglo[i]+1,"'");
            std2.insert(arreglo[i],"'");
        }
        std2.insert(std2.size(),"'");



        QByteArray consulta2=" ";
        consulta2 = consulta;
        consulta2.append(" ) VALUES('");
        consulta2.append(std2);
        consulta2.append(")");
        query2.write(consulta2);
        qDebug()<<consulta2;

        QSqlQuery insertar;
        insertar.exec(consulta2);
        if(insertar.exec(consulta2)){
            qDebug()<<"\n Insertado ";
        }else{
            qDebug()<<"\n Insertado fail"<<insertar.lastError();
        }


        }

    }

}

#endif // INSERTAR_H
