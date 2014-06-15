#include "fenaccueil.h"
#include "ui_fenaccueil.h"

FenAccueil::FenAccueil(Application *a, Observateur* obs, QWidget *parent) :
    QWidget(parent),
    ApplicationComposant(a),
    ui(new Ui::FenAccueil),
    observateur(obs)
{
    ui->setupUi(this);

    QStringList liste_dossiers = app->listeDossiers();
    QStandardItemModel* model = new QStandardItemModel();

    for (int i = 0; i < liste_dossiers.size(); i++)
    {
        model->setItem(i,0,new QStandardItem(liste_dossiers[i]));
    }

    ui->listeDossiers->setModel(model);
}

FenAccueil::~FenAccueil()
{
    delete ui;
}

void FenAccueil::on_listeDossiers_doubleClicked(const QModelIndex &index)
{
    QVariant login = index.data();
    observateur->notification(login.toString());
}
