#include "ventana.h"
#include<QLabel>
#include<QDebug>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{

    layout = new QGridLayout;
    QLabel * lIngresar = new QLabel;
    pbActualizar= new QPushButton("Actulizar");
    leVelocidad= new QLineEdit("ingrese la velocidad");
    leDiametro = new QLineEdit("ingrese el diametro");

    QPixmap pix1("../Imagen/imagen.jpg");
    lIngresar->setPixmap(pix1.scaled(100 ,100));
    qDebug()<<pix1.size();

    layout->addWidget(leVelocidad,0,0,1,1);
    layout->addWidget(leDiametro,0,1,1,1);
    layout->addWidget(pbActualizar,0,2,1,1);
    layout->addWidget(lIngresar,2,0,4,4);

    this->setLayout(layout);

}

Ventana::~Ventana()
{
}

