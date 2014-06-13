#include "configuration.h"
#include "ui_configuration.h"

using namespace std;

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
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Categorie>::const_iterator it = app->getCategorieManager().begin(); it != app->getCategorieManager().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        i++;
    }

    return model;
}
