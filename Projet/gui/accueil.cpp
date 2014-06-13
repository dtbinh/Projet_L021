#include "accueil.h"
#include "ui_accueil.h"

Accueil::Accueil(Application *a, QWidget *parent) :
    QWidget(parent),
    applicationcomposant(a),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}
