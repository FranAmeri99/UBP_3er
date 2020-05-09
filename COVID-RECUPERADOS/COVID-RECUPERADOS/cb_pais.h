#ifndef CB_PAIS_H
#define CB_PAIS_H
#include "ventana.h"
void ventana::cargar_cb()
{

    //CONSULTA
    QSqlQuery cargar_pais;

    QString consulta;
    consulta.append("SELECT Country, Province FROM recuperados");

    cargar_pais.prepare(consulta);
    if(!cargar_pais.exec()){
        qDebug()<<"\n Combo Box"<<cargar_pais.lastError();
    }

    while(cargar_pais.next()){

    QString a = cargar_pais.value(0).toByteArray().constData();
    QString b = "";
    if(cargar_pais.value(1).toByteArray().constData()== b){
        cb_pais->addItem(a);

    }else{
        b = cargar_pais.value(1).toByteArray().constData();
        QString c = a +" , "+ b;
        cb_pais->addItem(c);
        }
    }

}

#endif // CB_PAIS_H