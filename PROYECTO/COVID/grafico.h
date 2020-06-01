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

    explicit Grafico( AdminDB* OadminDB = nullptr , QString * provincia = nullptr , QWidget *parent = nullptr );
/*
    explicit Grafico(  QCheckBox * ptr_cbIT = nullptr,QCheckBox * ptr_cbID = nullptr, QCheckBox * ptr_cbMT = nullptr, QCheckBox * ptr_cbMD = nullptr, AdminDB* OadminDB = nullptr , QString * provincia = nullptr , QWidget *parent = nullptr );
*/
private:

    QLineSeries * infectados;
    QLineSeries * muertos;
    QLineSeries * infectadosD;
    QLineSeries * muertosD;
    AdminDB * db;
    QChart * chart;
    QFont font;
    QCategoryAxis * axisX;
    QChartView * chartView;

    QGridLayout * layout;

    QCheckBox * cbinfectadosT;
    QCheckBox * cbinfectadosD;
    QCheckBox * cbMuertosT;
    QCheckBox * cbMuertosD;

};

#endif // GRAFICP_H
