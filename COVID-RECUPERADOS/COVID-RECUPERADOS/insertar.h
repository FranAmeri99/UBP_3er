#ifndef INSERTAR_H
#define INSERTAR_H
#include "ventana.h"
#include<QTextStream>
#include <QChar>
void ventana::InsertarPais()
{
    qDebug()<<"\n Insertar";

    QDate inicio(2020,1,22);//fecha desde que se empezo a registrar casos
    QDate actual2;
    QDate actual = actual2.currentDate(); //fecha actual
    QByteArray consulta;
    //inicio la consulta con las 4 columnas que seguro voy a tener
    consulta.append("INSERT INTO RECUPERADOS(Province , Country, Lat, Lon");
    int mes = actual.month(); // numero de mes actual
    //creo las columas con las fechas desde el que se empezaron a registrar datos
    //hasta el dia actual
    for (int i=1; i<=mes ;i++) {
        QDate principo(2020,i,1);
        for (int j=1;j<=principo.daysInMonth();j++) {
            if (i==1 and j<22) {
                //recie en el dia 22 de enero se emepezaron a registra casos
                //los dias previos no hay datos
                continue;
            }
            //cuando llega al dia actual termina el for
            if(i==mes and j==(actual.day())){
                break;
            }
               QString fecha;
               // creo un nuevo formato para los dias
               int anio = 20;
               char d = 'd';
               char m = 'm';
               char y = 'y';
               QString coma = ",";
               //concateno los valores y separo por coma
               fecha = QString("%1 %2%3%4%5%6%7").arg(coma).arg(d).arg(j).arg(m).arg(i).arg(y).arg(anio);
               consulta.append(fecha);
        }
    }

    QFile query2;
    query2.setFileName("../db/insert.txt");
    query2.open(QIODevice::WriteOnly|QIODevice::Text);

    while (!archivo->atEnd()) {
    QByteArray line = archivo->readLine();
    //como la primera linea del csv contiene los nombres de las columas la omito en la insercion
    if(!line.startsWith("Province")){
        //si empieza con una coma significa que no tiene una provincia asociada
        //debemos completar ese dato faltante (para que no tire error en la insercion)
        //lo completo con el mismo nombre que el pais
            if(line.startsWith(",")){
                QString std5= QString(line);
                std5.remove(0,1);
                QString paiss = std5.mid(0,std5.indexOf(','));
                line.insert(0,paiss);
            }
            QString std = QString(line);
            QString std2 = std.mid(0,(std.size()-2));
            qDebug()<<std2;
            int agregar = std2.count(',')+1; //cantida de comas que pose la linea
            int arreglo[agregar]; //contiene las posiciones donde estan las comas
            int j = 0;
            for (int i = 0; i<std2.size();i++) {
                if(std2[i]==','){
                    arreglo[j]=i; //guardo las posiciones donde estan las comas
                    j++;
                }
            }
            int ss = arreglo[0];
            QString st3 = QString(agregar);
            QString std4 = std.mid(ss+2,2);

            for (int i = agregar-2;i>=0;i--) {
                std2.insert(arreglo[i]+1,"'"); //inserto comillas
                std2.insert(arreglo[i],"'");//inserto comillas
            }
            std2.insert(std2.size(),"'"); //inserto comillas al final
            QByteArray consulta2=" ";
            consulta2 = consulta;
            consulta2.append(" ) VALUES('");
            consulta2.append(std2);
            consulta2.append(")");
            query2.write(consulta2);

            QSqlQuery insertar;
            insertar.exec(consulta2);
            if(!insertar.exec(consulta2)){
                qDebug()<<"\n NO insertado "<<insertar.lastError();
            }
        }
    }
}

#endif // INSERTAR_H
