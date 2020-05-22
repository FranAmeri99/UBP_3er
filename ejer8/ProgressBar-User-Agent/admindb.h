#ifndef ADMINDB_H
#define ADMINDB_H

#include <QWidget>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>

class adminDB : public QWidget
{
    Q_OBJECT
public:
    explicit adminDB(QWidget *parent = nullptr);
    void CreatTable(QString nombreTable);
    void InsertarTable(QString nombreTable);
    void MostrarTable(QString nombreTable);
    QSqlDatabase db;

signals:

};

#endif // ADMINDB_H
