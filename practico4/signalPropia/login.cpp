#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    ui->leUsuario->setFocus();
    this->setWindowTitle("Login De Usuario");
    connect( ui->LIngresar , SIGNAL( signal_clic() ), this, SLOT( hide() ) );
}

Login::~Login()  {
    delete ui;
}

