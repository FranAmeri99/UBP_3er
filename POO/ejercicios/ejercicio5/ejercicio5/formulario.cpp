#include "formulario.h"
#include <QDebug>

Formulario::Formulario( QWidget * parent ) : QWidget( parent ){

    this->setWindowTitle("Formulario");

    lNombre = new QLabel( "Nombre" );
    lApellido = new QLabel( "Apellido" );
    lLegajo = new QLabel( "Legajo" );

    leNombre = new QLineEdit;
    leNombre->setPlaceholderText("Ingrese nombre");
    leApellido = new QLineEdit;
    leApellido->setPlaceholderText("Ingrese apellido");
    leLegajo = new QLineEdit;
    leLegajo->setPlaceholderText("Ingrese legajo");


    pbAlta = new QPushButton( "Alta" );
    pbSalir = new QPushButton( "Salir" );

    layout = new QGridLayout;

    layout->addWidget( lNombre,     0, 0, 1, 1 );
    layout->addWidget( lApellido,   1, 0, 1, 1 );
    layout->addWidget( lLegajo,     2, 0, 1, 1 );

    layout->addWidget( leNombre,    0, 1, 1, 3 );
    layout->addWidget( leApellido,  1, 1, 1, 3 );
    layout->addWidget( leLegajo,    2, 1, 1, 1 );

    layout->addWidget( pbAlta,      4, 2, 1, 1 );
    layout->addWidget( pbSalir,     4, 3, 1, 1 );

    captcha = new QGroupBox("Captcha");
    lCaptcha = new QLabel("<p align=center>3599</p>");
    leCaptcha = new QLineEdit;
    captchaLayout = new QGridLayout;

    captchaLayout->addWidget(lCaptcha,4,0);
    captchaLayout->addWidget(leCaptcha,1,0);

    layout->addWidget(captcha,3,0);

    captcha->setLayout(captchaLayout);
    this->setLayout( layout );

    connect( pbAlta, SIGNAL( pressed() ), this, SLOT( slot_Captcha() ) );
    connect( pbSalir, SIGNAL( pressed() ), this, SLOT( slot_salir() ) );

}

void Formulario::slot_Captcha()  {
    if(leCaptcha->text() == "3599"){
        qDebug() << "Se dio de alta: " << leNombre->text() << leApellido->text() << leLegajo->text();
        this->close();
    }else{
         qDebug() << "Captcha erroneo, ingrese nuevamente. ";
         this->leCaptcha->clear();
    }
}


void Formulario::slot_salir()  {
    qDebug() << ("Hasta luego");
    this->close();
}


