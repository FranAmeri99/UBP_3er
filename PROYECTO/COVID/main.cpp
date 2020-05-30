#include "inicio.h"
#include "grafico.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    inicio w;
    w.show();
/*
    Grafico grafico;
    grafico.resize(500,600);
    grafico.show();*/
    return a.exec();
}
