#include "login.h"
#include "ventana.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowTitle("Login De Usuario");
    connect( ui->LIngresar , SIGNAL( signal_clic() ), this, SLOT( slot_ingresar() ) );
}

Login::~Login()  {
    delete ui;
}

void Login::slot_ingresar()
{
    bool noNumero=true;
    QStringList listaNumeros = {"0","1","2","3","4","5","6","7","8","9"};
    QString Usuario = ui->leUsuario->text();
/*    for(int i = 1; i < Usuario.size(); i++)
    {
    if((Usuario[i]-1) != Usuario[i - 1])
        {
        noNumero = false;
        break ;
        }
    }*/
    Ventana ventana;
    ventana.show();
    this->hide();
    }
//}

void Login::slot_registrar()
{

}

