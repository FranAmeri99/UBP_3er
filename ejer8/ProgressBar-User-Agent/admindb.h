#ifndef ADMINDB_H
#define ADMINDB_H

#include <QWidget>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>

#include <QString>
#include <QStringList>
#include <QVector>
#include <QObject>
#include <QMessageBox>
#include <QFile>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);
    void CreatTable(QString nombreTable);
    QSqlDatabase db;

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    QVector< QStringList > select( QString comando );

    QStringList campos( QString tabla );

    void creats();

    void insertar( QString nombreTabla );

    void mostrar( QString nombreTabla , QString provincia );

    QFile * ProvinciaCSV ;



signals:

};

#endif // ADMINDB_H
