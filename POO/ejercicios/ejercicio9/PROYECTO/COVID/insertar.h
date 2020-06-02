#ifndef INSERTAR_H
#define INSERTAR_H
#include "admindb.h"
#include <QFile>
#include <QDebug>
void AdminDB::InsertarTable()
{
    int posicion = 0;
    int contador = 0;
    qDebug()<<"Admin Insertar";
    /*
    QFile ProvinciaCSV;
    ProvinciaCSV.setFileName("../db/ProvinciaCSV.csv");
    //Leo CSV
    ProvinciaCSV.open(QIODevice::ReadOnly|QIODevice::Text);
    if (!ProvinciaCSV.isOpen()){
        qDebug()<<"No se pudo abrir";
    }
    //CREO UN ARCHIVI TXT PARA PODER VISUALISAR MEJOR LAS CONSULTAS Y NO VERLAS
    // POR EL DEBUG
    QFile * Insertar = new QFile;
    Insertar->setFileName("../db/Insertar.txt");
    Insertar->open(QIODevice::ReadWrite|QIODevice::Text);
    if (!Insertar->isOpen()){
        qDebug()<<"No se pudo abrir insertar";
    }
    while ( ! ProvinciaCSV.atEnd() )  {
        QByteArray line = ProvinciaCSV.readLine();
        //como la primera linea del csv contiene los nombres de las columas la omito en la insercion
        if(!line.startsWith("provincia")){
        QString std = QString(line);
        QString std2 = std.mid(0,(std.size()-2));//para omitir la barra n
        int agregar = std2.count(',')+1; //cantida de comas que pose la linea
        int arreglo[agregar] ; //contiene las posiciones donde estan las comas


        QByteArray queryI = "INSERT INTO " + nombreTable.toUtf8() + "( ";
        queryI.append("fecha , provincia, casos_totales"
                      ", casos_nuevos, muertes_total, "
                      "muertes_nuevos ");
        if(agregar==7){
        queryI.append(", descripcion ");
        }
        queryI.append(") VALUES ( ");

        int j = 0;

        for (int i = 0; i<std2.size();i++) {
            if(std2[i]==','){
                arreglo[j]=i; //guardo las posiciones donde estan las comas
                j++;
            }
        }

        for (int i = agregar-2;i>=0;i--) {
            if (arreglo[i]+1 == arreglo[i+1] or arreglo[i] == std2.size()) {
                std2.insert(arreglo[i]+1,"-");
            }
            std2.insert(arreglo[i]+1,"'"); //inserto comillas
            std2.insert(arreglo[i],"'");//inserto comillas
        }
        std2.insert(std2.size(),"')");
        std2.insert(0,"'");
        queryI.append(std2);
       //qDebug()<<queryI;

        QSqlQuery inser;
        if(inser.exec(queryI)){ //controlo que todo salga ok
            //qDebug()<<"  Insertado ";
            //qDebug()<<"INSERCION numeros de coma"<< agregar << ", posicion"<<posicion;
        }else{
            qDebug()<<queryI;
               qDebug()<<"\nNO INSERCION numeros de coma"<< agregar << ", posicion"<<posicion<<"\n";
               qDebug()<<inser.lastError();
               contador ++;
        }
        queryI.append("\n");
        Insertar->write(queryI);

        posicion ++;
        }
    }
    qDebug()<<"CONTADOR DE ERRORES"<<contador;
    Insertar->close();
    ProvinciaCSV.close();*/
}

#endif // INSERTAR_H
