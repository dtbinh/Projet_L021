#include "configuration.h"
#include "ui_configuration.h"

Configuration::Configuration(Application *a, QWidget *parent) :
    QWidget(parent),
    applicationcomposant(a),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);

    ui->categories->setModel(categorieModele());
}

Configuration::~Configuration()
{
    delete ui;
}

QStandardItemModel *Configuration::categorieModele()
{
    QStandardItemModel* model = new QStandardItemModel(0,2,this);

    QStringList header_labels;
    header_labels << "code" << "nom";
    model->setHorizontalHeaderLabels(header_labels);

    model->setItem(0,0,new QStandardItem("CS"));
    model->setItem(0,1,new QStandardItem("Crédits Scientifiques"));

    return model;
}
