#include "ventana.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
    w.resize(300, 50);
    w.show();
    return a.exec();
}
