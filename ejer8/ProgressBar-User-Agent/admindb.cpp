#include "admindb.h"

adminDB::adminDB(QWidget *parent) : QWidget(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/recuperados.sqlite");
    if(!db.open()){
        qDebug()<<"HUBO UN PROBLEMA EN LA CONECCION"<<db.lastError();
    }

}

void adminDB::CreatTable(QString nombreTable)
{

    QByteArray query = "CREATE TABLE ";
    query.append(nombreTable);
    query.append(" (fecha INT, provincia VARCHAR, casos_totales VARCHAR, casos_nuevos VARCHAR, "
                 " muertes_total VARCHAR, muertes_nuevos VARCHAR, observaciones VARCHAR)");
}
