#include "grafico.h"
#include <QApplication>
#include <QDebug>
#include "formulario.h"

Grafico::Grafico(AdminDB* OadminDB, QString * provincia , QWidget *parent) : QMainWindow(parent)
{

    const int tamano = 100;
    series = new QLineSeries();
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
        int casos = query.value("casos_totales").toInt();
        QString Numero_Dia;
        Numero_Dia.setNum(i);

        series->append(i, casos);

        axisX->append(Numero_Dia,i);

        i++;
    }


    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle(*provincia);

    QPen pen(QRgb(0x000000));
    pen.setWidth(5);
    series->setPen(pen);

    chart->setAnimationOptions(QChart::AllAnimations);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);

}
