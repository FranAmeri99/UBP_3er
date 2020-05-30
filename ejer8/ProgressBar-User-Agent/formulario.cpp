#include "formulario.h"

Formulario::Formulario(QWidget*parent) : QWidget(parent)
{
    adminDB = new AdminDB;
    adminDB->conectar( "../db/usuarios.sqlite" );

 /*   adminDB->CreatTable("datos");
    adminDB->insertar("datos");*/
}
