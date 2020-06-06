#include "sir.h"
#include <QApplication>
#include <QDebug>
#include <QValueAxis>
#include "formulario.h"
#include <QLegend>
#include <QVXYModelMapper>

#include <boost/array.hpp>

#include <boost/numeric/odeint.hpp>

using namespace std;
using namespace boost::numeric::odeint;
const double b = 0.1;
const double g = 0.06;
int qw = 0;
typedef boost::array< double , 3 > state_type;

void sirr( const state_type &x , state_type &dxdt , double t )
{

    dxdt[0] = -b * x[0] * x[1]; //suceptibles
    dxdt[1] = b * x[0] * x[1] - g * x[1]; // infectados
    dxdt[2] = g * x[1]; //recuperados



}

void write_sir(const state_type &x , const double t )
{
    /*qw++;
    SuceptiblesSIR->append(t, x[0]);
    InfectadosSIR->append(t, x[1]);
    RecuperadosSIR->append(t, x[2]);*/
    cout << t << "Suceptibles: (" << x[0] << ") Infectados: (" << x[1] <<") Recuperados: ("<< x[2] <<") DIA: "<<qw<<endl;
    QString dia = QString::number(t);
    QString sucep = QString::number(x[0]);
    QString infe = QString::number(x[1]);
    QString recu = QString::number(x[2]);

    QSqlQuery insertar;
    QByteArray queryI = "INSERT INTO sir (fecha, susecptible, "
                        "infectados, recuperados) VALUES ('";
    queryI.append(dia + "','" + sucep + "','" + infe +"','" + recu +"') ");
    insertar.exec(queryI);
    qDebug()<<insertar.lastError();

}

void insertarSIR(const state_type &x , const double t ){

    /*qw++;
    SuceptiblesSIR->append(t, x[0]);
    InfectadosSIR->append(t, x[1]);
    RecuperadosSIR->append(t, x[2]);*/
    cout << t << "Suceptibles: (" << x[0] << ") Infectados: (" << x[1] <<") Recuperados: ("<< x[2] <<") DIA: "<<qw<<endl;
    QString dia = QString::number(t);
    QString sucep = QString::number(x[0]);
    QString infe = QString::number(x[1]);
    QString recu = QString::number(x[2]);

    QSqlQuery insertar;
    QByteArray queryI = "INSERT INTO sir (fecha, susecptible, "
                        "infectados, recuperados) VALUES ('";
    queryI.append(dia + "','" + sucep + "','" + infe +"','" + recu +"') ");
    insertar.exec(queryI);
    qDebug()<<insertar.lastError();

}


sir::sir(AdminDB* OadminDB)
{
    qDebug()<<"hola";
    state_type x = { 0.999999 , 0.00001 , 0.0 }; // initial conditions

    integrate( sirr , x , 0.0 , 100.0 , 0.1 , write_sir );

}
/*
void Grafico::sir(const Grafico::state_type &x, Grafico::state_type &dxdt, double t)
{
    dxdt[0] = -b * x[0] * x[1]; //suceptibles
    dxdt[1] = b * x[0] * x[1] - g * x[1]; // infectados
    dxdt[2] = g * x[1]; //recuperados

}

void Grafico::write_sir(const Grafico::state_type &x, const double t)
{
    qw++;
    SuceptiblesSIR->append(t, x[0]);
    InfectadosSIR->append(t, x[1]);
    RecuperadosSIR->append(t, x[2]);
    cout << t << "Suceptibles: (" << x[0] << ") Infectados: (" << x[1] <<") Recuperados: ("<< x[2] <<") DIA: "<<qw<<endl;
}
*/
