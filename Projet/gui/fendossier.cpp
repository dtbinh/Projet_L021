#include "fendossier.h"
#include "ui_fendossier.h"

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
