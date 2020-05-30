#include "formulario.h"
#include "admindb.h"
#include <QDebug>

Formulario::Formulario(AdminDB* OadminDB, QWidget * parent ) : QWidget( parent ){

    this->setWindowTitle("Formulario");

    lUsuario = new QLabel( "Usuario" );
    lClave = new QLabel( "Clave" );
    lNombre = new QLabel( "Nombre" );
    lApellido = new QLabel( "Apellido" );
    leUsuario = new QLineEdit( "Usuario" );
    leClave = new QLineEdit( "Clave" ) ;
    leNombre = new QLineEdit( "Nombre" ) ;
    leApellido = new QLineEdit( "Apellido" ) ;
    lTipo = new QLabel( "Seleccione La Accion" );
    tipo = new QComboBox();

    tipo->addItem("Insertar");
    tipo->addItem("Mostrar");
    tipo->addItem("Buscar");
    tipo->addItem("Borrar");

    boton= new QPushButton();
    teSelect = new QTableWidget();

    lLegajo = new QLabel( "Legajo" );

    leLegajo = new QLineEdit;

    pbAlta = new QPushButton( "Alta" );
    pbSalir = new QPushButton( "Salir" );

    if (!OadminDB){
        adminDB = new AdminDB();
        adminDB->conectar("../db/usuarios.sqlite");
    }
    else {
        this->adminDB = OadminDB;
    }

    layout = new QGridLayout;
    layout->addWidget( lTipo,      0, 0, 1, 2 );
    layout->addWidget( tipo,       0, 2, 1, 2 );
    layout->addWidget( lNombre,    1, 0, 1, 1 );
    layout->addWidget( lApellido,  2, 0, 1, 1 );
    layout->addWidget( lUsuario,   3, 0, 1, 1 );
    layout->addWidget( lClave,     4, 0, 1, 1 );

    layout->addWidget( leNombre,   1, 1, 1, 3 );
    layout->addWidget( leApellido, 2, 1, 1, 3 );
    layout->addWidget( leUsuario,  3, 1, 1, 3 );
    layout->addWidget( leClave,    4, 1, 1, 3 );

    layout->addWidget( pbAlta,      5, 0, 1, 2 );
    layout->addWidget( pbSalir,     5, 2, 1, 2 );
    layout->addWidget( teSelect,    6, 0, 3, 4 );

    teSelect->setColumnCount(5);
/*
currentIndexChanged(int index)
void	currentTextChanged(const QString &text)
void	highlighted(int index)
void	textActivated(const QString &text)
void	textHighlighted(const QString &text)
  */
    this->setLayout( layout );
    //connect( tipo, SIGNAL( ) , this, SLOT(slot_tipo));
    connect( tipo, SIGNAL( textActivated(QString) ) , this, SLOT( slot_tipo() ) );
    connect( pbAlta, SIGNAL( pressed() ), this, SLOT( slot_Captcha() ) );
    connect( pbSalir, SIGNAL( pressed() ), this, SLOT( slot_salir() ) );


}

void Formulario::mostrar_todo()
{
    QString consulta = "SELECT * FROM usuarios ";
    mostrar(consulta);

}
void Formulario::buscar()
{
    QString consulta = "SELECT * FROM usuarios WHERE usuario = '" + leUsuario->text() + "'";
    mostrar(consulta);

}
void Formulario::mostrar(QString consulta)
{
//    QSqlQuery mostrar;
//    mostrar.exec(consulta);
    teSelect->clear();

    QVector<QStringList> cons = adminDB->select(consulta);

    for (int i=0;i<cons.size();i++){
        teSelect->insertRow(i);
        for (int j=0;j<5;j++){
            teSelect->setItem(i,j,new QTableWidgetItem(cons.at(i).at(j)));
        }
    }
teSelect->removeColumn(0);
    /*int fila =0;
    teSelect->setRowCount(0);
    while(mostrar.next()){ //muestro en la tabla lo que devuelve la consulta
        teSelect->insertRow(fila);
        teSelect->setItem(fila, 0,new QTableWidgetItem(mostrar.value(0).toByteArray().constData()));
        teSelect->setItem(fila, 1,new QTableWidgetItem(mostrar.value(1).toByteArray().constData()));
        teSelect->setItem(fila, 2,new QTableWidgetItem(mostrar.value(2).toByteArray().constData()));
        teSelect->setItem(fila, 3,new QTableWidgetItem(mostrar.value(3).toByteArray().constData()));
        teSelect->setItem(fila, 4,new QTableWidgetItem(mostrar.value(4).toByteArray().constData()));
        fila ++;
    }*/

}

void Formulario::slot_Captcha()  {
    QStringList headers2 = { "ID", "Usuario", "Clave", "Nombre","Apellido"};
    teSelect->setHorizontalHeaderLabels(headers2);
    QString usuario = leUsuario->text();
    QString clave = leClave->text() ;
    QString nombre = leNombre->text();
    QString apellido = leApellido->text();

    QString operacion = tipo->currentText();
    if(operacion=="Insertar"){
           adminDB->insertar( usuario , clave , nombre , apellido );
   mostrar_todo();
    }
    if(operacion=="Borrar"){
        leNombre->setDisabled(true);
        leApellido->setDisabled(true);
        adminDB->borrar( usuario , clave );
    mostrar_todo();
    }
    if(operacion=="Buscar"){
            leNombre->setDisabled(true);
            leApellido->setDisabled(true);
            leClave->setDisabled(true);
            pbAlta->setText("Buscar");
            buscar();
        }


}


void Formulario::slot_salir()  {
    qDebug() << ("Hasta luego");
    this->close();
}

void Formulario::slot_tipo()
{

    leNombre->setDisabled(false);
    leApellido->setDisabled(false);
    leClave->setDisabled(false);
    leUsuario->setDisabled(false);




    QString operacion = tipo->currentText();
    if(operacion=="Buscar"){
        leNombre->setDisabled(true);
        leApellido->setDisabled(true);
        leClave->setDisabled(true);
        pbAlta->setText("Buscar");
        qDebug()<<"Buscar";
    }
    if(operacion=="Borrar"){
        leNombre->setDisabled(true);
        leApellido->setDisabled(true);
        leClave->setDisabled(true);
        pbAlta->setText("Borrar");
        qDebug()<<"Borrar";
        mostrar_todo();
    }
    if(operacion == "Insertar"){

        pbAlta->setText("Insertar");
        leNombre->setDisabled(false);
        leApellido->setDisabled(false);
        leClave->setDisabled(false);
        leUsuario->setDisabled(false);
        qDebug()<<"Insertar";
        mostrar_todo();

    }
    if(operacion == "Mostrar"){
        pbAlta->setText("Mostrar");
        leNombre->setDisabled(true);
        leApellido->setDisabled(true);
        leClave->setDisabled(true);
        leUsuario->setDisabled(true);
        mostrar_todo();
    }
}


