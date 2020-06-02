#ifndef INICIO_H
#define INICIO_H

#include <QWidget>
#include "formulario.h"
#include "admindb.h"

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
class inicio : public QWidget {
    Q_OBJECT

public:
    explicit inicio (QWidget * parent = nullptr);
    int control = 0;

protected:

private:
    QNetworkAccessManager * manager;
    QLineEdit * le_paginaweb;
    QGridLayout * layout;
    QTextEdit * text_edit;
    QProgressBar * progressBar;
    QFile * ProvinciaCSV ;
    Formulario * formulario;
    AdminDB * db;

private slots:
    void slot_respuesta(QNetworkReply * reply);
    void slot_descargando( qint64 bytesRecibidos, qint64 bytesTotales );

};

#endif // INICIO_H
