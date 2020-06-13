#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QDir>


QT_BEGIN_NAMESPACE
namespace Ui { class Ventana; }
QT_END_NAMESPACE

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    Ventana(QWidget *parent = nullptr);
    ~Ventana();

private slots:
    void on_pushButton_clicked();

    void on_Rotar_clicked();

private:
    Ui::Ventana *ui;
    QString nombre;
    int rotacion = 0;
};
#endif // VENTANA_H
