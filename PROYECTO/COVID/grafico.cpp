#include "grafico.h"
#include <QApplication>
#include <QDebug>
#include "formulario.h"


Grafico::Grafico(AdminDB* OadminDB, QString * provincia , QWidget *parent) : QMainWindow(parent)
{

    const int tamano = 100;
    infectados = new QLineSeries();
    infectadosD = new QLineSeries();
    muertos = new QLineSeries();
    muertosD = new QLineSeries();
    if (!OadminDB){
        db  = new AdminDB();
        db->conectar("../db/usuarios.sqlite");

        qDebug()<<"se creo db";
    }
    else {
        qDebug()<<"se paso la db";
        this->db  = OadminDB;
    }

    axisX = new QCategoryAxis();

    QSqlQuery query;
    QString consulta = "SELECT * from datos where provincia = '";
    consulta.append(*provincia);
    consulta.append("'");

    query.exec( consulta );
    qDebug()<<query.lastError();
    int contador_de_registros = 0;
    int i = 0 ;
    while( query.next() )  {
        int casosT = query.value("casos_totales").toInt();
        int casosD = query.value("casos_nuevos").toInt();
        int muertosT = query.value("muertes_total").toInt();
        int muertosDia = query.value("muertes_nuevos").toInt();
        QString Numero_Dia;
        Numero_Dia.setNum(i);

        infectados->append(i, casosT);
        infectadosD->append(i, casosD);
        muertos->append(i, muertosT);
        muertosD->append(i, muertosDia);

        axisX->append(Numero_Dia,i);

        i++;
    }




    /*

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
    chart->legend()->hide();
    chart->addSeries(infectados);
    chart->addSeries(infectadosD);
    chart->addSeries(muertos);
    chart->addSeries(muertosD);
    chart->createDefaultAxes();

    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle(*provincia);

    QPen penC;
    penC.setColor("black");
    penC.setWidth(5);
    infectados->setPen(penC);
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

    chart->setAnimationOptions(QChart::AllAnimations);

    chartView = new QChartView(chart);

    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);

}
