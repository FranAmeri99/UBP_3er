#include "admindb.h"

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/recuperados.sqlite");
    if(!db.open()){
        qDebug()<<"HUBO UN PROBLEMA EN LA CONECCION"<<db.lastError();
    }
    ProvinciaCSV->setFileName("../db/ProvinciaCSV.csv");
    ProvinciaCSV->open(QIODevice::WriteOnly|QIODevice::Text);
    if (!ProvinciaCSV->isOpen()){
        qDebug()<<"No se pudo abrir";
    }

}
bool AdminDB::conectar( QString archivoSqlite )  {

    db.setDatabaseName( archivoSqlite );

    if( db.open() ){

        return true;
        qDebug()<<"se conecto";
    }
    return false;
}

void AdminDB::CreatTable(QString nombreTable)
{
    QByteArray query = "CREATE TABLE ";
    query.append(nombreTable);
    query.append(" (fecha VARCHAR, provincia VARCHAR, casos_totales VARCHAR, casos_nuevos VARCHAR, "
                 " muertes_total VARCHAR, muertes_nuevos VARCHAR");
}

void AdminDB::insertar(QString nombreTable)
{

    QFile * Insertar = new QFile();
    Insertar->setFileName("../db/Insertar.txt");
    Insertar->open(QIODevice::ReadWrite|QIODevice::Text);
    if (!Insertar->isOpen()){
        qDebug()<<"No se pudo abrir insertar";
    }
    while ( ! ProvinciaCSV->atEnd() )  {
        QByteArray line = ProvinciaCSV->readLine();
        if(!line.startsWith("provincia")){
            QByteArray query = "INSERT INTO " ;
            query.append(nombreTable);
            query.append(" (fecha VARCHAR, provincia VARCHAR, "
                            "casos_totales VARCHAR, casos_nuevos VARCHAR, "
                            "muertes_total VARCHAR, muertes_nuevos VARCHAR) "
                            "VALUES (");
            QString std = QString(line);
            QString std2 = std.mid(0,(std.size()-2));//para omitir la barra n

            int j = 0;
            int cortar = 0;
            int arreglo[5]; //guarda la posiciones de la coma
            int agregar = std2.count(','); //cantida de comas que pose la linea

            if(agregar>5){
                for (int i = 0; i<std2.size();i++) {
                    if(std2[i]==','){
                        if(j>5){
                            break;
                        }
                        cortar = i;

                        arreglo[j] = i;
                        j++;
                    }
                }
                std2 = std2.mid(0,cortar);
            }

            for (int i = 5;i>=0;i--) {
                        if (arreglo[i]+1 == arreglo[i+1]) {
                            std2.insert(arreglo[i]+1,"-");
                        }

                        std2.insert(arreglo[i]+1,"'"); //inserto comillas
                        std2.insert(arreglo[i],"'");//inserto comillas
                    }
            std2.insert(0,"'"); //inserto comillas
            std2.append("')");
            Insertar->write(std2.toUtf8());
        }

    }
}

