#include "ventana.h"
#include <QFile>
#include<QDateTime>
#include<QSqlError>
#include <QDir>
ventana::ventana(QWidget *parent) : QWidget(parent)
{
//Ventana
    box = new QGroupBox;
    layout = new QGridLayout;
    pbSelect = new QPushButton("BUSCAR");
    pbSalir = new QPushButton("Salir");
    teSelect = new QTableWidget();
    teSelect->setColumnCount(5);

    //Forma rancia de convertir QDate con la fecha a string
/*
    QDate actual2;
    QDate aux = actual2.currentDate();
    QString auxS = aux.toString();
    qDebug()<<"------------------",auxS,"aaaaaaaa";
    QStringList headers = { "ESTADO", "PAIS", "LATITUD","longitud",auxS};
    teSelect->setHorizontalHeaderLabels(headers);*/

    layout->addWidget(pbSelect,0,0,1,2);
   // layout->addWidget(pbSalir,0,1);
    layout->addWidget(teSelect,1,0,2,2);
    box->setLayout(layout);
    box->show();

//Base de datos

    qDebug()<<"iniciando";
    QString nombre;
    //si la encutra la abre, sino la crea
    nombre.append("recuperados.sqlite");
    //nombre.append("recuperados.sql");
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db = QSqlDatabase::addDatabase("QSQL");
    db.setDatabaseName(nombre);
   if( db.open()){
       qDebug()<<"joya";
   }
   else {
       qDebug()<<"todo mal";
   }
   connect(pbSelect,SIGNAL(pressed()),this,SLOT(slot_Insertar()));
  // connect(pbSalir,SIGNAL(pressed()),this, SLOT(close()));
}

void ventana::CrearTablaUsuario()
{
    qDebug()<<"\n CREAR";

    QString consulta;

    consulta.append("CREATE TABLE IF NOT EXISTS USUARIO("
                    "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "NOMBRE VARCHAR(100),"
                    "APELLIDO VARCHAR(100),"
                    "EDAD INTEGER NOT NULL,"
                    "CLASE INTEGER NOT NULL"
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec()){
        qDebug()<<"\n Creado";
    }
    else {
        qDebug()<<"\n NO Creado";
    }
    //    CrearTablaUsuario();
}

void ventana::InsertarUsuario()
{
    qDebug()<<"\n Insertar";

    QString consulta;
    consulta.append("INSERT INTO USUARIO(NOMBRE, APELLIDO, EDAD,"
                    "CLASE)"
                    "VALUES("
                    "'pepe',"
                    "'AMERI',"
                    "21,"
                    "2017"
                    ");");

    QSqlQuery insertar;
    insertar.prepare(consulta);
    if(insertar.exec()){
        qDebug()<<"\n Insertado";
    }
    else {
        qDebug()<<"\n NO Insertado ";
    }
}

void ventana::MostrarDatos(){
    //BARRA SUPERIOR
    QDate actual2;
    QDate aux = actual2.currentDate();
    QString auxS = aux.toString();
    qDebug()<<"------------------",auxS,"--------------";
    QStringList headers = { "ESTADO", "PAIS", "LATITUD","longitud",auxS};
    teSelect->setHorizontalHeaderLabels(headers);
    qDebug()<<"\n joya 3";


    //CONSULTA
    QSqlQuery mostrar;

    QString consulta;
    //hacer mas bonito el select para que solo muestre las columnas de Country, Province, lat , long, QDate acutal::currentDate()
    //por el momento traigo todas las columasn

    //consulta.append("SELECT * FROM USUARIO");
   //consulta.append("SELECT * FROM recuperados ");
    //consulta.append("SELECT * FROM recuperados WHERE lat = -38.4161");
    consulta.append("SELECT * FROM recuperados WHERE Country = 'Argentina'");

    mostrar.prepare(consulta);
    if(mostrar.exec()){
        qDebug()<<"\n mostrado";

    }
    else {

        qDebug()<<"\n NO mostrado "<<mostrar.lastError();
    }

    int fila =0;
    teSelect->setRowCount(0);
    while(mostrar.next()){


    QDate inicio(2020, 1, 22);
    QDate actual2;
    QDate aux = actual2.currentDate();
    int a = inicio.daysTo(aux)+3;
    qDebug()<<"========="<<a;
    //como muestro las primeas cuatro columnas en orden correspondiente a la tabla
    //la quinta columna trae los datps de la ultima columna de la tabla
    //que es una diferencia entre la fecha de la fecha actual menos la de inicio mas 4 (columnas estado, pais, lat, long
    teSelect->insertRow(fila);

    teSelect->setItem(fila, 1,new QTableWidgetItem(mostrar.value(1).toByteArray().constData()));
    teSelect->setItem(fila, 0,new QTableWidgetItem(mostrar.value(0).toByteArray().constData()));
    teSelect->setItem(fila, 2,new QTableWidgetItem(mostrar.value(2).toByteArray().constData()));
    teSelect->setItem(fila, 3,new QTableWidgetItem(mostrar.value(3).toByteArray().constData()));
    teSelect->setItem(fila, 4,new QTableWidgetItem(mostrar.value(a).toByteArray().constData()));

    fila ++;

    }
}




void ventana::slot_Insertar(){
   CrearTablaUsuario();

   InsertarUsuario();
   MostrarDatos();

}
