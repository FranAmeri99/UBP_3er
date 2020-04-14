#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSqlDatabase>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QSqlTableModel;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pbNuevo_clicked();
    void on_pbActulizar_clicked();
    void on_pbBorrar_clicked();

private:
    Ui::Widget *ui;
    QSqlTableModel * mTable;
    QSqlDatabase * mDatabase;
};
#endif // WIDGET_H
