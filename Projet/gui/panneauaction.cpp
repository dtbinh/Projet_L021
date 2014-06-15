#include "panneauaction.h"
#include "ui_panneauaction.h"

using namespace std;

PanneauAction::PanneauAction(Application *a, Observateur* obs, QWidget *parent):
    QWidget(parent),
    ApplicationComposant(a),
    ui(new Ui::PanneauAction),
    observateur(obs),
    code(""),
    panneaux()
{
    ui->setupUi(this);

    panneaux["categorie"] = creerPanneau("categorie");
    panneaux["credits"] = creerPanneau("credits");
    panneaux["formation"] = creerPanneau("formation");
    panneaux["periode"] = creerPanneau("periode");
    panneaux["note"] = creerPanneau("note");
    panneaux["uv"] = creerPanneau("uv");

    cacherPanneaux();
    ui->contenu->addWidget(panneaux["categorie"]);
    ui->contenu->addWidget(panneaux["credits"]);
    ui->contenu->addWidget(panneaux["formation"]);
    ui->contenu->addWidget(panneaux["periode"]);
    ui->contenu->addWidget(panneaux["note"]);
    ui->contenu->addWidget(panneaux["uv"]);

    connect(categorieModifier, SIGNAL(clicked()), this, SLOT(categorieModifier_clicked()));
    connect(creditsModifier, SIGNAL(clicked()), this, SLOT(creditsModifier_clicked()));
}

PanneauAction::~PanneauAction()
{
    delete ui;
    delete categorieCode;
    delete categorieNom;
    delete categorieModifier;
}

void PanneauAction::setPanneau(const QString& panneau, const QString &c)
{
    code = c;
    cacherPanneaux();

    if (panneau == "categorie")
    {
        Categorie& categorie = app->getCategorieManager().getCategorie(code);
        categorieCode->setText(code);
        categorieNom->setText(categorie.getNom());

        ui->titre->setText("Edition");
        panneaux["categorie"]->setVisible(true);
    }
    else if (panneau == "credits")
    {
        Credits& credits = app->getCreditsManager().getCredits(code);
        creditsCode->setText(code);
        creditsNombre->setValue(credits.getNombre());

        ui->titre->setText("Edition");
        panneaux["credits"]->setVisible(true);
    }
}

void PanneauAction::cacherPanneaux()
{
    for(QMap<QString, QWidget*>::iterator it = panneaux.begin(); it != panneaux.end(); ++it) {
        it.value()->setHidden(true);
    }
}

void PanneauAction::categorieModifier_clicked()
{
    Categorie& categorie = app->getCategorieManager().getCategorie(code);
    categorie.setCode(categorieCode->text());
    categorie.setNom(categorieNom->text());

    observateur->notification("remplirCategorie");
    observateur->notification("remplirCredits");
    observateur->notification("remplirFormation");
}

void PanneauAction::creditsModifier_clicked()
{
    Credits& credits = app->getCreditsManager().getCredits(code);
    credits.setNom(creditsCode->text());
    credits.setNombre(creditsNombre->value());
    credits.setCategorie(app->getCategorieManager().getCategorie(creditsCategorie->currentText()));

    observateur->notification("remplirCredits");
    observateur->notification("remplirFormation");
    observateur->notification("remplirUV");
}

QWidget* PanneauAction::creerPanneau(const QString& panneau)
{
    QWidget* widget = new QWidget;
    QFormLayout* form = new QFormLayout;
    QVBoxLayout* layout = new QVBoxLayout;

    if (panneau == "categorie")
    {
        categorieCode = new QLineEdit;
        categorieNom = new QLineEdit;

        form->addRow("Code", categorieCode);
        form->addRow("Nom", categorieNom);

        categorieModifier = new QPushButton("Editer");
        categorieModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(categorieModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "credits")
    {
        creditsCode = new QLineEdit;
        creditsNombre = new QSpinBox;
        creditsCategorie = new QComboBox;

        for (map<QString,Categorie>::const_iterator it = app->getCategorieManager().getCategories().begin(); it != app->getCategorieManager().getCategories().end(); it++)
        {
            creditsCategorie->addItem(it->second.getCode());
        }

        form->addRow("Code", creditsCode);
        form->addRow("Nombre", creditsNombre);
        form->addRow("Catégorie", creditsCategorie);

        creditsModifier = new QPushButton("Editer");
        creditsModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(creditsModifier, 0, Qt::AlignRight);
    }

    widget->setLayout(layout);
    return widget;
}
