#include "galeria.h"

Galeria::Galeria( QWidget * parent ) : QWidget( parent ){





        this->setWindowTitle("Ventana");
        layout = new QGridLayout();
        lImagen = new QLabel("<img src='../imagen/index.png' />");
        pbAtras = new QPushButton;
        pbAdelante = new QPushButton;
       pbAtras->setText("Atras");
        pbAdelante->setText("Adelante");
       lImagen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


        layout->addWidget(lImagen,0,0,1,2);
        layout->addWidget(pbAtras,5,0,1,1);
        layout->addWidget(pbAdelante,5,1,1,1);
        this->setLayout(layout);

}

void Galeria::cambiar()
{

}

