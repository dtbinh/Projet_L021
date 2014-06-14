#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Application *a, QWidget *parent) :
    QMainWindow(parent),
    applicationcomposant(a),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    accueil = new Accueil(app);
    configuration = new Configuration(app);

    ui->contenu->addWidget(accueil);
    ui->contenu->addWidget(configuration);

    on_menuBoutonDossiers_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete accueil;
    delete configuration;
}

void MainWindow::on_menuBoutonDossiers_clicked()
{
    ui->titre->setText("Dossiers");
    accueil->setHidden(false);
    configuration->setHidden(true);
    //ui->menuBoutonDossiers->setStyleSheet("background-color: yellow;");
}

void MainWindow::on_menuBoutonConfiguration_clicked()
{
    ui->titre->setText("Configuration");
    accueil->setHidden(true);
    configuration->setHidden(false);
}
