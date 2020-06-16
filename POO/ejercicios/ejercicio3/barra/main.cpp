#include "ventana.h"

#include <QApplication>

//Ejercicio 3

//Cuando el valor del QSlider se modifique, colocar como título de la ventana el mismo valor (de 0 a 100).

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
    w.resize(600, 100);
    w.show();
    return a.exec();
}
