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

#include "admindb.h"

QT_CHARTS_USE_NAMESPACE

// Define the scope for your variables and functions
class Grafico : public QMainWindow
{
    Q_OBJECT
public:
    explicit Grafico( AdminDB* OadminDB = nullptr, QString * provincia = nullptr , QWidget *parent = nullptr );

private:

    AdminDB * db;

    QLineSeries * infectados;
    QLineSeries * muertos;
    QLineSeries * infectadosD;
    QLineSeries * muertosD;
    QChart * chart;
    QFont font;
    QCategoryAxis * axisX;
    QChartView * chartView;


};

#endif // GRAFICP_H
