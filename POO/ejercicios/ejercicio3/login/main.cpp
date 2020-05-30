#include <QApplication>
#include "login.h"
int main( int argc, char ** argv){

    QApplication a(argc, argv);

    Login login; //Creamos el login

    login.show();//se muestra login

    return a.exec();


}
