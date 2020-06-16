#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);
    connect(ui->lblMouse,SIGNAL(Mouse_Pos()),this, SLOT(Mouse_current_pos()));
    connect(ui->lblMouse,SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed()));
    connect(ui->lblMouse,SIGNAL(Mouse_Left()),this, SLOT(Mouse_left()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::Mouse_current_Pos()
{
    ui->lblMouse_Current_Pos->setText(QString("X= %1 , Y= %2 ").
                                      arg(ui->lblMouse->x).
                                      arg(ui->lblMouse->y));
    ui->lblMouse_Current_Event->setText("Mouse en movimiento!");
}

void Ventana::Mouse_Pressed()
{
    ui->lblMouse_Current_Event->setText("Mouse Precionado!");

}

void Ventana::Mouse_left()
{
    ui->lblMouse_Current_Event->setText("Mouse en Left!");

}

