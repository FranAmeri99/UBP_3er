#include "login.h"

Login::Login( QWidget * parent ) : QWidget ( parent ){

    this->setWindowTitle( "Login" );

    lUser = new QLabel( "User" );
    lPassword = new QLabel( "Password" );

    leUser = new QLineEdit;
    leUser->setPlaceholderText( "Ingrese user" );
    lePassword = new QLineEdit;
    lePassword->setPlaceholderText( "Ingrese password" );
    lePassword->setEchoMode( QLineEdit::Password );

    pbEntrar = new QPushButton( "Entrar" );

    layout = new QGridLayout;

    this->setLayout(layout);

    //layout->addWidget(campo,fila,columna,filaspan, columnaspan, alineacion)
    layout->addWidget( lUser, 0, 1);
    layout->addWidget( lPassword ,1, 1);
    layout->addWidget( pbEntrar ,3, 1);

    layout->addWidget( leUser, 0, 2, 1, 1);
    layout->addWidget( lePassword ,1, 2, 1 ,1);


    adminDB = new AdminDB();
    adminDB->conectar( "../db/usuarios.sqlite" );
    adminDB->creats();
    adminDB->registrar( "Aplicación abierta" );
    adminDB->admin("admin","123456");
    formulario = new Formulario(adminDB);

    connect( pbEntrar, SIGNAL( pressed() ), this, SLOT( slot_entrar() ) );
}

void Login::slot_entrar(){
//connect(sender, SIGNAL(destroyed(QObject*)), this, SLOT(objectDestroyed()));
  /*  if(this->leUser->text() == "admin" && this->lePassword->text() == "1111"){
        qDebug() << "Contrasena exitosa ";

    }else{
        qDebug()<< "Usuario y/o Contrasena erroneas";
        this->leUser->clear();
         this->lePassword->clear();
    }
*/

    QVector< QStringList > vRegistros = adminDB->select( "select id, clave, apellido from usuarios" );

  //  qDebug() << vRegistros;


    QStringList nombre_apellido = adminDB->validarUsuario( leUser->text(), lePassword->text(), "usuarios" );

    if ( ! nombre_apellido.isEmpty() )  {
        qDebug() << nombre_apellido.first();
        qDebug() << nombre_apellido.last();

        qDebug() <<
        QMessageBox::information( this, "Usuario valido", "Hola " + nombre_apellido.first()
                                  + nombre_apellido.last() + ". Bienvenido!!!" );
        formulario->show();
        formulario->resize(368,208);
        this->hide();
    }
    else  {
        leUser->setText( "" );
        lePassword->clear();
        QMessageBox::warning( this, "Intente de nuevo", "No me ...." );
    }

}
