#include <QApplication>
#include "login.h"

int main(int argc, char** argv){
    QApplication a(argc,argv);

    Login login;
    login.show();
    login.resize(368,208);

    return a.exec();
}
