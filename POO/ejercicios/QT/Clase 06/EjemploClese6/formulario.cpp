#include "formulario.h"

#include <QDebug>

Formulario::Formulario( QWidget * parent ) : QWidget( parent )  {

    lNombre = new QLabel( "Nombre" );
    lApellido = new QLabel( "Apellido" );
    lLegajo = new QLabel( "Legajo" );

    leNombre = new QLineEdit;
    leApellido = new QLineEdit;
    leLegajo = new QLineEdit;
    leLegajo->setEchoMode( QLineEdit::Password );

    pbAlta = new QPushButton( "Alta" );
    pbSalir = new QPushButton( "Salir" );

    layout = new QGridLayout;

    //       0        1        2     3
    // -- Nombre ---                     ---- 0
    // -- Apellido--                     ---- 1
    // -- Legajo----       ------------------ 2
    // --- ---------------------------------- 3
    // -------------------- Alta -- Salir---- 4

    layout->addWidget( lNombre,     0, 0, 1, 1 );
    layout->addWidget( lApellido,   1, 0, 1, 1 );
    layout->addWidget( lLegajo,     2, 0, 1, 1 );

    layout->addWidget( leNombre,    0, 1, 1, 3 );
    layout->addWidget( leApellido,  1, 1, 1, 3 );
    layout->addWidget( leLegajo,    2, 1, 1, 1 );

    layout->addWidget( pbAlta,      3, 2, 1, 1 );
    layout->addWidget( pbSalir,     3, 3, 1, 1 );

    this->setLayout( layout );

    connect( pbAlta, SIGNAL( pressed() ), this, SLOT( slot_alta() ) );
    connect( pbSalir, SIGNAL( pressed() ), this, SLOT( slot_salir() ) );

}

void Formulario::slot_alta()  {
    qDebug() << "Se dio de alta: " << leNombre->text() << leApellido->text() << leLegajo->text();
    leNombre->setText( "" );
    leApellido->clear();
}


void Formulario::slot_salir()  {
    qDebug() << "Hasta luego";
    this->close();
}







