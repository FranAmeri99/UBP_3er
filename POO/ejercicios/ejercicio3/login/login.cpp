#include "login.h"

Login::Login(QWidget * parent) : QWidget(parent){
    layout = new QGridLayout(); //nos permite definir la disposicion de los demas elementos
    lUsuario = new QLabel("Usuario");
    lClave = new QLabel("Clave");

    leUsuario = new QLineEdit("admin");
    leClave = new QLineEdit("1234");
    leClave->setEchoMode(QLineEdit::Password);
    pb = new QPushButton("Ingresar");

    //     0            1      2
    //--------------------------------------
    //---Usuario-----              ---------0
    //---Clave-------              ---------1
    //---------------validar----------------2
    //--------------------------------------3

    layout->addWidget(lUsuario, 1,0, 1, 1);
    layout->addWidget(lClave, 2,0, 1, 1);
    layout->addWidget(leUsuario, 1,1, 1, 2);
    layout->addWidget(leClave, 2,1, 1, 2);
    layout->addWidget(pb, 3,1,1, 2);

    this->setLayout( layout);
    connect(pb, SIGNAL(pressed()), this, SLOT(slot_validar()));
    connect(leClave, SIGNAL(returnPressed()), this, SLOT(slot_validar()));
}

//USUARIO valido es admin 1234
void Login::slot_validar(){
    if(leUsuario->text() == "admin" &&
            leClave->text() == "1234"){
            this->close();
    }

    else{
        leUsuario->setText("Usuario o Clave Incorrecto");

    }
}
