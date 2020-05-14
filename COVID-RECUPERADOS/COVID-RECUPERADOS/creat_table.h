#ifndef CREAT_TABLE_H
#define CREAT_TABLE_H

#include "ventana.h"
#include <QDateTime>
#include "insertar.h"

void Ventana::CrearTablaPais()
{
    QDate inicio(2020,1,22); //fecha donde se empiezan a registrar los casos recuperados
    QDate actual2;
    QDate actual = actual2.currentDate(); //fecha actual
    int a = inicio.daysTo(actual); //cuantos dias transcurrieron desde el inicio hasta el dia de hoy

    QByteArray consulta= "CREATE TABLE RECUPERADOS ("
            " Province VARCHAR NULL ,"
            " Country VARCHAR NULL ,"
            " Lat VARCHAR NULL ,"
            " Lon VARCHAR NULL ";
    int mes = actual.month(); //obtengo el numero del mes actual
    for (int i=1; i<=mes ;i++) {
        QDate principo(2020,i,1);
        for (int j=1;j<=principo.daysInMonth();j++){ //con el daysInMonth() obtengo cuantos dias tiene el mes
            if (i==1 and j<22) { // como la fecha desde que se registran datos es el  22/01/22 los dias previos no los agregos
                continue; //continua el for
            }
            if(i==mes and j>=(actual.day())){
                break; // cuando llega a la fecha actual termino el for
            }
               QString fecha;
               int anio = 20;
               char d = 'd';
               char m = 'm';
               char y = 'y';
               QString coma = ",";
               QString text = " VARCHAR NULL ";//para un manejo todos los datos van a ser del tipo VARCHAR
               fecha = QString("%1 %2%3%4%5%6%7%8").arg(coma).arg(d).arg(j).arg(m).arg(i).arg(y).arg(anio).arg(text);
               consulta.append(fecha);
        }
    }
    consulta.append(" )");
    //Ya tengo mi consulta armada
    //la guardo en un archivo creat.text para poder visualizarla menor que en la terminal del debug
    QFile query;
    query.setFileName("../db/creat.txt");
    query.open(QIODevice::WriteOnly|QIODevice::Text);
    query.write(consulta);
    query.close();
    query.flush();
    //ejecuto la consulta
    QSqlQuery crear;
    if(!crear.exec(consulta)){ //controlo que todo salga ok
        qDebug()<<" NO creado "<<crear.lastError();
    }
}

#endif // CREAT_TABLE_H


