#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent, QString*nombre ) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    QString nombreTitulo = * nombre;
    this->setWindowTitle(nombreTitulo);
    ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete ui;
}
