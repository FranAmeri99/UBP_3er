#include "grafico.h"
#include <QApplication>
#include <QDebug>
#include <QValueAxis>
#include "formulario.h"


Grafico::Grafico(AdminDB* OadminDB, QString * provincia ,QString * provincia2 , QWidget *parent) : QMainWindow(parent)
{
    infectados = new QLineSeries();
    infectadosD = new QLineSeries();
    muertos = new QLineSeries();
    muertosD = new QLineSeries();
// //////////////// agregar combobox ////////////////
    cbinfectadosT = new QCheckBox("Infectados Totales");
    cbinfectadosD= new QCheckBox("Infectados Dia");
    cbMuertosT= new QCheckBox("Muertos Totales");
    cbMuertosD= new QCheckBox("Muertos Dia");
// //////////////// dosp provincias /////////////////
    infectados2 = new QLineSeries();
    infectadosD2 = new QLineSeries();
    muertos2 = new QLineSeries();
    muertosD2 = new QLineSeries();
    if (!OadminDB){
        db  = new AdminDB();
        db->conectar("../db/usuarios.sqlite");

        qDebug()<<"se creo db";
    }
    else {
        qDebug()<<"se paso la db";
        this->db  = OadminDB;
    }

     axisX = new QCategoryAxis(this);
    auto axisY = new QValueAxis(this);

    //chartView->chart()->setAxisY(axisY);
    QSqlQuery query;
    QString consulta = "SELECT * from datos where provincia = '" + *provincia + "'";
    consulta.append("OR  provincia = '" + *provincia2 + "'");

    query.exec( consulta );
    qDebug()<<query.lastError();
   // int contador_de_registros = 0;
    int i = 0 ;
    int maximo;
    auto axisXY = new QBarCategoryAxis(this);
    QStringList dia;
    while( query.next() )  {

        QString nombre = query.value("provincia").toString();
        int casosT = query.value("casos_totales").toInt();
        int casosD = query.value("casos_nuevos").toInt();
        int muertosT = query.value("muertes_total").toInt();
        int muertosDia = query.value("muertes_nuevos").toInt();
        QString Numero_Dia;
       // qDebug()<<nombre;
        Numero_Dia.setNum(i);
        if(*provincia==nombre){
            infectados->append(i, casosT);
            infectadosD->append(i, casosD);
            muertos->append(i, muertosT);
            muertosD->append(i, muertosDia);


        } if(*provincia2==nombre){

        infectados2->append(i, casosT);
        infectadosD2->append(i, casosD);
        muertos2->append(i, muertosT);
        muertosD2->append(i, muertosDia);
        }
        dia.append(Numero_Dia);
        axisX->append(Numero_Dia,i);


        if(maximo < casosT){
            maximo = casosT;

        }
        i++;
    }
    axisY->setRange(0.0, maximo);
    axisXY->append(dia);
    /*
     *
     *

    if ( ptr_cbIT->isChecked() ) {
        chart->addSeries(infectados);
    }
    if ( ptr_cbIT->isChecked() ) {
        chart->addSeries(infectadosD);
    }
    if ( ptr_cbIT->isChecked() ) {
        chart->addSeries(muertos);
    }
    if ( ptr_cbIT->isChecked() ) {
        chart->addSeries(muertosD);
    }

      */

    chart = new QChart();
    chart->legend();
    //chart->legend()->hide();

    chart->addSeries(infectados);
    chart->addSeries(infectados2);/*
    chart->addSeries(infectadosD);
    chart->addSeries(muertos);
    chart->addSeries(muertosD);*/
    axisY->setTickCount(30);
    axisY->setLabelFormat("%.0f");

    chart->createDefaultAxes();
//    chart->setAxisX(axisX);
    chart->setAxisX(axisXY);

    chart->setAxisY(axisY);

    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Grafico COVID \n en azul "+ *provincia+ ", en rojo "+*provincia2);

    QPen penC;
    penC.setColor("blue");
    penC.setWidth(5);
    infectados->setPen(penC);
    QPen penC2;

    penC2.setColor("red");
    penC2.setWidth(5);
    infectados2->setPen(penC2);
    /*
    QPen penCD;
    penCD.setColor("green");
    penCD.setWidth(5);
    infectadosD->setPen(penCD);
    QPen penM;
    penM.setColor("red");
    penM.setWidth(2);
    muertos->setPen(penM);
    QPen penMD;
    penMD.setColor("blue");
    penMD.setWidth(2);
    muertosD->setPen(penMD);
*/
    chart->setAnimationOptions(QChart::AllAnimations);

    chartView = new QChartView(chart);
   // layout->addWidget(chartView,2,0);
   // chartView->setLayout(layout);

    chartView->setRenderHint(QPainter::Antialiasing);
    //this->setLayout(layout);

    this->setCentralWidget(chartView);

}
