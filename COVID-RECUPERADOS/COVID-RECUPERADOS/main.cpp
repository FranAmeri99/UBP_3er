#include "ventana.h"

#include <QApplication>
void tabla();
int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QWidget qwvent;
    ventana * vent = new ventana(&qwvent);
void tabla();
return app.exec();
}

void tabla(){
    QString a = "CREATE TABLE IF [recuperados] ([Province] VARCHAR NULL,[Country] VARCHAR NULL,[Lat] FLOAT NULL,[Long] FLOAT NULL,";

    qDebug()<<a;
  for(int m=1; m<1;m++) {

        for (int d=1;d<31;d++){
            /*if(d==1&&m==1){
                d=22;
            }
            if(d==31 && (m==2 || m==4 || m==6)){
                break;
               }*/

            //a.append(m);
            a.append("/");
            a.append(d);
            a.append("/");
            a.append("/20");

            qDebug()<<a;

        }
        }

        }

