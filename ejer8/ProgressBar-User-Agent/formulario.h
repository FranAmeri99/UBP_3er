#ifndef DBADMIN_H
#define DBADMIN_H

#include <QWidget>
#include "admindb.h"

class Formulario : public QWidget
{
    Q_OBJECT
public:
    explicit Formulario(QWidget *parent = nullptr);

private:
    AdminDB * adminDB;


};

#endif // DBADMIN_H
