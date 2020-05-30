#include "formulario.h"
#include <QDebug>

Formulario::Formulario( QWidget * parent ) : QWidget( parent ){

    this->setWindowTitle("Ventana");
    layout = new QGridLayout();
    lImagen = new QLabel("<img src='../imagen/index.png' />");

    lImagen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


    layout->addWidget(lImagen,0,0,1,1);
    this->setLayout(layout);
}



