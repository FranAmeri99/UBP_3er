#include <QApplication>
#include "ventana.h"

int main(int argc, char ** argv){
    QApplication a(argc, argv);
    Ventana ventana;
    //Formulario min;
    //min.show();
    ventana.showMaximized();
    a.exec();
}
