#include "galeria.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Galeria w;
    w.show();
    return a.exec();
}
