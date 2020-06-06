#include "admindb.h"
#include "formulario.h"
#include <QVariant>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QFile>

AdminDB::AdminDB( QObject * parent ) : QObject( parent )  {
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminDB::~AdminDB()  {
    db.close();
}

bool AdminDB::conectar( QString archivoSqlite )  {

    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}


/**
 * @brief Método que ejecuta una consulta SQL a la base de datos que ya se encuentra conectado.
          Utiliza QSqlQuery para ejecutar la consulta, con el método next() se van extrayendo
          los registros que pueden ser analizados con QSqlRecord para conocer la cantidad de
          campos por registro.
 * @param comando es una consulta como la siguiente: SELECT nombre, apellido, id FROM usuarios
 * @return Devuelve un QVector donde cada elemento es un registro, donde cada uno de estos registros
           están almacenados en un QStringList que contiene cada campo de cada registro.
 */
QVector< QStringList > AdminDB::select( QString comando )  {

    QVector< QStringList > vRegistros;
    if ( db.isOpen() && comando.startsWith( "select", Qt::CaseInsensitive ) )  {
        QSqlQuery query( db );
        bool exito = query.exec( comando );

        if ( exito )  {
            while( query.next() )  {

                QSqlRecord registro = query.record();
                int cantidad_registros = registro.count();
                QStringList valores_campos;

                for ( int i = 0 ; i < cantidad_registros ; i++ )  {

                    QString valor = registro.value( i ).toString();
                    valores_campos.append( valor );  // igual a   valores_campos << valor;
                }

                vRegistros.append( valores_campos );
            }
        }
    }

    return vRegistros;
}




void AdminDB::creats()
{
    QByteArray borrar = "DROP TABLE datos";
    QSqlQuery query( db );
    query.exec(borrar);
    //query.exec(borrar);
    qDebug()<<"Admin Create";
    QByteArray crear = "CREATE TABLE IF NOT EXISTS datos";
    crear.append(" (fecha VARCHAR, provincia VARCHAR, "
                 "casos_totales VARCHAR, casos_nuevos "
                 "VARCHAR, muertes_total VARCHAR, "
                 "muertes_nuevos VARCHAR, descripcion VARCHAR)");
    QSqlQuery query2( db );
    query2.exec(crear);
    qDebug() << query2.lastError();  // Devuelve un objeto de QSqlError // Devuelve un objeto de QSqlError

}

void AdminDB::creatsSir()
{

    QSqlQuery query( db );
    QByteArray borrar_sir = "DROP TABLE sir";
    query.exec(borrar_sir);
    QByteArray crear_sir = "CREATE TABLE IF NOT EXISTS sir";
    crear_sir.append(" (fecha double, susecptible double, "
                 "infectados double, recuperados double)");
    QSqlQuery query3( db );
    query3.exec(crear_sir);
    qDebug() << query3.lastError();
}

void AdminDB::insertar()
{

    int posicion = 0;
    int contador = 0;
    qDebug()<<"Admin Insertar";

    QFile *  ProvinciaCSV = new QFile;
    ProvinciaCSV->setFileName("../db/ProvinciaCSV.csv");
    //Leo CSV
    ProvinciaCSV->open(QIODevice::ReadOnly|QIODevice::Text);
    if (!ProvinciaCSV->isOpen()){
        qDebug()<<"No se pudo abrir";
    }
    //CREO UN ARCHIVO TXT PARA PODER VISUALISAR MEJOR LAS CONSULTAS Y NO VERLAS
    // POR EL DEBUG
    QFile * Insertar = new QFile;
    Insertar->setFileName("../db/Insertar.txt");
    Insertar->open(QIODevice::ReadWrite|QIODevice::Text);
    if (!Insertar->isOpen()){
        qDebug()<<"No se pudo abrir insertar";
    }
    int contadore = 0;
    while ( ! ProvinciaCSV->atEnd() )  {

        QByteArray line = ProvinciaCSV->readLine();
        //como la primera linea del csv contiene los nombres de las columas la omito en la insercion
        if(!line.startsWith("provincia")){
            contadore++;
            //qDebug()<<contadore;
        QString std = QString(line);
        QString std2 = std.mid(0,(std.size()-2));//para omitir la barra n
        int agregar = std2.count(',')+1; //cantida de comas que pose la linea
        int arreglo[agregar] ; //contiene las posiciones donde estan las comas


        QByteArray queryI = "INSERT INTO datos ( ";
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
            if (arreglo[i]+1 == arreglo[i+1] or arreglo[i+1] == std2.size()) {
                std2.insert(arreglo[i]+1,"0");
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
            //
            qDebug()<<"  Insertado ";
            //qDebug()<<"INSERCION numeros de coma"<< agregar << ", posicion"<<posicion;
        }else{
          //  qDebug()<<queryI;
            //   qDebug()<<"\nNO INSERCION numeros de coma"<< agregar << ", posicion"<<posicion<<"\n";
               //qDebug()<<inser.lastError();
               contador ++;
        }
        queryI.append("\n");
        Insertar->write(queryI);

        posicion ++;
        }
    }
    qDebug()<<"CONTADOR DE ERRORES"<<contador;
    Insertar->close();
    ProvinciaCSV->close();

}

void AdminDB::CrearProvincias()
{

    QStringList listaProv = {"Buenos Aires","CABA","Catamarca","Chaco",
                             "Chubut","Córdoba","Corrientes","Entre "
                             "Ríos","Formosa","Jujuy","La Pampa",
                             "La Rioja","Mendoza","Misiones","Neuquén",
                             "Río Negro","Salta","San Juan","Santa Cruz",
                             "Santiago del Estero","Tierra del Fuego","Tucumán"};
    QStringList listaPoblacion = {"15594428","2891082","3304825","3300736","2891082",
                                  "1741610","1592878","1236300","1215207","1097829",
                                  "1053466","993338","896461","680427","672260",
                                  "633374","550344","527895","506668","461588",
                                  "367820","331847","316940","272524","126190"};

    QSqlQuery query( db );
    query.exec("DROP TABLE provincia");
    qDebug()<<"Admin Create";
    QByteArray crear = "CREATE TABLE IF NOT EXISTS provincia";
    crear.append(" (nombre VARCHAR, poblacion int)");
    QSqlQuery query2( db );
    query2.exec(crear);

    for (int i = 0 ; i< listaProv.size() ; i++) {
        QByteArray insertar = "INSERT INTO provincia (nombre, poblacion) values"
                              "('" + listaProv[i].toUtf8() +"', '"
                                +  listaPoblacion[i].toUtf8()+ "')";
        query2.exec(insertar);
        qDebug()<<query2.lastError();
    }

}









