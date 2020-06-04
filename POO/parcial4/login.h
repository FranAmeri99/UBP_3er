#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include "lineadeclave.h"
#include "label.h"
#include <QMessageBox>

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QLineEdit* leUser;
    LineaDeClave* ldcPass;
    Label* lbIngresar;
    Label* lbRegistrarse;

private slots:
    void irALogin();
    void irARegistrarse();

signals:
    void loginPressed(const QString &text);
    void registrarsePressed();

};

#endif // LOGIN_H
