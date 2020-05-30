#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QObject>

#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>
class AdminDB : public QObject  {
    Q_OBJECT

public:
    explicit AdminDB( QObject * parent = nullptr );
    ~AdminDB();

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

    QVector< QStringList > select( QString comando );

    void creats();

    void insertar();

    void InsertarTable();


private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
