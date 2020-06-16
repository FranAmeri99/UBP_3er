    #include "formulario.h"
#include "sir.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent)
{

    this->setWindowTitle("COVID-fran");
    //DATOS PARA MODELO SI
    poblacion_s = new QSpinBox;
    dias_s = new QDoubleSpinBox;
    beta_s = new QDoubleSpinBox;
    gama_s = new QDoubleSpinBox;
    //asigno dominio de valores que pueden tomar
    dias_s->setRange(1,800);
    poblacion_s->setRange(1,17000000);
    beta_s->setRange(00.0,5.0);
    gama_s->setRange(00.0,5.0);
    //asigno valores por defecto
    poblacion_s->setValue(100);
    dias_s->setValue(97);
    beta_s->setValue(100);
    gama_s->setValue(100);
    lDias = new QLabel;
    lDias->setText("Ingrese la cantida de dias para la proyeccion del Model SIR");
    pbActualizar = new QPushButton;
    pbActualizar->setText("Actualizar Datos");


    layout = new QGridLayout;
    pbBuscar = new QPushButton;
    cbprov = new QComboBox;
    cbprov2 = new QComboBox;
    defecha = new QDateEdit;
    teSelect = new QTableWidget;
    pbBuscar->setText("Buscar");

    cbinfectadosT = new QCheckBox("Infectados Totales");
    cbinfectadosT->click();
    cbinfectadosD= new QCheckBox("Infectados Dia");
    cbMuertosT= new QCheckBox("Muertos Totales");
    cbMuertosD= new QCheckBox("Muertos Dia");

    layout->addWidget(cbprov,0,0,1,1);
    layout->addWidget(cbprov2,0,1,1,1);
    layout->addWidget(defecha,0,2,1,1);
    layout->addWidget(pbBuscar,0,3,1,1);

    layout->addWidget(cbinfectadosT,1,0,1,1);
    layout->addWidget(cbinfectadosD,1,1,1,1);
    layout->addWidget(cbMuertosT,1,2,1,1);
    layout->addWidget(cbMuertosD,1,3,1,1);

    layout->addWidget(lDias,2,0,1,2);
    layout->addWidget(dias_s,2,2,1,1);
    layout->addWidget(pbActualizar,2,3,1,1);

    layout->addWidget(teSelect, 3,0,4,4);
    this->setLayout(layout);
    teSelect->setColumnCount(6);//adigno cantidad de columas
    QDate actual5;
    actual5.setDate(2020,5,28);//seteo un dia para el tesst
    defecha->setDate(actual5);
    //conecto base de datos
    db = new AdminDB;
    db->conectar( "../db/COVID.sqlite" );

    cargarCB(cbprov); //cardo los combo box con las provincias de argentina
    cargarCB(cbprov2);

    connect( pbBuscar, SIGNAL( pressed() ) , this, SLOT( slot_mostra() ) );
    connect(pbActualizar, SIGNAL( pressed() ) , this, SLOT( slot_actualizare() ) );

    QStringList headers2 = { "FECHA", "PROVINCIA", "CASOS TOTALES",
                             "CASOS NUEVOS","MUERTOS TOTALES","MUERTOS NUEVOS" };
    teSelect->setHorizontalHeaderLabels(headers2); //encabezado

    QDate inicio(2020,03,05);//se registra el primer caso en argentina
    QDate actual=actual.currentDate(); //fecha actual
    defecha->setDateRange(inicio,actual); // rango para la busqueda de datos

}

void Formulario::cargarCB(QComboBox * combo)
{
    qDebug()<<"Cargando provianciassassss";
    QString consulta2 = "SELECT nombre FROM provincia";
    QSqlQuery query2;
    query2.exec(consulta2);

    while (query2.next()) {
        QString nombre = query2.value(0).toString();
        combo->addItem(nombre);
    }
}


void Formulario::mostrar(QString provincia , QString provincia2 , QString fecha )
{
    QStringList headers2 = { "FECHA", "PROVINCIA", "CASOS TOTALES",
                             "CASOS NUEVOS","MUERTOS TOTALES",
                             "MUERTOS NUEVOS" };

    teSelect->setHorizontalHeaderLabels(headers2);

    //Genero Consulta
    QString consulta = "SELECT * FROM datos ";
    if (provincia != "todo"){
        consulta.append("WHERE provincia = '" + provincia + "' ");
        consulta.append("AND fecha = '" + fecha + "'");
        consulta.append("OR  provincia = '"+ provincia2 + "' ");
        consulta.append("AND fecha = '" + fecha + "'");
    }

    QVector<QStringList> cons = db->select(consulta);
    for (int i=0;i<cons.size();i++){
        teSelect->insertRow(i);
        for (int j=0;j<6;j++){
            teSelect->setItem(i,j,new QTableWidgetItem(cons.at(i).at(j)));
        }
    }
    QString * ptr_Provincia = new QString(cbprov->currentText());
    QString * ptr_Provincia2= new QString(cbprov2->currentText());

    bool * MIT = new bool(cbinfectadosT->isChecked());
    bool * MID = new bool(cbinfectadosD->isChecked());
    bool * MMT= new bool(cbMuertosT->isChecked());
    bool * MMD = new bool(cbMuertosD->isChecked());
    bool * SIR = new bool(false);



    graficador = new Grafico( db , MIT , MID, MMT,MMD,SIR,
                              ptr_Provincia, ptr_Provincia2); //creo grafico
    graficador->show();
    graficador->resize(600,600);

}


void Formulario::slot_mostra()
{
    teSelect->clear(); //limpio la tabla

    for (int i = teSelect->rowCount() ; i>-1; i--) {
        teSelect->removeRow(i); //elimino las filas en blanco
    }
    defecha->setDisplayFormat("yyyy-MM-dd"); //Cambio formato para
                                             //adecuarlo al de la tabla
    QSqlQuery tam_pobl;
    QString consulta = "SELECT * FROM provincia WHERE nombre = '" + cbprov->currentText() + "'";

    tam_pobl.exec(consulta);
        qDebug()<<"consulta para poblacion" <<tam_pobl.lastError();
    int poblacion;
    while (tam_pobl.next()){
        poblacion = tam_pobl.value(1).toInt();

    }
   // qDebug()<<"poblacin formulario1: "<<poblacion;
    /*sir * Sir;
    Sir = new sir;
    int * N = new int();
    *N = poblacion;
    qDebug()<<"poblacin formulario: "<<*N;
    Sir->poblacion = N;
    double * diasF = new double();
    *diasF = dias_s->value();
    Sir->dias = diasF;


    Sir->cargar();
*/
    mostrar(cbprov->currentText(),cbprov2->currentText(), defecha->text());


}

void Formulario::slot_actualizare()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Insertando");
    msgBox.setText("Se Insertaron los datos\n"
                   "esto puede tardar un tiempo "
                   "espere a que aparesaca un "
                   "nuevo mensaje OK");


    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){

        qDebug()<<"actualizando ....";
        db->creats();
        //db->CrearProvincias();
        //COMO ya tengo los datos cargados dejo comentado la insercion
        db->insertar();
        qDebug()<<"Fin  ....";
        msgBox.information(this,"Insertando",
                           "LISTO");
    }else {
        msgBox.warning(this,"Actualizar",
                           "No se Actualizo");
    }


}


