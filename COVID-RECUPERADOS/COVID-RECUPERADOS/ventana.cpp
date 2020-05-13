#include "ventana.h"
#include "cb_pais.h"
#include "creat_table.h"
#include "mostrar.h"
#include "insertar.h"
#include "drop_table.h"
#include <QFile>
#include <QDateTime>
#include <QSqlError>
#include <QDir>
using namespace std;
ventana::ventana(QWidget *parent) : QWidget(parent)
{   box = new QGroupBox;
    layout = new QGridLayout;
    pbSelect = new QPushButton("BUSCAR");
    pbSalir = new QPushButton("Salir");
    teSelect = new QTableWidget();
    teSelect->setColumnCount(5);
    pbCrear= new QPushButton("CREAR");
    pbBorrar= new QPushButton("BORRAR");
    pbInsertar= new QPushButton("INSERTAR");
    pbCargar= new QPushButton("CARGAR");
    cb_pais = new QComboBox();
    de_dia = new QDateEdit();

    layout->addWidget(teSelect,0,0,7,4);
    layout->addWidget(pbBorrar,0,5);
    layout->addWidget(pbCrear,1,5);
    layout->addWidget(pbInsertar,2,5);
    layout->addWidget(pbCargar,3,5);
    layout->addWidget(cb_pais,4,5);
    layout->addWidget(de_dia,5,5);
    layout->addWidget(pbSelect,6,5);
    box->setLayout(layout);
    box->show();

    texto = new QByteArray;
    archivo = new QFile;
    archivo->setFileName("../db/documento.csv");
    archivo->open(QIODevice::ReadWrite);

    manager = new QNetworkAccessManager;
   // slot_solicitar();
  //  connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(slot_respuesta(QNetworkReply *)));

    QDate actual5(2020,4,29); //seteo un dia para agilisar el tesst
    de_dia->setDate(actual5);
    //CREO/CONECTO LA BASE DE DATOS
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/recuperados.sqlite");
    if(!db.open()){
        qDebug()<<"HUBO UN PROBLEMA EN LA CONECCION"<<db.lastError();
    }

    connect(pbBorrar,SIGNAL(pressed()),this,SLOT(slot_Borrar()));
    connect(pbCrear,SIGNAL(pressed()),this,SLOT(slot_Crear()));
    connect(pbInsertar,SIGNAL(pressed()),this,SLOT(slot_Insertar()));
    connect(pbCargar,SIGNAL(pressed()),this,SLOT(slot_CargarCB()));
    connect(pbSelect,SIGNAL(pressed()),this,SLOT(slot_Mostrar()));

}

void ventana::slot_Borrar(){
    BorraTable();
}
void ventana::slot_Crear(){
    CrearTablaPais();
}
void ventana::slot_Insertar(){
    InsertarPais();
}

void ventana::slot_CargarCB(){
    cargar_cb();
}
void ventana::slot_Mostrar(){
    MostrarDatos();
}
void ventana::slot_respuesta(QNetworkReply *reply)
{    //ESCRIBO EN UN ARCHIVO LOS TRAIDOS
    *texto = reply->readAll();
    archivo->write(*texto);
}

void ventana:: process_line(){
    process_line(line);
}

void ventana:: process_line(QByteArray * line){

    while (!archivo->atEnd()) {
            QByteArray line = archivo->readLine();
        }

}
void ventana::slot_solicitar()
{   //TRAIGO EL CONTENDIO LA PAGINA DONDE SE ENCUENTRAN LOS DATOS QUE VOY A PROCESAR
    QString ur = "https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv";
    QUrl url(ur);
    manager->get(QNetworkRequest(url));
    botonPresionado = (QPushButton*) this->sender();
}
