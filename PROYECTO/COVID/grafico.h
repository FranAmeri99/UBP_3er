#ifndef GRAFICP_H
#define GRAFICP_H

#include <QMainWindow>
#include <QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QCheckBox>
#include <QGridLayout>
#include "admindb.h"

QT_CHARTS_USE_NAMESPACE

// Define the scope for your variables and functions
class Grafico : public QMainWindow
{
    Q_OBJECT
public:

    explicit Grafico( AdminDB* OadminDB = nullptr , bool * MIT = nullptr , bool * MID = nullptr , bool * MMT = nullptr , bool * MMD = nullptr , QString * provincia = nullptr , QString * provincia2 = nullptr , QWidget *parent = nullptr );
public:


    //void sir( const state_type &x , state_type &dxdt , double t );
    //void write_sir(const state_type &x , const double t );

private:
    bool * MIT;
    bool * MID;
    bool * MMT;
    bool * MMD;
    QLineSeries * infectados;
    QLineSeries * muertos;
    QLineSeries * infectadosD;
    QLineSeries * muertosD;
    AdminDB * db;
    QChart * chart;
    QFont font;
    QCategoryAxis * axisX;
    QChartView * chartView;


    QLineSeries * infectados2;
    QLineSeries * muertos2;
    QLineSeries * infectadosD2;
    QLineSeries * muertosD2;

    QLineSeries * InfectadosSIR;
    QLineSeries * SuceptiblesSIR;
    QLineSeries * RecuperadosSIR;



};

#endif // GRAFICP_H
