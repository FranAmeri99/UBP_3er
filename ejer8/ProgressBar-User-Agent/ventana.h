#ifndef VENTANA_H
#define VENTANA_H
#include <admindb.h>
#include <QWidget>
#include <QLineEdit>
#include <QLayout>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QFile>
#include "grafico.h"
#include "formulario.h"


class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana (QWidget * parent = nullptr);
    int control = 0;

protected:

private:
    QNetworkAccessManager * manager;
    QLineEdit * le_paginaweb;
    QGridLayout * layout;
    QTextEdit * text_edit;
    QProgressBar * progressBar;
    QFile * ProvinciaCSV ;
   // grafico  * graficoo;
    Formulario * graficoo;

private slots:
    void slot_respuesta(QNetworkReply * reply);
    void slot_descargando( qint64 bytesRecibidos, qint64 bytesTotales );

};

#endif // VENTANA_H
