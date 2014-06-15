#include "panneauaction.h"
#include "ui_panneauaction.h"

using namespace std;

PanneauAction::PanneauAction(Application *a, Observer* obs, QWidget *parent):
    QWidget(parent),
    ApplicationComposant(a),
    ui(new Ui::PanneauAction),
    fenconfiguration(obs),
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
    connect(formationModifier, SIGNAL(clicked()), this, SLOT(formationModifier_clicked()));
    connect(periodeModifier, SIGNAL(clicked()), this, SLOT(periodeModifier_clicked()));
    connect(noteModifier, SIGNAL(clicked()), this, SLOT(noteModifier_clicked()));
    connect(uvModifier, SIGNAL(clicked()), this, SLOT(uvModifier_clicked()));
}

PanneauAction::~PanneauAction()
{
    delete ui;
}

void PanneauAction::setPanneau(const QString& panneau, const QString& q, const QString &c)
{
    code = c;
    quoi = q;
    cacherPanneaux();

    if (panneau == "categorie")
    {
        if (quoi == "editer")
        {
            const Categorie& categorie = app->getCategorieManager().getCategorie(code);
            categorieCode->setText(code);
            categorieNom->setText(categorie.getNom());

            ui->titre->setText("Edition catégorie");
            categorieModifier->setText("Editer");
            panneaux["categorie"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            categorieCode->setText("");
            categorieNom->setText("");

            ui->titre->setText("Ajout catégorie");
            categorieModifier->setText("Ajouter");
            panneaux["categorie"]->setVisible(true);
        }
    }
    else if (panneau == "credits")
    {
        creditsCategorie->clear();
        for (map<QString,Categorie>::const_iterator it = app->getCategorieManager().getCategories().begin(); it != app->getCategorieManager().getCategories().end(); it++)
        {
            creditsCategorie->addItem(it->second.getCode());
        }

        if (quoi == "editer")
        {
            const Credits& credits = app->getCreditsManager().getCredits(code);
            creditsCode->setText(code);
            creditsNombre->setValue(credits.getNombre());
            creditsCategorie->setCurrentText(credits.getCategorie().getCode());

            ui->titre->setText("Edition crédits");
            creditsModifier->setText("Editer");
            panneaux["credits"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            creditsCode->setText(code);
            creditsNombre->setValue(0);

            ui->titre->setText("Ajout crédits");
            creditsModifier->setText("Ajouter");
            panneaux["credits"]->setVisible(true);
        }
    }
    else if (panneau == "formation")
    {
        if (quoi == "editer")
        {
            const Formation& formation = app->getFormationManager().getFormation(code);
            formationCode->setText(code);
            formationNom->setText(formation.getNom());

            ui->titre->setText("Edition formation");
            formationModifier->setText("Editer");
            panneaux["formation"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            formationCode->setText("");
            formationNom->setText("");

            ui->titre->setText("Ajout formation");
            formationModifier->setText("Ajouter");
            panneaux["formation"]->setVisible(true);
        }
    }
    else if (panneau == "periode")
    {
        if (quoi == "editer")
        {
            const Periode& periode = app->getPeriodeManager().getPeriode(code);
            periodeNom->setText(periode.getNom());
            periodeAnnee->setValue(periode.getAnnee());

            ui->titre->setText("Edition période");
            creditsModifier->setText("Editer");
            panneaux["periode"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            periodeNom->setText("");
            periodeAnnee->setValue(2015);

            ui->titre->setText("Ajout période");
            periodeModifier->setText("Ajouter");
            panneaux["periode"]->setVisible(true);
        }
    }
    else if (panneau == "note")
    {
        if (quoi == "editer")
        {
            const Note& note = app->getNoteManager().getNote(code);
            noteNote->setText(code);
            noteMention->setText(note.getMention());

            ui->titre->setText("Edition note");
            noteModifier->setText("Editer");
            panneaux["note"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            noteNote->setText("");
            noteMention->setText("");

            ui->titre->setText("Ajout note");
            noteModifier->setText("Ajouter");
            panneaux["note"]->setVisible(true);
        }
    }
    else if (panneau == "uv")
    {
        uvCategorie->clear();
        for (map<QString,Categorie>::const_iterator it = app->getCategorieManager().getCategories().begin(); it != app->getCategorieManager().getCategories().end(); it++)
        {
            uvCategorie->addItem(it->second.getCode());
        }

        if (quoi == "editer")
        {
            const UV& uv = app->getUVManager().getUV(code);
            uvCode->setText(code);
            uvNom->setText(uv.getNom());
            uvCategorie->setCurrentText(uv.getCategorie().getCode());

            ui->titre->setText("Edition UV");
            uvModifier->setText("Editer");
            panneaux["uv"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            uvCode->setText("");
            uvNom->setText("");

            ui->titre->setText("Ajout UV");
            uvModifier->setText("Ajouter");
            panneaux["uv"]->setVisible(true);
        }
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
    if (quoi == "editer")
    {
        Categorie& categorie = app->getCategorieManager().getCategorie(code);
        //categorie.setCode(categorieCode->text());
        categorie.setNom(categorieNom->text());
    }
    else if (quoi == "ajouter")
    {
        app->getCategorieManager().ajouterCategorie(categorieCode->text(), categorieNom->text());
    }

    QStringList notif;
    notif << "remplir" << "categorie";
    fenconfiguration->notification(notif);
    notif[1] = "credits";
    fenconfiguration->notification(notif);
    notif[1] = "formation";
    fenconfiguration->notification(notif);
}

void PanneauAction::creditsModifier_clicked()
{
    if (quoi == "editer")
    {
        Credits& credits = app->getCreditsManager().getCredits(code);
        credits.setNombre(creditsNombre->value());
        credits.setCategorie(app->getCategorieManager().getCategorie(creditsCategorie->currentText()));
        //credits.setCode(creditsCode->text());
    }
    else if (quoi == "ajouter")
    {
        app->getCreditsManager().ajouterCredits(creditsCode->text(), creditsNombre->value(), app->getCategorieManager().getCategorie(creditsCategorie->currentText()));
    }

    QStringList notif;
    notif << "remplir" << "credits";
    fenconfiguration->notification(notif);
    notif[1] = "formation";
    fenconfiguration->notification(notif);
    notif[1] = "uv";
    fenconfiguration->notification(notif);
}

void PanneauAction::formationModifier_clicked()
{
    if (quoi == "editer")
    {
        Formation& formation = app->getFormationManager().getFormation(code);
        //formation.setCode(formationCode->text());
        formation.setNom(formationNom->text());
    }
    else if (quoi == "ajouter")
    {
        app->getFormationManager().ajouterFormation(formationCode->text(), formationNom->text());
    }

    QStringList notif;
    notif << "remplir" << "formation";
    fenconfiguration->notification(notif);
}

void PanneauAction::periodeModifier_clicked()
{
    if (quoi == "editer")
    {
        //Periode& periode = app->getPeriodeManager().getPeriode(code);
        //periode.setNom(periodeNom->text());
        //periode.setAnnee(periodeAnnee->value());
    }
    else if (quoi == "ajouter")
    {
        app->getPeriodeManager().ajouterPeriode(periodeNom->text(), periodeAnnee->value());
    }

    QStringList notif;
    notif << "remplir" << "periode";
    fenconfiguration->notification(notif);
}

void PanneauAction::noteModifier_clicked()
{
    if (quoi == "editer")
    {
        Note& note = app->getNoteManager().getNote(code);
        //note.setNote(noteNote->text());
        note.setMention(noteMention->text());
    }
    else if (quoi == "ajouter")
    {
        app->getNoteManager().ajouterNote(noteNote->text(), noteMention->text());
    }

    QStringList notif;
    notif << "remplir" << "note";
    fenconfiguration->notification(notif);
    notif[1] = "uv";
    fenconfiguration->notification(notif);
}

void PanneauAction::uvModifier_clicked()
{
    if (quoi == "editer")
    {
        UV& uv = app->getUVManager().getUV(code);
        //uv.setCode(uvCode->text());
        uv.setCategorie(app->getCategorieManager().getCategorie(uvCategorie->currentText()));
        uv.setNom(uvNom->text());
    }
    else if (quoi == "ajouter")
    {
        app->getUVManager().ajouterUV(uvCode->text(), uvNom->text(), app->getCategorieManager().getCategorie(uvCategorie->currentText()));
    }

    QStringList notif;
    notif << "remplir" << "uv";
    fenconfiguration->notification(notif);
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

        form->addRow("Code", creditsCode);
        form->addRow("Nombre", creditsNombre);
        form->addRow("Catégorie", creditsCategorie);

        creditsModifier = new QPushButton("Editer");
        creditsModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(creditsModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "formation")
    {
        formationCode = new QLineEdit;
        formationNom = new QLineEdit;

        form->addRow("Code", formationCode);
        form->addRow("Nom", formationNom);

        formationModifier = new QPushButton("Editer");
        formationModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(formationModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "periode")
    {
        periodeNom = new QLineEdit;
        periodeAnnee = new QSpinBox;
        periodeAnnee->setRange(1800,2200);

        form->addRow("Nom", periodeNom);
        form->addRow("Année", periodeAnnee);

        periodeModifier = new QPushButton("Editer");
        periodeModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(periodeModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "note")
    {
        noteNote = new QLineEdit;
        noteMention = new QLineEdit;

        form->addRow("Note", noteNote);
        form->addRow("Mention", noteMention);

        noteModifier = new QPushButton("Editer");
        noteModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(noteModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "uv")
    {
        uvCode = new QLineEdit;
        uvNom = new QLineEdit;
        uvCategorie = new QComboBox;

        form->addRow("Code", uvCode);
        form->addRow("Nom", uvNom);
        form->addRow("Catégorie", uvCategorie);

        uvModifier = new QPushButton("Editer");
        uvModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(uvModifier, 0, Qt::AlignRight);
    }

    widget->setLayout(layout);
    return widget;
}
