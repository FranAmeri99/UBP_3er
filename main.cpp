#include "ventana.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QWidget qwvent;
    ventana * vent = new ventana(&qwvent);
      //  vent->resize(800,600);
    return app.exec();
}

