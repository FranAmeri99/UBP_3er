#include "ventana.h"
#include <QDebug>
#include <QImage>
#include <QByteArray>
#include <QFile>

Ventana :: Ventana ( QWidget * parent) : QWidget (parent),
                                        manager(new QNetworkAccessManager(this) )
           {
    qDebug()<<"entro";


       this->setWindowTitle("COVID-19");

       le_paginaweb = new QLineEdit( "https://raw.githubusercontent.com/lucia15/Datos-Covid19"
                                     "-Argentina/master/Argentina-covid19-por-provincia.csv" );
     //  le_paginaweb->setPlaceholderText("Ingrese pagina web");

       layout = new QGridLayout;
       text_edit = new QTextEdit;
       progressBar = new QProgressBar( this );
       ProvinciaCSV = new QFile;
       layout->addWidget( le_paginaweb, 1,0,1,1);
       layout->addWidget(text_edit,6,0,4,4);
       layout->addWidget( progressBar, 10, 0, 1, 4 );
       graficoo = new Formulario;

       graficoo->show();
       graficoo->resize(368,208);
       this->setLayout(layout);

       qDebug()<<"entro";
       connect(manager,SIGNAL(finished(QNetworkReply * )),this,SLOT (slot_respuesta(QNetworkReply *)));
       qDebug()<<"entro";

       text_edit->clear();
       progressBar->reset();

       manager->get(QNetworkRequest(QUrl(le_paginaweb->text())));

       QNetworkReply * replyDescargando =manager->get( QNetworkRequest( QUrl( le_paginaweb->text() ) ) );

       connect( replyDescargando, SIGNAL( downloadProgress( qint64, qint64 ) ),
                this, SLOT( slot_descargando( qint64, qint64 ) ) );
        ProvinciaCSV->setFileName("../db/ProvinciaCSV.csv");
        ProvinciaCSV->open(QIODevice::WriteOnly|QIODevice::Text);
        if (!ProvinciaCSV->isOpen()){
            qDebug()<<"No se pudo abrir";
        }
        qDebug()<<"entro";

}
void Ventana::slot_respuesta( QNetworkReply * reply )  {
    if (control == 0) {
        QByteArray ba = reply->readAll();
        text_edit->append( ba );
        qDebug()<<"entro";
        ProvinciaCSV->write(ba);
    }
    qDebug()<<control;

    control ++;
}


void Ventana::slot_descargando( qint64 bytesRecibidos, qint64 bytesTotales )  {
    progressBar->setRange( 0, 100 );

    progressBar->setValue( 100 * int( bytesRecibidos ) / int( bytesTotales ) );

}





