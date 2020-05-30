#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

#include <QGridLayout>
#include <QLineEdit>

class Editor : public QWidget
{
    Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    ~Editor();
    int Contar(QString);
    void Borrar(QString);

private:
    QGridLayout * layout;
    QTextEdit * tEditor;
    QPushButton * pbBuscar;
    QPushButton * pbBorrar;
    QLabel * lResultado;
    QLineEdit * lefrace;
public slots:
    void slot_buscar();
    void slot_borrar();
};
#endif // EDITOR_H
