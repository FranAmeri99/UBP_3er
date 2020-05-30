#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario( QWidget * parent = nullptr );
private:
    QLabel * lNombre;
    QLabel * lApellido;
    QLabel * lLegajo;

    QLineEdit * leNombre;
    QLineEdit * leApellido;
    QLineEdit * leLegajo;

    QPushButton * pbAlta;
    QPushButton * pbSalir;

    QGridLayout * layout;

    QGroupBox * captcha;
    QLabel * lCaptcha;
    QLineEdit * leCaptcha;
    QGridLayout * captchaLayout;


private slots:
    void slot_Captcha();
    void slot_salir();

};

#endif // FORMULARIO_H
