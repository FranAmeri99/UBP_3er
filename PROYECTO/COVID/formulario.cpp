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
    layout->addWidget(cbprov,0,0,1,2);
    layout->addWidget(defecha,0,2,1,1);
    layout->addWidget(pbBuscar,0,3,1,1);
    layout->addWidget(teSelect, 1,0,4,4);
    this->setLayout(layout);
    teSelect->setColumnCount(5);;
    QDate actual5;
    actual5.setDate(2020,5,4);//seteo un dia para agilisar el tesst
    defecha->setDate(actual5);
    db = new AdminDB;
    db->conectar( "../db/COVID.sqlite" );
    db->creats();

    //db->insertar();
    cargarCB();
    connect( pbBuscar, SIGNAL( pressed() ) , this, SLOT( slot_mostra() ) );

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

    QStringList headers2 = { "FECHA", "PROVINCIA", "CASOS TOTALES","CASOS NUEVOS","MUERTOS","TOTALES","MUERTOS NUEVOS" };
    teSelect->setHorizontalHeaderLabels(headers2);
    QString consulta = "SELECT * FROM datos ";
    if (provincia != "todo"){
        consulta.append("WHERE provincia = '" + provincia + "' ");
        consulta.append(" AND fecha = '" + fecha + "'");
   }

    QVector<QStringList> cons = db->select(consulta);
    for (int i=0;i<cons.size();i++){
        teSelect->insertRow(i);
        for (int j=0;j<5;j++){
            teSelect->setItem(i,j,new QTableWidgetItem(cons.at(i).at(j)));
        }
    }
    graficador = new Grafico (db, cbprov->currentText());

}

QString Formulario::get_provinvia()
{
    return cbprov->currentText();
}

void Formulario::slot_mostra()
{
    teSelect->clear();

    for (int i = teSelect->rowCount() ; i>-1; i--) {
        teSelect->removeRow(i);
    }
    defecha->setDisplayFormat("yyyy-MM-dd");

    mostrar(cbprov->currentText(), defecha->text());

}


