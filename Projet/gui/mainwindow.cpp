#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Application *a, QWidget *parent) :
    QMainWindow(parent),
    ApplicationComposant(a),
    Observateur(),
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
}

void MainWindow::notification(const QString& quoi)
{
    app->charger(quoi);

    fenconfiguration->notification("remplir");

    ui->menuDossiers->setDisabled(false);
    ui->menuConfiguration->setDisabled(false);
    on_menuDossiers_clicked();
}
