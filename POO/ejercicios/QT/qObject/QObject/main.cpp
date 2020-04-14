#include <QCoreApplication>
#include<QDebug>


class Persona : public QObject{

public:
    Persona(QObject * padre = NULL)
        :QObject(padre)
    {


    }

    void setNombre(const QString &nombre) {

        this->nombre = nombre;
    }

    void setEdad(int edad) {

        this->edad = edad;
    }


    void setSalario(double salario) {

        this->salario = salario;
    }

    QString getNombre()const {

        return nombre;
    }

    int getEdad() const{

        return edad;
    }


    double getSalario() const{

        return salario;
    }

    ~Persona(){
        qDebug()<<nombre<<"se elimino";
    }

private:
    QString nombre;
    int edad;
    double salario;

};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Persona * Juan = new Persona;
    Persona * Pedro = new Persona(Juan);

    Persona * Luis = new Persona(Juan);

    Juan->setNombre("Juan");
    Juan->setEdad(60);
    Juan->setSalario(100000);
    Pedro->setNombre("Pedro");
    Pedro->setEdad(40);
    Pedro->setSalario(50000);
    Luis->setNombre("Luis");
    Luis->setEdad(35);
    Luis->setSalario(40000);
    qDebug<<Luis->getNombre();
    return a.exec();
}


