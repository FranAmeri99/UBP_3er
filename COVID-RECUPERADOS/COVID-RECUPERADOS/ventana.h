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
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QFile>


class Ventana : public QWidget
{
    Q_OBJECT
public:
    explicit Ventana(QWidget *parent = nullptr);

    void BorraTable();
    void CrearTablaPais();
    void InsertarPais();
    void cargar_cb();
    void MostrarDatos();
    void Describe();


private:
    QGridLayout *layout;
    QPushButton *pbSelect;

    QPushButton *pbBorrar;
    QPushButton *pbCrear;
    QPushButton *pbInsertar;
    QPushButton *pbCargar;


    QPushButton *pbSalir;
    QTableWidget *teSelect;
    QLayout * lSelect;
    QComboBox * cb_pais;
    QDateEdit * de_dia;

    QSqlDatabase db;

    QFile * archivo;
    QNetworkAccessManager *manager;
    QPushButton *botonPresionado;
    QByteArray *line;
//BORRAR
    QFile * archivo2;
public slots:
    void slot_Borrar();
    void slot_Crear();
    void slot_CargarCB();
    void slot_Mostrar();
    void slot_Insertar();
    void slot_respuesta(QNetworkReply *);
    void process_line();
    void process_line(QByteArray * line);

signals:

};

#endif // VENTANA_H
