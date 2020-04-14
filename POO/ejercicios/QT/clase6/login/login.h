#ifndef LOGIN_H

#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include<QGridLayout>

class Login : public QWidget{ //Creamos la clase login que era las caractiristicas de qwidget
Q_OBJECT //tenemos que convir nuestra clase login en una de qt

public:
    Login(QWidget * parent = nullptr); //constructor

private:
    QLabel * lUsuario;    //Etiqueta usuario
    QLabel * lClave;    //Etiqueta clave

    QLineEdit * leUsuario; //ingresa el nombre
    QLineEdit * leClave;   //ingresa la clave

    QPushButton * pb;

    QGridLayout * layout; //funciona como una grilla

private slots:
    void slot_validar();

};

#endif // LOGIN_H
