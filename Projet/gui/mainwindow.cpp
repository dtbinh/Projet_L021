#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(Application *a, QWidget *parent) :
    QMainWindow(parent),
    ApplicationComposant(a),
    Observer(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fenaccueil = new FenAccueil(app, this);
    fendossier = new FenDossier(app, this);
    fenconfiguration = new FenConfiguration(app, this);
    panneauAction = new PanneauAction(app, this);

    QSizePolicy sp(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sp.setHorizontalStretch(3);
    fendossier->setSizePolicy(sp);
    fenconfiguration->setSizePolicy(sp);
    sp.setHorizontalStretch(1);
    panneauAction->setSizePolicy(sp);

    ui->contenu->addWidget(fenaccueil);
    ui->contenu->addWidget(fendossier);
    ui->contenu->addWidget(fenconfiguration);
    ui->contenu->addWidget(panneauAction);

    ui->menuDossiers->setDisabled(true);
    ui->menuConfiguration->setDisabled(true);
    panneauAction->setHidden(true);

    on_menuAccueil_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menuAccueil_clicked()
{
    ui->titre->setText("Accueil");

    fenaccueil->setVisible(true);
    fendossier->setHidden(true);
    fenconfiguration->setHidden(true);
    panneauAction->setHidden(true);

    ui->menuAccueil->setChecked(true);
    ui->menuDossiers->setChecked(false);
    ui->menuConfiguration->setChecked(false);
}

void MainWindow::on_menuDossiers_clicked()
{
    ui->titre->setText("Dossier de " + app->getDossier().getLogin() + " (" + app->getDossier().getPrenom() + " " + app->getDossier().getNom() + ")");

    fenaccueil->setHidden(true);
    fendossier->setVisible(true);
    fenconfiguration->setHidden(true);

    ui->menuAccueil->setChecked(false);
    ui->menuDossiers->setChecked(true);
    ui->menuConfiguration->setChecked(false);
}

void MainWindow::on_menuConfiguration_clicked()
{
    ui->titre->setText("Configuration de " + app->getDossier().getLogin() + " (" + app->getDossier().getPrenom() + " " + app->getDossier().getNom() + ")");

    fenaccueil->setHidden(true);
    fendossier->setHidden(true);
    fenconfiguration->setVisible(true);

    ui->menuAccueil->setChecked(false);
    ui->menuDossiers->setChecked(false);
    ui->menuConfiguration->setChecked(true);
}

void MainWindow::notification(const QStringList &quoi)
{
    if(quoi[0] == "nouveau" || quoi[0] == "charger")
    {
        if (quoi[0] == "nouveau")
        {
            QString nom = quoi[1];
            QString prenom = quoi[2];
            app->nouveau(nom, prenom);
        }
        else if (quoi[0] == "charger")
        {
            QString login = quoi[1];
            app->charger(login);
        }

        QStringList notif;
        notif << "remplir";
        fenconfiguration->notification(notif);
        fendossier->notification(notif);

        panneauAction->setHidden(true);
        ui->menuDossiers->setDisabled(false);
        ui->menuConfiguration->setDisabled(false);
        on_menuDossiers_clicked();
    }
    else if(quoi[0] == "editer")
    {
        panneauAction->setPanneau(quoi[0], quoi[1], quoi[2]);
        panneauAction->setVisible(true);
    }
    else if(quoi[0] == "ajouter")
    {
        panneauAction->setPanneau(quoi[0], quoi[1]);
        panneauAction->setVisible(true);
    }
    else if(quoi[0] == "remplir")
    {
        if (quoi[1] == "inscription" || quoi[1] == "formationDossier") {
            fendossier->notification(quoi);
        } else {
            fenconfiguration->notification(quoi);
        }
    }
}
