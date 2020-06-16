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
const double b = 0.10888;
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
    qw++;
   /* SuceptiblesSIR->append(t, x[0]);
    InfectadosSIR->append(t, x[1]);
    RecuperadosSIR->append(t, x[2]);*/
    qDebug()<<"Dia: [" << t << "] Suceptibles: (" << x[0] << ") Infectados: (" << x[1] <<") Recuperados: ("<< x[2] <<") DIA: "<<qw<<endl;
    QString dia = QString::number(t);
    QString sucep = QString::number(x[0]);
    QString infe = QString::number(x[1]);
    QString recu = QString::number(x[2]);

    QSqlQuery insertar;
    QByteArray queryI = "INSERT INTO sir (fecha, susecptible, "
                        "infectados, recuperados) VALUES ('";
    queryI.append(dia + "','" + sucep + "','" + infe +"','" + recu +"') ");
    insertar.exec(queryI);
    //qDebug()<<insertar.lastError();

}


sir::sir(AdminDB* OadminDB)
{

    qDebug()<<"hola";
    AdminDB::creatsSir();

}

void sir::cargar()
{
    int p = *poblacion;
    double totalI = (100/99);
    qDebug()<<" Poblacion Sir " << totalI;
    //float totlaF = 1-totalI;
    //qDebug()<<"total "<<totalI;

    state_type x = { 0.999993587 , 0.000006413 , 0.0 }; // initial conditions
    qDebug()<<"dias cargados:::"<<*dias;

    integrate( sirr , x , 0.0 , *dias , 1.0 , write_sir );
}
