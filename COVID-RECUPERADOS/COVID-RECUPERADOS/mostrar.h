#ifndef MOSTRAR_H
#define MOSTRAR_H
#include"ventana.h"
void ventana::MostrarDatos(){
    //BARRA SUPERIOR
    QDate actual2;
    QDate aux = actual2.currentDate();
    QString auxS = aux.toString();
    qDebug()<<"------------------"<<auxS<<"--------------";
    QStringList headers = { "PAIS", "ESTADO", "LATITUD","longitud",auxS};
    teSelect->setHorizontalHeaderLabels(headers);
    qDebug()<<"\n joya 3";
    de_dia->setDisplayFormat("M/d/yy");
    QString dia = de_dia->text();
    qDebug()<<" \n dia seteado \n"<<dia;
    //CONSULTA
    QSqlQuery mostrar;
    QString  desribe= ".schema";
    QSqlQuery descrinbe;
    descrinbe.prepare(desribe);
    QString consulta;
    //consulta.append("SELECT * FROM recuperados WHERE Country = 'Argentina' ");
    //consulta.append("SELECT * ");
    consulta.append("SELECT Country, Province, Lat, Long, [");


    consulta.append(dia);
        //dia del combo box
    QString a = cb_pais->currentText();
    bool estado = a.contains(',');
    if(!estado){
    consulta.append("] FROM recuperados WHERE Country = '");
    consulta.append(a);
     consulta.append("';");

    }
    else{
        consulta.append("] FROM recuperados WHERE Province = '");
        int p = a.indexOf(',');
        QString pp = a.mid(p+2,-1);
        consulta.append(pp);
        // aux.append(aux2);
        consulta.append("';");
        }
    qDebug()<<"\n"<<consulta<<"\n";
    mostrar.prepare(consulta);
    qDebug()<<"\n";
    if(!mostrar.exec()){
        qDebug()<<"\n NO mostrado "<<mostrar.lastError();

    }

    int fila =0;
    teSelect->setRowCount(0);
    while(mostrar.next()){


    QDate inicio(2020, 1, 22);
    QDate actual2;/*
    QDate aux = actual2.currentDate();
    int a = inicio.daysTo(aux);*/
    //int a = inicio.daysTo();
    //a +=3;
    //como muestro las primeas cuatro columnas en orden correspondiente a la tabla
    //la quinta columna trae los datps de la ultima columna de la tabla
    //que es una diferencia entre la fecha de la fecha actual menos la de inicio mas 4 (columnas estado, pais, lat, long
    teSelect->insertRow(fila);

    teSelect->setItem(fila, 1,new QTableWidgetItem(mostrar.value(1).toByteArray().constData()));
    teSelect->setItem(fila, 0,new QTableWidgetItem(mostrar.value(0).toByteArray().constData()));
    teSelect->setItem(fila, 2,new QTableWidgetItem(mostrar.value(2).toByteArray().constData()));
    teSelect->setItem(fila, 3,new QTableWidgetItem(mostrar.value(3).toByteArray().constData()));
    teSelect->setItem(fila, 4,new QTableWidgetItem(mostrar.value(4).toByteArray().constData()));
    fila ++;

    }
    QStringList headers2 = { "PAIS", "ESTADO", "LATITUD","longitud",dia};
    teSelect->setHorizontalHeaderLabels(headers2);
}
#endif // MOSTRAR_H
