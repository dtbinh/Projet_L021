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
    fendossier = new FenDossier(app);
    fenconfiguration = new FenConfiguration(app);

    ui->contenu->addWidget(fenaccueil);
    ui->contenu->addWidget(fendossier);
    ui->contenu->addWidget(fenconfiguration);

    ui->menuDossiers->setDisabled(true);
    ui->menuConfiguration->setDisabled(true);

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
    if(quoi[0] == "nouveau")
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

    ui->menuDossiers->setDisabled(false);
    ui->menuConfiguration->setDisabled(false);
    on_menuDossiers_clicked();
}
