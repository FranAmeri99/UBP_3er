#include "formulario.h"
Formulario::Formulario(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("COVID-fran");

    layout = new QGridLayout;
    pbBuscar = new QPushButton;
    cbprov = new QComboBox;
    defecha = new QDateEdit;
    teSelect = new QTableWidget;
    pbBuscar->setText("Buscar");
/*
    cbinfectadosT = new QCheckBox("Infectados Totales");
    cbinfectadosD= new QCheckBox("Infectados Dia");
    cbMuertosT= new QCheckBox("Muertos Totales");
    cbMuertosD= new QCheckBox("Muertos Dia");
    layout->addWidget(cbinfectadosT,1,0,1,1);
    layout->addWidget(cbinfectadosD,1,1,1,1);
    layout->addWidget(cbMuertosT,1,2,1,1);
    layout->addWidget(cbMuertosD,1,3,1,1);
*/
    layout->addWidget(cbprov,0,0,1,2);
    layout->addWidget(defecha,0,2,1,1);
    layout->addWidget(pbBuscar,0,3,1,1);
    layout->addWidget(teSelect, 2,0,4,4);
    this->setLayout(layout);
    teSelect->setColumnCount(6);//adigno cantidad de columas
    QDate actual5;
    actual5.setDate(2020,5,28);//seteo un dia para agilisar el tesst
    defecha->setDate(actual5);
    //conecto base de datos
    db = new AdminDB;
    db->conectar( "../db/COVID.sqlite" );
   // db->creats();
    //COMO ya tengo los datos cargados dejo comentado la insercion
  //  db->insertar();
    cargarCB();
    connect( pbBuscar, SIGNAL( pressed() ) , this, SLOT( slot_mostra() ) );

    QStringList headers2 = { "FECHA", "PROVINCIA", "CASOS TOTALES","CASOS NUEVOS","MUERTOS TOTALES","MUERTOS NUEVOS" };
    teSelect->setHorizontalHeaderLabels(headers2);

}

void Formulario::cargarCB()
{
    cbprov->addItem("Buenos Aires");
    cbprov->addItem("CABA");
    cbprov->addItem("Catamarca");
    cbprov->addItem("Chaco");
    cbprov->addItem("Chubut");
    cbprov->addItem("Córdoba");
    cbprov->addItem("Corrientes");
    cbprov->addItem("Entre Ríos");
    cbprov->addItem("Formosa");
    cbprov->addItem("Jujuy");
    cbprov->addItem("La Pampa");
    cbprov->addItem("La Rioja");
    cbprov->addItem("Mendoza");
    cbprov->addItem("Misiones");
    cbprov->addItem("Neuquén");
    cbprov->addItem("Río Negro");
    cbprov->addItem("Salta");
    cbprov->addItem("San Juan");
    cbprov->addItem("Santa Cruz");
    cbprov->addItem("Santa Fe");
    cbprov->addItem("Santiago del Estero");
    cbprov->addItem("Tierra del Fuego");
    cbprov->addItem("Tucumán");


}


void Formulario::mostrar(QString provincia , QString fecha )
{
    QStringList headers2 = { "FECHA", "PROVINCIA", "CASOS TOTALES","CASOS NUEVOS","MUERTOS TOTALES","MUERTOS NUEVOS" };

    teSelect->setHorizontalHeaderLabels(headers2);

    //Genero Consulta
    QString consulta = "SELECT * FROM datos ";
    if (provincia != "todo"){
        consulta.append("WHERE provincia = '" + provincia + "' ");
        consulta.append(" AND fecha = '" + fecha + "'");
   }

    QVector<QStringList> cons = db->select(consulta);
    for (int i=0;i<cons.size();i++){
        teSelect->insertRow(i);
        for (int j=0;j<6;j++){
            teSelect->setItem(i,j,new QTableWidgetItem(cons.at(i).at(j)));
        }
    }
    QString * ptr_Provincia = new QString(cbprov->currentText());

    //graficador = new Grafico( cbinfectadosT , cbinfectadosD
                               //cbMuertosT ,cbMuertosD , db , ptr_Provincia);

    graficador = new Grafico( db , ptr_Provincia); //creo grafico
    graficador->show();
    graficador->resize(600,600);

}

QString Formulario::get_provinvia()
{
    return cbprov->currentText();
}

void Formulario::slot_mostra()
{
    teSelect->clear(); //limpio la tabla

    for (int i = teSelect->rowCount() ; i>-1; i--) {
        teSelect->removeRow(i); //elimino las filas en blanco
    }
    defecha->setDisplayFormat("yyyy-MM-dd"); //Cambio formato para
                                             //adecuarlo al de la tabla

    mostrar(cbprov->currentText(), defecha->text());

}


