#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    QGridLayout * layout;
    QPushButton * pbActualizar;
    QLineEdit * leVelocidad;
    QLineEdit * leDiametro;
};
#endif // VENTANA_H
