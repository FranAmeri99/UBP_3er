#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QTableWidget>
#include <QComboBox>
#include "admindb.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QCryptographicHash>
#include <QMessageBox>

class Formulario : public QWidget {
   Q_OBJECT

public:
   Formulario(AdminDB* OadminDB = nullptr, QWidget * parent = nullptr );

private:

   QGridLayout * layout;

   QLabel * lUsuario;
   QLabel * lClave;
   QLabel * lNombre;
   QLabel * lApellido;
   QLabel * lTipo;

   QLineEdit * leUsuario;
   QLineEdit * leClave;
   QLineEdit * leNombre;
   QLineEdit * leApellido;

   QPushButton * boton;

   AdminDB * adminDB;

   QComboBox * tipo;
   QTableWidget *teSelect;
   QLabel * lLegajo;

   QLineEdit * leLegajo;

   QPushButton * pbAlta;
   QPushButton * pbSalir;


   QGroupBox * captcha;
   QLabel * lCaptcha;
   QLineEdit * leCaptcha;
   QGridLayout * captchaLayout;

   void mostrar(QString);
   void buscar();
   void mostrar_todo();


private slots:
   void slot_Captcha();
   void slot_salir();
   void slot_tipo();

};

#endif // FORMULARIO_H
