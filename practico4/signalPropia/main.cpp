#include "login.h"
#include "label.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Login login;

    login.show();

    //QObject::connect( &label, SIGNAL( signal_clic() ), &w, SLOT( showMaximized() ) );




    return a.exec();
}
