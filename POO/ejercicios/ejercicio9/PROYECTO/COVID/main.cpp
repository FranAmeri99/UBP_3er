#include "inicio.h"
#include "grafico.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    inicio w;
    w.setWindowIcon(QIcon("../db/icono.ico"));
    w.resize(500,600);
    w.show();

    return a.exec();
}
