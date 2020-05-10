#ifndef INSERTAR_H
#define INSERTAR_H
#include "ventana.h"
#include<QTextStream>
void ventana::InsertarPais()
{
    qDebug()<<"\n Insertar";

    QDate inicio(2020,1,22);
    QDate actual2;
    QDate actual = actual2.currentDate();
//    int a = inicio.daysTo(actual);
    QByteArray consulta;
    consulta.append("INSERT INTO RECUPERADOS(Province , Country, Lat, Lon");
    int mes = actual.month();

    for (int i=1; i<=mes ;i++) {
        QDate principo(2020,i,1);

        for (int j=1;j<=principo.daysInMonth();j++) {
            if (i==1 and j<22) {
                continue;
            }
            if(i==mes and j==(actual.day()+1)){
                break;
            }
               QString fecha;
               int anio = 20;
               char d = 'd';
               char m = 'm';
               char y = 'y';
               QString coma = ",";
               fecha = QString("%1 %2%3%4%5%6%7").arg(coma).arg(d).arg(j).arg(m).arg(i).arg(y).arg(anio);
               consulta.append(fecha);
        }
    }
    QFile query2;
    query2.setFileName("../db/insert.txt");
    query2.open(QIODevice::WriteOnly|QIODevice::Text);

    while (!archivo->atEnd()) {
    QByteArray line = archivo->readLine();
    if(!line.startsWith("Province")){
        QString std = QString(line);
        QString std2 = std.mid(1,(std.size()-2));
        int agregar = std2.count(',')+1;
        int arreglo[agregar];
        int j = 0;
        for (int i = 0; i<std2.size();i++) {
            if(std2[i]==','){
                arreglo[j]=i;
                j++;
            }
        }
        for (int i = agregar-2;i>=0;i--) {

            std2.insert(arreglo[i]+1,"'");
            std2.insert(arreglo[i],"'");
        }
        std2.insert(std2.size(),"'");



        QByteArray consulta2=" ";
        consulta2 = consulta;
        consulta2.append(" ) VALUES('");
        consulta2.append(std2);
        consulta2.append(")");
        query2.write(consulta2);
       // qDebug()<<consulta2;

//


        }

    }
    QString algo = "INSERT INTO RECUPERADOS(Country, Lat, Lon, d22m1y20, d23m1y20, d24m1y20, d25m1y20, d26m1y20, d27m1y20, d28m1y20, d29m1y20, d30m1y20, d31m1y20, d1m2y20, d2m2y20, d3m2y20, d4m2y20, d5m2y20, d6m2y20, d7m2y20, d8m2y20, d9m2y20, d10m2y20, d11m2y20, d12m2y20, d13m2y20, d14m2y20, d15m2y20, d16m2y20, d17m2y20, d18m2y20, d19m2y20, d20m2y20, d21m2y20, d22m2y20, d23m2y20, d24m2y20, d25m2y20, d26m2y20, d27m2y20, d28m2y20, d29m2y20, d1m3y20, d2m3y20, d3m3y20, d4m3y20, d5m3y20, d6m3y20, d7m3y20, d8m3y20, d9m3y20, d10m3y20, d11m3y20, d12m3y20, d13m3y20, d14m3y20, d15m3y20, d16m3y20, d17m3y20, d18m3y20, d19m3y20, d20m3y20, d21m3y20, d22m3y20, d23m3y20, d24m3y20, d25m3y20, d26m3y20, d27m3y20, d28m3y20, d29m3y20, d30m3y20, d31m3y20, d1m4y20, d2m4y20, d3m4y20, d4m4y20, d5m4y20, d6m4y20, d7m4y20, d8m4y20, d9m4y20, d10m4y20, d11m4y20, d12m4y20, d13m4y20, d14m4y20, d15m4y20, d16m4y20, d17m4y20, d18m4y20, d19m4y20, d20m4y20, d21m4y20, d22m4y20, d23m4y20, d24m4y20, d25m4y20, d26m4y20, d27m4y20, d28m4y20, d29m4y20, d30m4y20, d1m5y20, d2m5y20, d3m5y20, d4m5y20, d5m5y20, d6m5y20, d7m5y20, d8m5y20, d9m5y20, d10m5y20 ) VALUES ('Afghanistan','33.0','65.0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','1','1','1','1','1','1','2','2','2','2','2','2','5','5','10','10','10','15','18','18','29','32','32','32','32','32','40','43','54','99','112','131','135','150','166','179','188','188','207','220','228','252','260','310','331','345','397','421','458','468','472','502')";
    QSqlQuery insertar;
    insertar.exec(algo);
    if(insertar.exec(algo)){
        qDebug()<<"\n Insertado ";
    }else{
        qDebug()<<"\n Insertado fail"<<insertar.lastError();
    }
}

#endif // INSERTAR_H
