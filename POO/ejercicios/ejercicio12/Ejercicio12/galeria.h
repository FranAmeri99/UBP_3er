#ifndef GALERIA_H
#define GALERIA_H

#include <QWidget>

#include <QObject>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>

class Galeria : public QWidget {
    Q_OBJECT
public:
    Galeria(QWidget *parent = nullptr);
private:
    QPushButton * pbAdelante;
    QPushButton * pbAtras;
    QLabel * lImagen;
    QGridLayout * layout;

private slots:
    void cambiar();
};
#endif // GALERIA_H
