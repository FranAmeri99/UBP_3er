#ifndef VENTANA_H
#define VENTANA_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QGroupBox>
#include <QLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidget>
class ventana : public QWidget
{
    Q_OBJECT
public:
    explicit ventana(QWidget *parent = nullptr);
    void CrearTablaUsuario();
    void InsertarUsuario();
    void MostrarDatos();
private:
    QGroupBox *box;
    QGridLayout *layout;
    QPushButton *pbSelect;
    QPushButton *pbSalir;
    QTableWidget *teSelect;
    QLayout * lSelect;

    QSqlDatabase db;
public slots:
    void slot_Insertar();



signals:

};

#endif // VENTANA_H
