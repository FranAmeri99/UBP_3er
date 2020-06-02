#include "formulario.h"
#include <QMovie>
#include <QDebug>

Formulario::Formulario( QWidget * parent ) : QWidget( parent ){

    this->setWindowTitle("Ventana");
    layout = new QGridLayout();
    lImagen = new QLabel;
//    lImagen = new QLabel("<img src='../imagen/index.png' />");

    QMovie* movie = new QMovie("../imagen/cargando.gif");

    // Make sure the GIF was loaded correctly
    if (!movie->isValid())
    {
            qDebug()<<"pepe";
    }

    // Play GIF
    QLabel* label = new QLabel(this);
    lImagen->setMovie(movie);
    movie->start();


    lImagen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


    layout->addWidget(lImagen,0,0,1,1);
    this->setLayout(layout);
}



