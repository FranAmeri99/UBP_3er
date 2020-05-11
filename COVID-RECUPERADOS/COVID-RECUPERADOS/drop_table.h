#ifndef DROP_TABLE_H
#define DROP_TABLE_H
#include "ventana.h"

void ventana::BorraTable()
{

    QSqlQuery query;
    QString BorrarRegistros = "DELETE FROM RECUPERADOS";
    if(!query.exec(BorrarRegistros)){ //Borro todo los registro insertados
        qDebug()<<"\n No Borrado "<<query.lastError();
    }
    QString BorrarTabla = "DROP TABLE RECUPERADOS";
    if(!query.exec(BorrarTabla)){ //Borro la tabla recuperados
        qDebug()<<"\n No Borrado "<<query.lastError();
    }



}
#endif // DROP_TABLE_H
