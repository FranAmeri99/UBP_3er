#include <QApplication>
#include "ventana.h"

int main (int argc, char ** argv){
    QApplication app (argc, argv);
    QWidget qwvent;
    ventana * vent = new ventana(&qwvent);

    return app.exec();
}
