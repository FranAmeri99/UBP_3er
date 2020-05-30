#include "ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{

    spinBox = new QSpinBox;
    slider = new QSlider( Qt::Horizontal );
    layout = new QHBoxLayout();

    spinBox->setRange( 0, 100 );
    slider->setRange( 0, 100 );

    QObject::connect( spinBox, SIGNAL( valueChanged( int ) ), slider, SLOT( setValue( int ) ) );
    QObject::connect( slider, SIGNAL( valueChanged( int ) ),  spinBox, SLOT( setValue( int ) ) );
    connect(slider, SIGNAL( valueChanged( int ) ),  this, SLOT( cambiarValor() ));

    spinBox->setValue( 15 );

    layout->addWidget( spinBox );
    layout->addWidget( slider );
    this->setLayout( layout );
    this->setVisible( true );

}

Ventana::~Ventana()
{
}

void Ventana::cambiarValor()
{
    int i = slider->value();
    QString valor;
    valor.setNum(i);
    this->setWindowTitle(valor);

}

