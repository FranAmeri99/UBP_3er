#include "grafico.h"
#include <QApplication>
#include <QDebug>
#include <QValueAxis>
#include "formulario.h"
#include <QLegend>
#include <QVXYModelMapper>
Grafico::Grafico(AdminDB* OadminDB, bool * MIT, bool * MID, bool * MMT, bool * MMD, QString * provincia ,QString * provincia2 , QWidget *parent) : QMainWindow(parent)
{
    this->MIT = MIT;
    this->MID = MIT;
    this->MMT = MMT;
    this->MMD = MMD;
    QString Qprovincia1 = * provincia;
    QString Qprovincia2 = * provincia2;
    infectados = new QLineSeries();
    infectados->setName("infectados Totales: " + Qprovincia1);
    infectadosD = new QLineSeries();
    infectadosD->setName("infectados Dia: "+ Qprovincia1);
    muertos = new QLineSeries();
    muertos->setName("Fallecidos totales: " + Qprovincia1);
    muertosD = new QLineSeries();
    muertosD->setName("Fallecidos Dia: "+ Qprovincia1);
    infectados2 = new QLineSeries();
    infectadosD2 = new QLineSeries();
    muertos2 = new QLineSeries();
    muertosD2 = new QLineSeries();
    infectados2->setName("infectados Totales: " + Qprovincia2);
    infectadosD2->setName("infectados Totales: "+ Qprovincia2);
    muertos2->setName("Fallecidos Totales: " + Qprovincia2);
    muertosD2->setName("Fallecidos Dia: " + Qprovincia2);

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
    int maximo = 0;
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
        int total[4];
        total[0] = 0;
total[1] = 0;
total[2] = 0;
total[3] = 0;
        if(*provincia==nombre){

            if (*MIT == true)
            {
                total[0]= casosT;
                infectados->append(i, casosT);
            }else{
                total[0]= 0;
            }
            if (*MID == true)
            {
                total[1]= casosD;
                infectadosD->append(i, casosD);
            }
            else{
                total[1]= 0;
            }
            if (*MMT == true)
            {
                total[2]= muertosT;
                muertos->append(i, muertosT);
            }
            else{
                total[2]= 0;
            }
            if (*MMD == true)
            {
                total[3]= muertosDia;
                muertosD->append(i, muertosDia);
            }
            else{
                total[3]= 0;

            }


        } if(*provincia2==nombre){

            if (*MIT == true)
            {
                total[0]= casosT;
                infectados2->append(i, casosT);
            }if (*MID == true)
            {
                total[1]= casosD;
                infectadosD2->append(i, casosD);
            }if (*MMT == true)
            {
                total[2]= muertosT;
                muertos2->append(i, muertosT);
            }if (*MMD == true)
            {
                total[3]= muertosDia;
                muertosD2->append(i, muertosDia);
            }
        }
        dia.append(Numero_Dia);
        axisX->append(Numero_Dia,i);

        for(int i = 0; i<4; i++){
            //qDebug()<<i;

            if(maximo <= total[i]){
                maximo = total[i];
                qDebug()<<maximo;
            }
        }
        i++;
    }
    axisY->setRange(0.0, maximo);
    axisXY->append(dia);
    chart = new QChart();
    //chart->legend()->hide();



    if (*MIT == true)
    {
        chart->addSeries(infectados);
     if(*provincia != *provincia2) chart->addSeries(infectados2);

    }if (*MID == true)
    {
        chart->addSeries(infectadosD);
      if(*provincia != *provincia2)  chart->addSeries(infectadosD2);
       }
    if (*MMT == true)
    {
        chart->addSeries(muertos);
        if(*provincia != *provincia2) chart->addSeries(muertos2);

    }if (*MMD == true)
    {
        chart->addSeries(muertosD);
        if(*provincia != *provincia2) chart->addSeries(muertosD2);
    }

    axisY->setTickCount(30);
    axisY->setLabelFormat("%.03f");
    chart->createDefaultAxes();
    chart->setAxisX(axisXY);

    chart->setAxisY(axisY);

    font.setPixelSize(30);
    chart->setTitleFont(font);

    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("Grafico COVID ");

    chart->setAnimationOptions(QChart::AllAnimations);


    chartView = new QChartView(chart);


    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);

}
