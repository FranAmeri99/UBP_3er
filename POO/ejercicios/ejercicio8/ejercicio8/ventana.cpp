#include "ventana.h"
#include <QDebug>
#include <QImage>
#include<QByteArray>
Ventana :: Ventana ( QWidget * parent) : QWidget (parent),
                                        manager(new QNetworkAccessManager(this) )

           {

       this->setWindowTitle("Ejercicio Network");

       paginaweb = new QLabel( "Pagina web" );
       le_paginaweb = new QLineEdit( "https://www.ubp.edu.ar" );
       le_paginaweb->setPlaceholderText("Ingrese pagina web");

       pb_pagina = new QPushButton( "HTML" );
       pb_pagina2 = new QPushButton( "Plano" );
       pb_androidHTML = new QPushButton( "Ser un Android" );
       pb_archivo = new QPushButton( "Descargar archivo" );
       text_edit = new QTextEdit;
       text_edit2 = new QTextEdit;

       lAndroid = new QLabel;//( "Android" );
       lAndroid->setText("Android");
       lNavegador = new QLabel( "Navegador PC" );
       pb_Buscar = new QPushButton( "Buscar" );


       layout = new QGridLayout;

       layout->addWidget( paginaweb, 0,0,1,2);
       layout->addWidget( le_paginaweb, 1,0,1,2);
       layout->addWidget( pb_Buscar, 1,2,1,2);
  //     layout->addWidget( pb_androidHTML, 2,0,1,1);
//       layout->addWidget( pb_archivo, 3,0,1,1);

      // layout->addWidget(pb_pagina, 4,3,1,1);
       //layout->addWidget(pb_pagina2, 5,3,1,1);

       layout->addWidget(lAndroid, 3,0,2,2);
       layout->addWidget(lNavegador, 3,2,2,2);
       layout->addWidget(text_edit,6,0,2,2);
       layout->addWidget(text_edit2,6,2,2,2);

       progressBar = new QProgressBar( this );

       layout->addWidget( progressBar, 10, 0, 1, 4 );


       this->setLayout(layout);


       connect(manager,SIGNAL(finished(QNetworkReply * )),this,SLOT (slot_respuesta1(QNetworkReply *)));
       connect(manager,SIGNAL(finished(QNetworkReply * )),this,SLOT (slot_respuesta2(QNetworkReply *)));

       connect(pb_Buscar,SIGNAL(pressed()),this,SLOT(slot_solicitar1()));
}
void Ventana::slot_respuesta1( QNetworkReply * reply )  {
    QByteArray ba = reply->readAll();

    qDebug() << "Size de la respuesta " << ba.size();

    text_edit->setHtml( ba );
    QList< QByteArray > listadoCabecerasHTTP = reply->rawHeaderList();
    for( int i = 0 ; i < listadoCabecerasHTTP.size() ; i++ )  {

        QString linea = listadoCabecerasHTTP.at( i );
        linea += " = ";
        linea.append( reply->rawHeader( listadoCabecerasHTTP.at( i ) ) );

        text_edit->append( linea );
    }

}
void Ventana::slot_respuesta2( QNetworkReply * reply )  {
    QByteArray ba = reply->readAll();

    qDebug() << "Size de la respuesta " << ba.size();

    text_edit2->setHtml( ba );
    QList< QByteArray > listadoCabecerasHTTP = reply->rawHeaderList();
    for( int i = 0 ; i < listadoCabecerasHTTP.size() ; i++ )  {

        QString linea = listadoCabecerasHTTP.at( i );
        linea += " = ";
        linea.append( reply->rawHeader( listadoCabecerasHTTP.at( i ) ) );

        text_edit2->append( linea );
    }

}

void Ventana::slot_solicitar1(){
    text_edit->clear();

    botonPresionado = ( QPushButton * ) this->sender();

        qDebug () << "Html";
        manager->get(QNetworkRequest(QUrl(le_paginaweb->text())));


        QNetworkReply * replyDescargando =manager->get( QNetworkRequest( QUrl( le_paginaweb->text() ) ) );

        connect( replyDescargando, SIGNAL( downloadProgress( qint64, qint64 ) ),
                 this, SLOT( slot_descargando( qint64, qint64 ) ) );



}

void Ventana::slot_solicitar2()
{
    qDebug () << "Android";

    QString valorUA = "Mozilla/5.0 (Linux; Android 4.0.4; Galaxy Nexus Build/IMM76B) ";
    valorUA.append(   "AppleWebKit/535.19 (KHTML, like Gecko) Chrome/18.0.1025.133 " );
    valorUA.append(   "Mobile Safari/535.19" );

    qDebug() << valorUA;

    QNetworkRequest request( QUrl( le_paginaweb->text() ) );
    request.setRawHeader( "User-Agent", valorUA.toUtf8() );

    manager->get( request );

}

void Ventana::slot_descargando( qint64 bytesRecibidos, qint64 bytesTotales )  {
    progressBar->setRange( 0, 100 );
    progressBar->setValue( 100 * int( bytesRecibidos ) / int( bytesTotales ) );

}





