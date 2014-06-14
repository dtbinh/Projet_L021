#include "configuration.h"
#include "ui_configuration.h"

using namespace std;

Configuration::Configuration(Application *a, QWidget *parent) :
    QWidget(parent),
    applicationcomposant(a),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);

    remplirCategorie();
    remplirCredits();
    remplirFormation();
    remplirNote();
    remplirPeriode();
    remplirUV();
}

Configuration::~Configuration()
{
    delete ui;
}

void Configuration::remplirCategorie()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Actions";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Categorie>::const_iterator it = app->getCategorieManager().getCategories().begin(); it != app->getCategorieManager().getCategories().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        i++;
    }

    ui->categories->setModel(model);
    ui->categories->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Configuration::remplirCredits()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Nom" << "Nombre" << "Catégorie" << "Actions";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Credits>::const_iterator it = app->getCreditsManager().getCredits().begin(); it != app->getCreditsManager().getCredits().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getNom()));
        model->setItem(i,1,new QStandardItem(QString::number(it->second.getNombre())));
        model->setItem(i,2,new QStandardItem(it->second.getCategorie().getCode()));
        i++;
    }

    ui->credits->setModel(model);
    ui->credits->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Configuration::remplirFormation()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Crédits" << "Spécialités" << "UVs" << "Actions";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Formation>::const_iterator it = app->getFormationManager().getFormations().begin(); it != app->getFormationManager().getFormations().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));

        QStringList credits;
        for (vector<const Credits*>::const_iterator it2 = it->second.getCredits().begin(); it2 != it->second.getCredits().end(); it2++) {
            credits << (*it2)->getNom();
        }
        model->setItem(i,2,new QStandardItem(credits.join(", ")));

        QStringList specialites;
        for (vector<const Formation*>::const_iterator it2 = it->second.getSpecialites().begin(); it2 != it->second.getSpecialites().end(); it2++) {
            specialites << (*it2)->getCode();
        }
        model->setItem(i,3,new QStandardItem(specialites.join(", ")));

        QStringList uvs;
        for (vector<const UV*>::const_iterator it2 = it->second.getUVs().begin(); it2 != it->second.getUVs().end(); it2++) {
            uvs << (*it2)->getCode();
        }
        model->setItem(i,4,new QStandardItem(uvs.join(", ")));

        i++;
    }

    ui->formations->setModel(model);
    ui->formations->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Configuration::remplirNote()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Note" << "Mention" << "Actions";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Note>::const_iterator it = app->getNoteManager().getNotes().begin(); it != app->getNoteManager().getNotes().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getNote()));
        model->setItem(i,1,new QStandardItem(it->second.getMention()));
        i++;
    }

    ui->notes->setModel(model);
    ui->notes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Configuration::remplirPeriode()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Année" << "Actions";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Periode>::const_iterator it = app->getPeriodeManager().getPeriodes().begin(); it != app->getPeriodeManager().getPeriodes().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        model->setItem(i,2,new QStandardItem(QString::number(it->second.getAnnee())));
        i++;
    }

    ui->periodes->setModel(model);
    ui->periodes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void Configuration::remplirUV()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Catégorie" << "Crédits" << "Prérequis" << "Actions";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,UV>::const_iterator it = app->getUVManager().getUVs().begin(); it != app->getUVManager().getUVs().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        model->setItem(i,2,new QStandardItem(it->second.getCategorie().getCode()));

        QStringList credits;
        for (vector<const Credits*>::const_iterator it2 = it->second.getCredits().begin(); it2 != it->second.getCredits().end(); it2++) {
            credits << (*it2)->getNom();
        }
        model->setItem(i,3,new QStandardItem(credits.join(", ")));

        QStringList prerequis;
        for (vector<const UV*>::const_iterator it2 = it->second.getPrerequis().begin(); it2 != it->second.getPrerequis().end(); it2++) {
            prerequis << (*it2)->getCode();
        }
        model->setItem(i,4,new QStandardItem(prerequis.join(", ")));

        i++;
    }

    ui->uvs->setModel(model);
    ui->uvs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
