#include "fenconfiguration.h"
#include "ui_fenconfiguration.h"

using namespace std;

FenConfiguration::FenConfiguration(Application *a, Observer* obs, QWidget *parent) :
    QWidget(parent),
    ApplicationComposant(a),
    Observer(),
    ui(new Ui::FenConfiguration),
    mainwindow(obs)
{
    ui->setupUi(this);

    remplirCategorie();
    remplirCredits();
    remplirFormation();
    remplirNote();
    remplirPeriode();
    remplirUV();
}

FenConfiguration::~FenConfiguration()
{
    delete ui;
}

void FenConfiguration::notification(const QStringList &quoi)
{
    if(quoi[0] == "remplir" && quoi.size() == 2)
    {
        if (quoi[1] == "categorie") {
            remplirCategorie();
        }
        else if (quoi[1] == "credits") {
            remplirCredits();
        }
        else if (quoi[1] == "formation") {
            remplirFormation();
        }
        else if (quoi[1] == "note") {
            remplirNote();
        }
        else if (quoi[1] == "periode") {
            remplirPeriode();
        }
        else if (quoi[1] == "uv") {
            remplirUV();
        }
        }
    else if (quoi[0] == "remplir")
    {
        remplirCategorie();
        remplirCredits();
        remplirFormation();
        remplirNote();
        remplirPeriode();
        remplirUV();
    }
}

void FenConfiguration::setPanneau(const QString &quoi, const QString& panneau, const QModelIndex& index)
{
    if (quoi == "editer")
    {
        QVariant code = index.sibling(index.row(),0).data();
        QStringList notif;
        notif << quoi << panneau << code.toString();
        mainwindow->notification(notif);
    }
    else if (quoi == "ajouter")
    {
        QStringList notif;
        notif << quoi << panneau;
        mainwindow->notification(notif);
    }
}

void FenConfiguration::remplirCategorie()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Categorie>::const_iterator it = app->getCategorieManager().getCategories().begin(); it != app->getCategorieManager().getCategories().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        i++;
    }

    delete ui->categorie->model();
    ui->categorie->setModel(model);
    ui->categorie->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void FenConfiguration::remplirCredits()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nombre" << "Catégorie";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Credits>::const_iterator it = app->getCreditsManager().getCredits().begin(); it != app->getCreditsManager().getCredits().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(QString::number(it->second.getNombre())));
        model->setItem(i,2,new QStandardItem(it->second.getCategorie().getCode()));
        i++;
    }

    delete ui->credits->model();
    ui->credits->setModel(model);
    ui->credits->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void FenConfiguration::remplirFormation()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Crédits" << "Spécialités" << "UVs";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Formation>::const_iterator it = app->getFormationManager().getFormations().begin(); it != app->getFormationManager().getFormations().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));

        QStringList credits;
        for (vector<const Credits*>::const_iterator it2 = it->second.getCredits().begin(); it2 != it->second.getCredits().end(); it2++) {
            credits << (*it2)->getCode();
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

    delete ui->formation->model();
    ui->formation->setModel(model);
    ui->formation->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void FenConfiguration::remplirNote()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Note" << "Mention";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Note>::const_iterator it = app->getNoteManager().getNotes().begin(); it != app->getNoteManager().getNotes().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getNote()));
        model->setItem(i,1,new QStandardItem(it->second.getMention()));
        i++;
    }

    delete ui->note->model();
    ui->note->setModel(model);
    ui->note->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void FenConfiguration::remplirPeriode()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Année";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,Periode>::const_iterator it = app->getPeriodeManager().getPeriodes().begin(); it != app->getPeriodeManager().getPeriodes().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        model->setItem(i,2,new QStandardItem(QString::number(it->second.getAnnee())));
        i++;
    }

    delete ui->periode->model();
    ui->periode->setModel(model);
    ui->periode->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void FenConfiguration::remplirUV()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Nom" << "Catégorie" << "Crédits";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (map<QString,UV>::const_iterator it = app->getUVManager().getUVs().begin(); it != app->getUVManager().getUVs().end(); it++)
    {
        model->setItem(i,0,new QStandardItem(it->second.getCode()));
        model->setItem(i,1,new QStandardItem(it->second.getNom()));
        model->setItem(i,2,new QStandardItem(it->second.getCategorie().getCode()));

        QStringList credits;
        for (vector<const Credits*>::const_iterator it2 = it->second.getCredits().begin(); it2 != it->second.getCredits().end(); it2++) {
            credits << (*it2)->getCode();
        }
        model->setItem(i,3,new QStandardItem(credits.join(", ")));

        i++;
    }

    delete ui->uv->model();
    ui->uv->setModel(model);
    ui->uv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
