#include <QApplication>
#include "ventana.h"

int main( int argc, char ** argv )  {
    QApplication app ( argc, argv );

    Ventana * ventana = new Ventana;
    ventana->resize( 800, 600 );
    ventana->show();

    return app.exec();
}

