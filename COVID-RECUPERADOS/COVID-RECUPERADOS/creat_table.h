#ifndef CREAT_TABLE_H
#define CREAT_TABLE_H

#include"ventana.h"
void ventana::CrearTablaUsuario()
{
    QByteArray line = archivo->readLine();

    qDebug()<<"\n CREAR TABLA RECUPERADOS";
    QByteArray consulta= "CREATE TABLE IF NOT EXISTS [recuperados] ("
            "Province VARCHAR ,"
            "Country VARCHAR ,"
            "Lat FLOAT,"
            "Long FLOAT,";
    consulta.append(line);

    int tamano_consulta = consulta.size();
    int cantidad_a_agregar = consulta.count(',');
    int arreglo_indice[cantidad_a_agregar];
    int w = 0;
    //for guardo en un arreglo las posiciones en donde debo
    //agregar el VARCHAR (30)
    for (int i = 0; i <tamano_consulta;i++) {
        if(consulta[i]==','){
            arreglo_indice[w]= i;
            w++;
        }
    }
    //for donde inserto el varchar()
    //lo recorro de atras para adelante para no andar recalculando
    // las posiciones

    for (w = cantidad_a_agregar-1;w>=0;w--) {
        int indice = arreglo_indice[w];
        consulta.insert(indice," TEXT");
    }
   // qDebug()<<"\n $$$$$$$$$$$$ \n" <<consulta;
   // archivo->write(consulta);
   // consulta.append(" TEXT");
   // qDebug()<<"\n $$$$$$$$$$$$ \n" <<consulta;
    //archivo2->flush();
    //archivo2->close();
    /*  QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec()){
        qDebug()<<"\n Creado2";
    }
    else {
        qDebug()<<"\n NO Creado"<<crear.lastError();
    }
*/
}


#endif // CREAT_TABLE_H


