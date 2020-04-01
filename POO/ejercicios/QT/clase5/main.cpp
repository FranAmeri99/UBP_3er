//#include "mainwindow.h"
#include <QApplication>
#include<QLabel>
#include<QPushButton>
//#include<QObject>


#define PI int funcion(){return 6;}
int main(int argc, char **argv)
{

    QApplication app(argc, argv);
    QPushButton pb1("Mostrar segundo boton y label"); //primer boton
    pb1.resize(400,200);
    QPushButton *p_pb1;
    p_pb1 = &pb1;
    pb1.show();

    QPushButton pb2("Ocultar label y mostrar boton final"); //segundo boton
    pb2.resize(400,200);
    QPushButton *p_pb2;
    p_pb2 = &pb2;
    QPushButton pb3("Cerrar App"); //segundo boton
    pb2.resize(400,200);
    QPushButton *p_pb3;
    p_pb3 = &pb3;
  //  pb2.show();




        QObject::connect( &pb1, SIGNAL( pressed() ), &pb2, SLOT( show() ) );
        QObject::connect( &pb1, SIGNAL( pressed() ), &pb1, SLOT( close() ) );

        QObject::connect( &pb2, SIGNAL( pressed() ), &pb3, SLOT( show() ) );

        QObject::connect( &pb2, SIGNAL( pressed() ), &pb2, SLOT( close() ) );
        QObject::connect( &pb3, SIGNAL( pressed() ), &app, SLOT( quit() ) );

    return app.exec();
}
