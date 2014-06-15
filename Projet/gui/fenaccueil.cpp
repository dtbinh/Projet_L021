#include "fenaccueil.h"
#include "ui_fenaccueil.h"

FenAccueil::FenAccueil(Application *a, Observer* obs, QWidget *parent) :
    QWidget(parent),
    ApplicationComposant(a),
    ui(new Ui::FenAccueil),
    mainwindow(obs)
{
    ui->setupUi(this);

    remplirListeDossiers();
}

FenAccueil::~FenAccueil()
{
    delete ui;
}

void FenAccueil::on_listeDossiers_doubleClicked(const QModelIndex &index)
{
    QVariant login = index.data();
    QStringList notif;
    notif << "charger" << login.toString();
    mainwindow->notification(notif);
}

void FenAccueil::on_creer_clicked()
{
    if (ui->nomLabel->text() != "" && ui->prenomLabel->text() != "")
    {
        QStringList notif;
        notif << "nouveau" << ui->nomLineEdit->text() << ui->prenomLineEdit->text();
        mainwindow->notification(notif);
    }
}

void FenAccueil::remplirListeDossiers()
{
    QStringList liste_dossiers = app->listeDossiers();
    QStandardItemModel* model = new QStandardItemModel();

    for (int i = 0; i < liste_dossiers.size(); i++) {
        model->setItem(i,0,new QStandardItem(liste_dossiers[i]));
    }

    ui->listeDossiers->setModel(model);
}
