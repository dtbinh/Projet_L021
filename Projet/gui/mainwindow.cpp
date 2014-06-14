#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Application *a, QWidget *parent) :
    QMainWindow(parent),
    ApplicationComposant(a),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fenaccueil = new FenAccueil(app);
    fendossier = new FenDossier(app);
    fenconfiguration = new FenConfiguration(app);

    ui->contenu->addWidget(fenaccueil);
    ui->contenu->addWidget(fendossier);
    ui->contenu->addWidget(fenconfiguration);

    on_menuDossiers_clicked();
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
    ui->titre->setText("Dossiers");

    fenaccueil->setHidden(true);
    fendossier->setVisible(true);
    fenconfiguration->setHidden(true);

    ui->menuAccueil->setChecked(false);
    ui->menuConfiguration->setChecked(false);
}

void MainWindow::on_menuConfiguration_clicked()
{
    ui->titre->setText("Configuration");

    fenaccueil->setHidden(true);
    fendossier->setHidden(true);
    fenconfiguration->setVisible(true);

    ui->menuAccueil->setChecked(false);
    ui->menuDossiers->setChecked(false);
}
