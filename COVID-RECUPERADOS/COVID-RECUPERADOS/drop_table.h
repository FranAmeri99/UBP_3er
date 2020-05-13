#ifndef DROP_TABLE_H
#define DROP_TABLE_H
#include "ventana.h"

void ventana::BorraTable()
{
    //como la tabla que manejo se va actulizando diriamente inclusive varias veces al dia
    //lo mejor es borrar la tabla con sus registros y crearlos devuelta con los datos nuevos
    QSqlQuery query;
    QString BorrarRegistros = "DELETE FROM RECUPERADOS";
    if(!query.exec(BorrarRegistros)){ //Borro todo los registro insertados
        qDebug()<<"\n No Borrado elementos "<<query.lastError();
    }
    QString BorrarTabla = "DROP TABLE RECUPERADOS";
    if(!query.exec(BorrarTabla)){ //Borro la tabla recuperados
        qDebug()<<"\n No Borrado tabla "<<query.lastError();
    }



}
#endif // DROP_TABLE_H
