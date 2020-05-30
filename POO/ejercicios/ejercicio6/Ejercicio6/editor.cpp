#include "editor.h"
#include <QDebug>
Editor::Editor(QWidget *parent) : QWidget(parent)
{

    layout = new QGridLayout;
    tEditor = new QTextEdit;
    pbBorrar = new QPushButton("Borrar");
    pbBuscar = new QPushButton("Buscar");
    lefrace = new QLineEdit;
    lResultado = new QLabel;
    lResultado->setText("se repite 0 veces la letra A");
    layout->addWidget(lResultado, 0, 0, 1, 2);
    layout->addWidget(pbBuscar, 0, 2, 1, 1);
    layout->addWidget(lefrace,  1, 0, 1, 2);
    layout->addWidget(pbBorrar, 1, 2, 1, 1);
    layout->addWidget(tEditor,  2, 0, 1, 3);

    this->setLayout( layout );
    connect( pbBuscar, SIGNAL( pressed() ), this, SLOT( slot_buscar() ) );
    connect( pbBorrar, SIGNAL( pressed() ), this, SLOT( slot_borrar() ) );
}

Editor::~Editor()
{
}

int Editor::Contar(QString letra)
{
    QString texto = tEditor->toPlainText();
    int contador = texto.count(letra);
    return contador;

}

void Editor::Borrar(QString frase)
{
    QString nuevo = tEditor->toPlainText();
    //nuevo.NormalizationForm_KD
    nuevo.replace(frase,"");
    tEditor->setText(nuevo);
}

void Editor::slot_buscar()
{
    int a = Contar(lefrace->text());
    QString resultado;
    resultado = "se repite " + QString::number(a) + " la letra A";
    lResultado->setText(resultado);
}

void Editor::slot_borrar()
{
    Borrar(lefrace->text());

}

