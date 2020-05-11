#ifndef MOSTRAR_H
#define MOSTRAR_H
#include"ventana.h"
void ventana::MostrarDatos(){
    //BARRA SUPERIOR
    QDate actual2;
    QDate aux = actual2.currentDate();
    QString auxS = aux.toString();
    QStringList headers = { "PAIS", "ESTADO", "LATITUD","longitud",auxS}; //EN LA QUINTA COLUMNA SE MUESTRA LA FECHA ACTUAL
    teSelect->setHorizontalHeaderLabels(headers);

    //CONSULTA
    QDate dia = de_dia->date();
    QSqlQuery mostrar;
    QString consulta;
    consulta.append("SELECT"
                    " Country, Province, Lat, Lon, "
                    "");
    QString fecha = "d";

    //PROCESO LA FECHA DEL COMBO BOX PARA ADECUARLA A MI CONSULTA
    QString di, me, an ;
    di.setNum(dia.day());
    me.setNum(dia.month());
    an.setNum(dia.year()-2000);
    fecha.append(di);
    fecha.append("m");
    fecha.append(me);
    fecha.append("y");
    fecha.append(an);
    consulta.append(fecha);

    //AGREGO EL PAIS/ESTADO,PAISE
    QString a = cb_pais->currentText();
    bool estado = a.contains(',');
    if(!estado){ //HAGO UNA COMPARACION PARA SABER SI TENGO QUE BUSCAR SOLO UN PAIS O UN ESTADO
        consulta.append(" FROM recuperados WHERE Country = '");
        consulta.append(a);
        consulta.append("';");
    }
    else{
        consulta.append(" FROM recuperados WHERE Province = '");
        int p = a.indexOf(',');
        QString pp = a.mid(p+2,-1);
        consulta.append(pp);
        consulta.append("'");
        }
    mostrar.exec(consulta);
    qDebug()<<"\n";
    if(!mostrar.exec()){
        qDebug()<<"\n NO mostrado "<<mostrar.lastError();
    }
    int fila =0;
    teSelect->setRowCount(0);
    while(mostrar.next()){ //muestro en la tabla lo que devuelve la consulta
        teSelect->insertRow(fila);
        teSelect->setItem(fila, 1,new QTableWidgetItem(mostrar.value(1).toByteArray().constData()));
        teSelect->setItem(fila, 0,new QTableWidgetItem(mostrar.value(0).toByteArray().constData()));
        teSelect->setItem(fila, 2,new QTableWidgetItem(mostrar.value(2).toByteArray().constData()));
        teSelect->setItem(fila, 3,new QTableWidgetItem(mostrar.value(3).toByteArray().constData()));
        teSelect->setItem(fila, 4,new QTableWidgetItem(mostrar.value(4).toByteArray().constData()));
        fila ++;

    }
    QStringList headers2 = { "PAIS", "ESTADO", "LATITUD","longitud",dia.toString()};
    teSelect->setHorizontalHeaderLabels(headers2);
}
#endif // MOSTRAR_H
