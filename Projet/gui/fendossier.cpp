#include "fendossier.h"
#include "ui_fendossier.h"

using namespace std;

FenDossier::FenDossier(Application *a, QWidget *parent) :
    QWidget(parent),
    ApplicationComposant(a),
    ui(new Ui::FenDossier)
{
    ui->setupUi(this);
}

FenDossier::~FenDossier()
{
    delete ui;
}

void FenDossier::notification(const QStringList &quoi)
{
    if (quoi[0] == "remplir") {
        remplirInscriptions();
        remplirCreditsFormations();
    }
}

void FenDossier::remplirInscriptions()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Période" << "Inscription";

    unsigned int i = 0;
    for (map<QString,Inscription>::const_iterator it = app->getDossier().getInscriptions().begin(); it != app->getDossier().getInscriptions().end(); it++)
    {
        const Inscription& inscription = it->second;
        model->setItem(i,0,new QStandardItem(inscription.getCode()));
        model->setItem(i,1,new QStandardItem(inscription.getPeriode().getCode()));

        QMap<int,QStringList> uvs_categories;
        for (map<QString,UV>::const_iterator ituv = inscription.getUVs().begin(); ituv != inscription.getUVs().end(); ++ituv)
        {
            const UV& uv = ituv->second;
            const QString& categorie = uv.getCategorie().getCode();

            int j = header_labels.indexOf(categorie, 2);
            if (j == -1)
            {
                header_labels << categorie; //Ajout de la catégorie aux colonnes
                j = header_labels.count();
            }

            QString credits = "";
            for (vector<const Credits*>::const_iterator itcred = uv.getCredits().begin(); itcred != uv.getCredits().end(); ++itcred)
            {
                if ((*itcred)->getCategorie().getCode() == categorie) {
                    credits += QString::number((*itcred)->getNombre());
                }
            }

            uvs_categories[j] << uv.getCode() + " " + credits + " " + inscription.getNotes().get(uv.getCode()).getNote();
        }

        for(QMap<int,QStringList>::const_iterator itcat = uvs_categories.begin(); itcat != uvs_categories.end(); ++itcat)
        {
            model->setItem(i,itcat.key(),new QStandardItem(itcat.value().join(" | ")));
        }

        i++;
    }

    model->setHorizontalHeaderLabels(header_labels);

    delete ui->inscriptions->model();
    ui->inscriptions->setModel(model);
    ui->inscriptions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void FenDossier::remplirCreditsFormations()
{
    for (map<QString,Formation>::const_iterator it = app->getDossier().getFormations().begin(); it != app->getDossier().getFormations().end(); it++)
    {
        QWidget* credits_formation = creerCreditsFormation(it->second);
        ui->formations->addWidget(credits_formation);
    }
}

QWidget* FenDossier::creerCreditsFormation(const Formation& formation)
{
    QWidget* widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    QTableView* view = new QTableView;
    QStandardItemModel* model = new QStandardItemModel();
    Factory<Credits> creditsDossier = app->getDossier().getCredits(app->getCategorieManager());

    QLabel* titre = new QLabel(formation.getNom());

    QStringList header_labels;
    header_labels << "Validés" << "A valider";
    model->setHorizontalHeaderLabels(header_labels);

    unsigned int i = 0;
    for (vector<const Credits*>::const_iterator it = formation.getCredits().begin(); it != formation.getCredits().end(); it++)
    {
        model->setVerticalHeaderItem(i, new QStandardItem((*it)->getCategorie().getCode()));
        model->setItem(i,0, new QStandardItem(QString::number(creditsDossier.get((*it)->getCategorie().getCode()).getNombre())));
        model->setItem(i,1, new QStandardItem(QString::number((*it)->getNombre())));
        i++;
    }

    view->setModel(model);
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    view->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(titre);
    layout->addWidget(view);

    QSizePolicy sp(QSizePolicy::Maximum, QSizePolicy::Maximum);
    widget->setLayout(layout);
    widget->setSizePolicy(sp);

    return widget;
}
