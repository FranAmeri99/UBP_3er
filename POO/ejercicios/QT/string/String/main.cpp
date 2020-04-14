#include <QCoreApplication>
#include <QDebug>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int x = 6;
    double y = 3.1416;
    char z = '#';
    QString todo ;

    todo = QString("%1,%2,%3").arg(x).arg(y).arg(z); //concatenar varios tipos de datos
    qDebug()<< todo;
//----------------------------------------------------------------------------------------------------------------
    string s = "en c++";
    QString qs = s.c_str(); //para pasar del string de c++ a QString
    qDebug() << qs;
//----------------------------------------------------------------------------------------------------------------

    QString q = "en QT";
    string sq = q.toStdString();
    qDebug()<<sq.c_str();//combirte para q lo muestre. no muestra las comillas (' ') xq no son caracteres originales de qt
//----------------------------------------------------------------------------------------------------------------

    bool verdarero = q.contains("en"); //devuelve si contiene esa palabra
    qDebug()<<verdarero;

//----------------------------------------------------------------------------------------------------------------
    QString texto = "esto es un texto que contiene muchos caracteres 23456789!@#$%^&*()_";
    int posicion = texto.indexOf('e');//devuelve la posicion del primer caracter que encuntre
    qDebug()<<posicion;

//----------------------------------------------------------------------------------------------------------------

    int posicion2 = texto.indexOf('z');//devuelve la posicion -1 si no encuentra el caracter
    qDebug()<<posicion2;

    //----------------------------------------------------------------------------------------------------------------

        QChar posicion3 = texto.at(2);//devuelve el caracter en esa posicion
        qDebug()<<posicion3;

        //----------------------------------------------------------------------------------------------------------------

            texto.insert(2,"chupame un huevo");//devuelve el caracter en esa posicion")";
            qDebug()<<texto;
    return a.exec();
}
