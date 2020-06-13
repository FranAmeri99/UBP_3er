#include "ventana.h"
#include "ui_ventana.h"
Ventana::Ventana(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);
}

Ventana::~Ventana()
{
    delete ui;
}


void Ventana::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName( this, "Abrir", "./", "Imagen (*.png *.jpg)" );

    QMessageBox::information(this,"Archivo Sellecionado",file_name);
    qDebug()<<"ruta del archivo: "<<file_name;
    if(file_name!=NULL){

        this->nombre = file_name;
        ui->Limagen->setPixmap(QPixmap(file_name));

    }
    else{
        qDebug()<<"es nulo";
        qDebug()<<"Ruta anterior::"<<nombre;

    }
    //setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
ui->Limagen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

}

void Ventana::on_Rotar_clicked()
{
    rotacion = rotacion + 90;
    QTransform trans;
    trans.rotate(rotacion);
    qDebug()<<"rotar: "<<nombre;
    ui->Limagen->setPixmap(QPixmap(nombre).transformed(trans));
    ui->Limagen->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

}
