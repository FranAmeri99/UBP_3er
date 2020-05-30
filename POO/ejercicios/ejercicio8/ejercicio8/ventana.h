#ifndef VENTANA_H
#define VENTANA_H

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


class Ventana : public QWidget {
    Q_OBJECT


public:
    explicit Ventana (QWidget * parent = nullptr);


protected:


private:
    QNetworkAccessManager * manager;
    QLabel * paginaweb;
    QLineEdit * le_paginaweb;
    QPushButton * pb_pagina;
    QPushButton * pb_pagina2;
    QPushButton * pb_androidHTML;
    QPushButton * pb_archivo;
    QGridLayout * layout;
    QTextEdit * text_edit;
    QTextEdit * text_edit2;
    QPushButton * botonPresionado;
    QProgressBar * progressBar;

    QLabel * lAndroid;
    QLabel * lNavegador;
    QPushButton * pb_Buscar;


private slots:
    void slot_respuesta1(QNetworkReply * reply);
    void slot_respuesta2(QNetworkReply * reply);
    void slot_solicitar1();
    void slot_solicitar2();

    void slot_descargando( qint64 bytesRecibidos, qint64 bytesTotales );


signals:


};




#endif // VENTANA_H
