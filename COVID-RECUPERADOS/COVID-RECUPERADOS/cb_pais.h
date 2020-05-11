#ifndef CB_PAIS_H
#define CB_PAIS_H
#include "ventana.h"
void ventana::cargar_cb()
{
    cb_pais->clear();
    //cargo en el ComboBox los paices y provincias que puedo buscar
    QSqlQuery cargar_pais;
    QString consulta;
    consulta.append("SELECT Country, Province FROM RECUPERADOS");
    cargar_pais.prepare(consulta);
    if(!cargar_pais.exec()){
        qDebug()<<"\n Combo Box"<<cargar_pais.lastError();
    }
    while(cargar_pais.next()){
    QString a = cargar_pais.value(0).toByteArray().constData();
    QString b = "";
    // veo si tiene provincias o solo esta el pais
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
