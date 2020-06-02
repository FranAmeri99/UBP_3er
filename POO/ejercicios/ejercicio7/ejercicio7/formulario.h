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
    QLabel * lImagen;

    QGridLayout * layout;


};


#endif // FORMULARIO_H
