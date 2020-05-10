#include "ventana.h"
#include "cb_pais.h"
#include "creat_table.h"
#include "mostrar.h"
#include "insertar.h"
#include <QFile>
#include <QDateTime>
#include <QSqlError>
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
    de_dia = new QDateEdit();

    layout->addWidget(teSelect,0,0,5,3);
    layout->addWidget(cb_pais,0,3);
    layout->addWidget(de_dia,1,3);
    layout->addWidget(pbSelect,2,3);
    box->setLayout(layout);
    box->show();

    manager = new QNetworkAccessManager;
    texto = new QByteArray;
    archivo = new QFile;
    archivo->setFileName("../db/documento.csv");
    archivo->open(QIODevice::ReadWrite);


    slot_solicitar();
    connect(manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(slot_respuesta(QNetworkReply *)));

    QDate actual5(2020,4,29);
    de_dia->setDate(actual5);

    qDebug()<<"INICIANDO...";

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../db/recuperados.sqlite");
    if(!db.open()){
        qDebug()<<"HUBO UN PROBLEMA EN LA CONECCION"<<db.lastError();
    }

    connect(pbSelect,SIGNAL(pressed()),this,SLOT(slot_Insertar()));

   // CrearTablaPais();
   // InsertarPais();
    cargar_cb();


}



void ventana::slot_Insertar(){
  // InsertarPais();
   // process_line();
   MostrarDatos();
}

void ventana::slot_respuesta(QNetworkReply *reply)
{
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
{
    QString ur = "https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv";
    QUrl url(ur);
    manager->get(QNetworkRequest(url));
    botonPresionado = (QPushButton*) this->sender();
}
