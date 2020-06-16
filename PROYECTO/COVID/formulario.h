#ifndef FORMULARIO_H
#define FORMULARIO_H
#include <QWidget>
#include "admindb.h"
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QTextEdit>
#include <QLabel>
#include <QComboBox>
#include <QDateEdit>#
#include <QDateTime>
#include <QTableWidget>
#include "grafico.h"
#include "sir.h"
#include <QMessageBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
class Formulario : public QWidget
{
    Q_OBJECT
public:
    explicit Formulario(QWidget *parent = nullptr);
    void cargarCB(QComboBox * combo);
    void graficaProvinvia(QString provincia);
    void mostrar( QString provincia ,QString provincia2 , QString fecha);

private:

    QLineEdit * le_paginaweb;
    QGridLayout * layout;
    QPushButton * pbBuscar;
    QComboBox * cbprov;
    QDateEdit * defecha;
    QTableWidget * teSelect;
    AdminDB * db;
    Grafico * graficador;

    QCheckBox * cbinfectadosT;
    QCheckBox * cbinfectadosD;
    QCheckBox * cbMuertosT;
    QCheckBox * cbMuertosD;
//    Formulario * formulario;
    //sir * sir;
    QComboBox * cbprov2;

    QSpinBox * poblacion_s;
    QDoubleSpinBox * dias_s;
    QDoubleSpinBox * beta_s;
    QDoubleSpinBox * gama_s;
    QLabel * lDias;

    QPushButton * pbActualizar;

private slots:
    void slot_mostra();
    void slot_actualizare();
};
#endif // FORMULARIO_H
