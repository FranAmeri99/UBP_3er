#include "login.h"

Login::Login( QWidget * parent ) : QWidget ( parent ){

    this->setWindowTitle( "Login" );

    lUser = new QLabel( "User" );
    lPassword = new QLabel( "Password" );

    leUser = new QLineEdit;
    leUser->setPlaceholderText( "Ingrese user" );
    lePassword = new QLineEdit;
    lePassword->setPlaceholderText( "Ingrese password" );
    lePassword->setEchoMode( QLineEdit::Password );

    pbEntrar = new QPushButton( "Entrar" );

    layout = new QGridLayout;

    this->setLayout(layout);

    //layout->addWidget(campo,fila,columna,filaspan, columnaspan, alineacion)
    layout->addWidget( lUser, 0, 1);
    layout->addWidget( lPassword ,1, 1);
    layout->addWidget( pbEntrar ,3, 1);

    layout->addWidget( leUser, 0, 2, 1, 1);
    layout->addWidget( lePassword ,1, 2, 1 ,1);

    formulario = new Formulario;

    connect( pbEntrar, SIGNAL( pressed() ), this, SLOT( slot_entrar() ) );
}

void Login::slot_entrar(){
//connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
    if(this->leUser->text() == "admin" && this->lePassword->text() == "1111"){
        qDebug() << "Contrasena exitosa ";
        formulario->show();
        formulario->resize(368,208);
        this->hide();
    }else{
        qDebug()<< "Usuario y/o Contrasena erroneas";
        this->leUser->clear();
         this->lePassword->clear();
    }
}
