#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

    QSpinBox * spinBox ;
    QSlider * slider ;
    QHBoxLayout * layout;
public slots:
    void cambiarValor();
};
#endif // VENTANA_H
