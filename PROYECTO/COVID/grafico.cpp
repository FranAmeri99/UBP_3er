#include "grafico.h"
#include <QApplication>
#include <QDebug>
#include <QValueAxis>
#include "formulario.h"
#include <QLegend>
#include <QVXYModelMapper>

#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>



Grafico::Grafico(AdminDB* OadminDB, bool * MIT, bool * MID, bool * MMT, bool * MMD, QString * provincia ,QString * provincia2 , QWidget *parent) : QMainWindow(parent)
{
    this->MIT = MIT;
    this->MID = MIT;
    this->MMT = MMT;
    this->MMD = MMD;

    QString Qprovincia1 = * provincia;
    QString Qprovincia2 = * provincia2;
    QLineSeries * limite = new QLineSeries();
    limite->setName("Limite sistema de salud");

    InfectadosSIR = new QLineSeries();
    SuceptiblesSIR = new QLineSeries();
    RecuperadosSIR = new QLineSeries();
    InfectadosSIR ->setName("Infectados SIR");
    SuceptiblesSIR ->setName("Suceptibles SIR");
    RecuperadosSIR ->setName("Recuperados SIR");

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
    }
    else {
        this->db  = OadminDB;
    }
    QStringList dia;

    axisX = new QCategoryAxis(this);
    auto axisY = new QValueAxis(this);

    QSqlQuery query2;
int poblacion;
    //
    query2.exec("select * from provincia where nombre = '" + *provincia + "'");
    while (query2.next()) {
    poblacion =  query2.value( "poblacion" ).toInt();
    }

    qDebug()<<" + " << poblacion;
    //
   // int poblacion = 1000000;
   // poblacion = pobl.toInt();
  //  qDebug()<<poblacion;
//    QSqlQuery query2;
    QString consulta2 = "SELECT * from sir";
    query2.exec(consulta2);
    double maximo2;


    int diaaa = 0;
    while (query2.next()){
        //qDebug()<<diaaa;
        diaaa++;
        double fecha= query2.value( 0 ).toDouble();
        double suceptibles = query2.value( 1 ).toDouble();
        double infecatados = query2.value( 2 ).toDouble();
        double recuperados  = query2.value( 3 ).toDouble();
        InfectadosSIR->append(fecha, infecatados*poblacion);
        SuceptiblesSIR->append(fecha, suceptibles);
        RecuperadosSIR->append(fecha, recuperados);
        if(maximo2 < infecatados * poblacion){
        maximo2 = infecatados * poblacion;
        }
       // dia.append(QString::number(fecha));

        //qDebug()<<maximo2;
    }
    //chartView->chart()->setAxisY(axisY);
    QSqlQuery query;
    QString consulta = "SELECT * from datos where provincia = '" + *provincia + "'";
    consulta.append("OR  provincia = '" + *provincia2 + "'");
    query.exec( consulta );
   // qDebug()<<query.lastError();
   // int contador_de_registros = 0;
    int i = 0 ;
    int maximo = 0;
    int maxSitema = 10000;
    auto axisXY = new QBarCategoryAxis(this);

    while( query.next() ){
        QString nombre = query.value( "provincia" ).toString();
        int casosT = query.value( "casos_totales" ).toInt();
        int casosD = query.value( "casos_nuevos" ).toInt();
        int muertosT = query.value( "muertes_total" ).toInt();
        int muertosDia = query.value( "muertes_nuevos" ).toInt();
        QString Numero_Dia;
        Numero_Dia.setNum(i);
        int total[4];
        total[0] = 0;
        total[1] = 0;
        total[2] = 0;
        total[3] = 0;
        if ( *provincia==nombre ){
            if ( *MIT == true ){
                total[0]= casosT;
                infectados->append(i, casosT);
            }
            if ( *MID == true ) {
                total[1]= casosD;
                infectadosD->append(i, casosD);
            }
            if ( *MMT == true )
            {
                total[2]= muertosT;
                muertos->append(i, muertosT);
            }
            if (*MMD == true){
                total[3]= muertosDia;
                muertosD->append(i, muertosDia);
            }
        }
        if(*provincia2==nombre){
            if (*MIT == true){
                total[0]= casosT;
                infectados2->append(i, casosT);
            }
            if (*MID == true){
                total[1]= casosD;
                infectadosD2->append(i, casosD);
            }
            if (*MMT == true){
                total[2]= muertosT;
                muertos2->append(i, muertosT);
            }
            if (*MMD == true){
                total[3]= muertosDia;
                muertosD2->append(i, muertosDia);
            }
        }

        dia.append(Numero_Dia);
       // axisX->append(Numero_Dia,i);

        for(int i = 0; i<4; i++){
            if(maximo <= total[i]){
                maximo = total[i];//obtener el mayot valor y setearlo
            }                       //como maximo en el eje Y
        }
        limite->append(i,maxSitema ); //limite sistema de salud
        i++;
    }
    if(maxSitema>maximo){
        maximo=maxSitema;
    }
    axisY->setRange(0.0, maximo2);
    axisXY->append(dia);
    chart = new QChart();
    chart->addSeries(InfectadosSIR);
  /*  chart->addSeries(SuceptiblesSIR);
    chart->addSeries(RecuperadosSIR);*/

    if (*MIT == true){
       // chart->addSeries(limite);
        chart->addSeries(infectados);
        if(*provincia != *provincia2) chart->addSeries(infectados2);
    }
    if (*MID == true){
        chart->addSeries(infectadosD);
        if(*provincia != *provincia2)  chart->addSeries(infectadosD2);
    }
    if (*MMT == true){
        chart->addSeries(muertos);
        if(*provincia != *provincia2) chart->addSeries(muertos2);
    }
    if (*MMD == true){
        chart->addSeries(muertosD);
        if(*provincia != *provincia2) chart->addSeries(muertosD2);
    }
    QPen pen;
    QColor red;
    red.setRed(255);
    pen.setColor(red);
    limite->setPen(pen);
    axisY->setTickCount(30);//divido al eje y en 30
    axisY->setLabelFormat("%.0f");//con valores enteros
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
