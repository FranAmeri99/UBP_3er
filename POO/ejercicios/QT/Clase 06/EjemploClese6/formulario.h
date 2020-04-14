#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QGridLayout>

class Formulario : public QWidget  {
    Q_OBJECT

public:
    /**
     * @brief Formulario Crea un formulario
     * @param parent
     */
    Formulario( QWidget * parent = nullptr );

private:
    QLabel * lNombre;
    QLabel * lApellido;
    QLabel * lLegajo;

    /**
     * @brief leNombre Pide el nombre de la persona para dar de alta
     */
    QLineEdit * leNombre;
    QLineEdit * leApellido;
    QLineEdit * leLegajo;

    QPushButton * pbAlta;
    QPushButton * pbSalir;

    QGridLayout * layout;

// Modificadores de acceso
// En C++: public - private - protected
// Qt agrega ademas: private slots - public slots - signals

private slots:
    void slot_alta();
    void slot_salir();

};

#endif // FORMULARIO_H
