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
    }
}

void FenDossier::remplirInscriptions()
{
    QStandardItemModel* model = new QStandardItemModel();

    QStringList header_labels;
    header_labels << "Code" << "Période";

    unsigned int i = 0;
    for (map<QString,Inscription>::const_iterator it = app->getDossier().getInscriptions().begin(); it != app->getDossier().getInscriptions().end(); it++)
    {
        const Inscription& inscription = it->second;
        model->setItem(i,0,new QStandardItem(inscription.getCode()));
        model->setItem(i,1,new QStandardItem(inscription.getPeriode().getCode()));

        for (map<QString,UV>::const_iterator ituv = inscription.getUVs().begin(); ituv != inscription.getUVs().end(); ++ituv)
        {
            const UV& uv = ituv->second;
            /*int j = header_labels.indexOf(uv.getCategorie().getCode());
            if (j == -1) {
                header_labels << uv.getCategorie().getCode();
            }*/
            model->setItem(i,2,new QStandardItem(uv.getCode() + " " + inscription.getNotes().get(uv.getCode()).getNote()));
        }

        i++;
    }

    model->setHorizontalHeaderLabels(header_labels);

    delete ui->inscriptions->model();
    ui->inscriptions->setModel(model);
    ui->inscriptions->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
