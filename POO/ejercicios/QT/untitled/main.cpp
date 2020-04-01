#include <QApplication>

#include<QPushButton>
int main(int argc, char **argv)
{

    QApplication a(argc, argv);
    QPushButton pb("cerrar");

    QWidget v;

    v.show();
    pb.show();

    a.exec();
}
