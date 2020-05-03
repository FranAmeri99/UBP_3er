#include "ventana.h"
#include <QFile>
#include<QDateTime>
#include<QSqlError>
#include <QDir>
using namespace std;
ventana::ventana(QWidget *parent) : QWidget(parent)
{
//Ventana
    box = new QGroupBox;
    layout = new QGridLayout;
    pbSelect = new QPushButton("BUSCAR");
    pbSalir = new QPushButton("Salir");
    teSelect = new QTableWidget();
    teSelect->setColumnCount(5);

    cb_pais = new QComboBox();
    cb_estado = new QComboBox();
    de_dia = new QDateEdit();



    layout->addWidget(cb_pais,0,3,1,1);
    layout->addWidget(pbSelect,3,3,1,1);
    layout->addWidget(teSelect,0,0,3,3);
    box->setLayout(layout);
    box->show();

    manager = new QNetworkAccessManager;
    texto = new QByteArray;
    archivo = new QFile;
    archivo->setFileName("documento.csv");
    archivo->open(QIODevice::WriteOnly);
    slot_solicitar();
    connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(slot_respuesta(QNetworkReply *)));
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

cargar_cb();
}

void ventana::CrearTablaUsuario()
{
    qDebug()<<"\n CREAR";

    QString consulta;

    consulta.append("CREATE VIRTUAL TABLE IF NOT EXISTS USUARIO2 USING CSV ('documento.csv')"

                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec()){
        qDebug()<<"\n Creado2";
    }
    else {
        qDebug()<<"\n NO Creado"<<crear.lastError();
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
        qDebug()<<"\n NO Insertado "<<insertar.lastError();
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
    //consulta.append("SELECT * FROM recuperados WHERE Country = 'Argentina' ");
    consulta.append("SELECT * ");
        //dia del combo box
    QString a = cb_pais->currentText();
    //string aux2 = a.toStdString();
    //qDebug()<<"-------------------"<<aux2<<"-------------------";
    bool estado = a.contains(',');
    if(!estado){
    consulta.append("FROM recuperados WHERE Country = '");
    consulta.append(a);
    // aux.append(aux2);
    consulta.append("';");

    }
    else{
        consulta.append("FROM recuperados WHERE Province = '");
        int p = a.indexOf(',');
        QString pp = a.mid(p+2,-1);
        consulta.append(pp);
        // aux.append(aux2);
        consulta.append("';");
        qDebug()<<"@@@@@@@@@@@@@@@@@@@"<<consulta<<"@@@@@@@@@@@@@@@@@@@";
    }
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
    int a = inicio.daysTo(aux)+2;
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

void ventana::cargar_cb()
{

    //CONSULTA
    QSqlQuery cargar_pais;

    QString consulta;
    consulta.append("SELECT Country, Province FROM recuperados");

    cargar_pais.prepare(consulta);
    if(cargar_pais.exec()){
        qDebug()<<"\n mostrado";

    }
    else {

        qDebug()<<"\n combo box"<<cargar_pais.lastError();
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

void ventana::slot_Insertar(){
   CrearTablaUsuario();



   InsertarUsuario();
   MostrarDatos();

}

void ventana::slot_respuesta(QNetworkReply *reply)
{
    *texto = reply->readAll();
        archivo->write(*texto);
}

void ventana::slot_solicitar()
{
    QString ur = "https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv";
    QUrl url(ur);
    manager->get(QNetworkRequest(url));
    botonPresionado = (QPushButton*) this->sender();
}
