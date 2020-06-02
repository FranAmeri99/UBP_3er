#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->leUsuario->setFocus();
    this->setWindowTitle("Login De Usuario");
    connect( ui->LIngresar , SIGNAL( signal_clic() ), this, SLOT( slot_ingresar() ) );
}

Login::~Login()  {
    delete ui;
}

void Login::slot_ingresar()
{
    bool noNumero=true;
    QString Usuario = ui->leUsuario->text();
    for(int i = 1; i < Usuario.size; i++)
    {
    if((Usuario[i] - 1) != Usuario[i - 1])
    {

        break
    }
    }

    return true;


    }
}

void Login::slot_registrar()
{

}

