#include "widget.h"
#include "ui_widget.h"
#include<QSqlTableModel>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlError>
#include<QDebug>
//#include "qtdir/src/sql/drivers/psql/qsql_psql.cpp"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("localhost");
       db.setDatabaseName("qt");
       db.setUserName("root");
       db.setPassword("root");
       bool ok = db.open();
    if(!ok){
        QMessageBox::critical(this, "Error", db.lastError().text());
        return;
    }

    mTable = new QSqlTableModel(this);
    mTable->setTable("persona");
    mTable->select();
    ui->tableView->setModel(mTable);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pbNuevo_clicked()
{
    //mTable->insertRows(mTable->rowCount());

}
void Widget::on_pbActulizar_clicked()
{
    qDebug()<<"Actualizar";
 //   mTable->select();


}

void Widget::on_pbBorrar_clicked()
{

}
