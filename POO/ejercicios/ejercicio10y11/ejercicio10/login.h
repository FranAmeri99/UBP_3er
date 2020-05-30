#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QMessageBox>
#include "formulario.h"
#include "admindb.h"
class Login : public QWidget {
        Q_OBJECT
public:
    Login( QWidget * parent = nullptr);

private:
    QLabel * lUser;
    QLabel * lPassword;

    QLineEdit * leUser;
    QLineEdit * lePassword;

    QPushButton * pbEntrar;

    QGridLayout * layout;
    AdminDB * adminDB;

    Formulario * formulario;

private slots:
    void slot_entrar();

};

#endif // LOGIN_H
