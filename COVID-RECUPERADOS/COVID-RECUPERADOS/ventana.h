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
#include <QComboBox>
#include <QDateEdit>

class ventana : public QWidget
{
    Q_OBJECT
public:
    explicit ventana(QWidget *parent = nullptr);
    void CrearTablaUsuario();
    void InsertarUsuario();
    void MostrarDatos();
    void Describe();
    void cargar_cb();
private:
    QGroupBox *box;
    QGridLayout *layout;
    QPushButton *pbSelect;
    QPushButton *pbSalir;
    QTableWidget *teSelect;
    QLayout * lSelect;
    QComboBox * cb_pais;
    QComboBox * cb_estado;
    QDateEdit * de_dia;

    QSqlDatabase db;
public slots:
    void slot_Insertar();
    void slot_Click_Pais();




signals:

};

#endif // VENTANA_H
