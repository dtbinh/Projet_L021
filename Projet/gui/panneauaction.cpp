#include "panneauaction.h"
#include "ui_panneauaction.h"

using namespace std;

PanneauAction::PanneauAction(Application *a, Observer* obs, QWidget *parent):
    QWidget(parent),
    ApplicationComposant(a),
    ui(new Ui::PanneauAction),
    mainwindows(obs),
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
    panneaux["inscription"] = creerPanneau("inscription");
    panneaux["formationDossier"] = creerPanneau("formationDossier");
    panneaux["preference"] = creerPanneau("preference");
    panneaux["uvInscription"] = creerPanneau("uvInscription");

    cacherPanneaux();
    ui->contenu->addWidget(panneaux["categorie"]);
    ui->contenu->addWidget(panneaux["credits"]);
    ui->contenu->addWidget(panneaux["formation"]);
    ui->contenu->addWidget(panneaux["periode"]);
    ui->contenu->addWidget(panneaux["note"]);
    ui->contenu->addWidget(panneaux["uv"]);
    ui->contenu->addWidget(panneaux["inscription"]);
    ui->contenu->addWidget(panneaux["formationDossier"]);
    ui->contenu->addWidget(panneaux["preference"]);
    ui->contenu->addWidget(panneaux["uvInscription"]);

    connect(categorieModifier, SIGNAL(clicked()), this, SLOT(categorieModifier_clicked()));
    connect(creditsModifier, SIGNAL(clicked()), this, SLOT(creditsModifier_clicked()));
    connect(formationModifier, SIGNAL(clicked()), this, SLOT(formationModifier_clicked()));
    connect(periodeModifier, SIGNAL(clicked()), this, SLOT(periodeModifier_clicked()));
    connect(noteModifier, SIGNAL(clicked()), this, SLOT(noteModifier_clicked()));
    connect(uvModifier, SIGNAL(clicked()), this, SLOT(uvModifier_clicked()));
    connect(inscriptionModifier, SIGNAL(clicked()), this, SLOT(inscriptionModifier_clicked()));
    connect(formationDossierModifier, SIGNAL(clicked()), this, SLOT(formationDossierModifier_clicked()));
    connect(preferenceModifier, SIGNAL(clicked()), this, SLOT(preferenceModifier_clicked()));
    connect(uvInscriptionModifier, SIGNAL(clicked()), this, SLOT(uvInscriptionModifier_clicked()));

}

PanneauAction::~PanneauAction()
{
    delete ui;
}

void PanneauAction::setPanneau(const QString& q, const QString& panneau, const QString &c)
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
    else if (panneau == "inscription")
    {
        inscriptionPeriode->clear();
        for (map<QString,Periode>::const_iterator it = app->getPeriodeManager().getPeriodes().begin(); it != app->getPeriodeManager().getPeriodes().end(); it++)
        {
            inscriptionPeriode->addItem(it->second.getCode());
        }
        inscriptionFormation->clear();
        for (map<QString,Formation>::const_iterator it = app->getFormationManager().getFormations().begin(); it != app->getFormationManager().getFormations().end(); it++)
        {
            inscriptionFormation->addItem(it->second.getCode());
        }

        if (quoi == "editer")
        {
            const Inscription& inscription = app->getDossier().getInscription(code);
            inscriptionCode->setText(code);
            inscriptionPeriode->setCurrentText(inscription.getPeriode().getCode());
            inscriptionFormation->setCurrentText(inscription.getFormation().getCode());

            ui->titre->setText("Edition inscription");
            inscriptionModifier->setText("Editer");
            panneaux["inscription"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            inscriptionCode->setText("");

            ui->titre->setText("Ajout inscription");
            inscriptionModifier->setText("Ajouter");
            panneaux["inscription"]->setVisible(true);
        }
    }
    else if (panneau == "formationDossier")
    {
        formationDossierCode->clear();
        for (map<QString,Formation>::const_iterator it = app->getFormationManager().getFormations().begin(); it != app->getFormationManager().getFormations().end(); it++)
        {
            formationDossierCode->addItem(it->second.getCode());
        }

        if (quoi == "editer")
        {
            formationDossierCode->setCurrentText(app->getDossier().getFormation(code).getCode());

            ui->titre->setText("Edition formation du dossier");
            formationDossierModifier->setText("Editer");
            panneaux["formationDossier"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            ui->titre->setText("Ajout formation au dossier");
            formationDossierModifier->setText("Ajouter");
            panneaux["formationDossier"]->setVisible(true);
        }
    }
    else if (panneau == "preference")
    {
        preferenceCode->clear();
        for (map<QString,UV>::const_iterator it = app->getUVManager().getUVs().begin(); it != app->getUVManager().getUVs().end(); it++)
        {
            preferenceCode->addItem(it->second.getCode());
        }

        if (quoi == "editer")
        {
            preferenceCode->setCurrentText(app->getUVManager().getUV(code).getCode());
            preferencePref->setCurrentText(app->getCompletion().getPreferences().find(code)->second); //écrit en "dur" dans creer

            ui->titre->setText("Edition préférence");
            preferenceModifier->setText("Editer");
            panneaux["preference"]->setVisible(true);
        }
        else if (quoi == "ajouter")
        {
            ui->titre->setText("Ajout préférence");
            preferenceModifier->setText("Ajouter");
            panneaux["preference"]->setVisible(true);
        }
    }
    else if (panneau == "uvInscription")
    {
        uvInscriptionCode->clear();
        for (map<QString,UV>::const_iterator it = app->getUVManager().getUVs().begin(); it != app->getUVManager().getUVs().end(); it++)
        {
            uvInscriptionCode->addItem(it->second.getCode());
        }

        uvInscriptionNote->clear();
        for (map<QString,Note>::const_iterator it = app->getNoteManager().getNotes().begin(); it != app->getNoteManager().getNotes().end(); it++)
        {
            uvInscriptionNote->addItem(it->second.getNote());
        }

        uvInscriptionInscription->clear();
        for (map<QString,Inscription>::const_iterator it = app->getDossier().getInscriptions().begin(); it != app->getDossier().getInscriptions().end(); it++)
        {
            uvInscriptionInscription->addItem(it->second.getCode());
        }

        if (quoi == "ajouter")
        {
            ui->titre->setText("Ajout/Edition UV");
            preferenceModifier->setText("Ajouter/Editer");
            panneaux["uvInscription"]->setVisible(true);
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
    mainwindows->notification(notif);
    notif[1] = "credits";
    mainwindows->notification(notif);
    notif[1] = "formation";
    mainwindows->notification(notif);
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
    mainwindows->notification(notif);
    notif[1] = "formation";
    mainwindows->notification(notif);
    notif[1] = "uv";
    mainwindows->notification(notif);
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
    mainwindows->notification(notif);
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
    mainwindows->notification(notif);
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
    mainwindows->notification(notif);
    notif[1] = "uv";
    mainwindows->notification(notif);
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
    mainwindows->notification(notif);
}

void PanneauAction::inscriptionModifier_clicked()
{
    if (quoi == "editer")
    {
        Inscription& inscription = app->getDossier().getInscription(code);
        //inscription.setCode(inscriptionCode->text());
        inscription.setPeriode(app->getPeriodeManager().getPeriode(inscriptionPeriode->currentText()));
        inscription.setFormation(app->getFormationManager().getFormation(inscriptionFormation->currentText()));
    }
    else if (quoi == "ajouter")
    {
        app->getDossier().ajouterInscription(inscriptionCode->text(), app->getPeriodeManager().getPeriode(inscriptionPeriode->currentText()), app->getFormationManager().getFormation(inscriptionFormation->currentText()));
    }

    QStringList notif;
    notif << "remplir" << "inscription";
    mainwindows->notification(notif);
}

void PanneauAction::formationDossierModifier_clicked()
{
    if (quoi == "editer")
    {
        app->getDossier().getFormation(code) = app->getFormationManager().getFormation(code);
        app->getDossier().changerCodeFormation(code, formationDossierCode->currentText());
    }
    else if (quoi == "ajouter")
    {
        app->getDossier().ajouterFormation(app->getFormationManager().getFormation(formationDossierCode->currentText()));
    }

    QStringList notif;
    notif << "remplir" << "formationDossier";
    mainwindows->notification(notif);
}

void PanneauAction::preferenceModifier_clicked()
{
    if (quoi == "editer")
    {
        app->getCompletion().setPreference(preferenceCode->currentText(), preferencePref->currentText());
    }
    else if (quoi == "ajouter")
    {
        app->getCompletion().ajouterPreference(preferenceCode->currentText(), preferencePref->currentText());
    }

    QStringList notif;
    notif << "remplir" << "preference";
    mainwindows->notification(notif);
}

void PanneauAction::uvInscriptionModifier_clicked()
{
    if (quoi == "ajouter")
    {
        app->getDossier().getInscription(uvInscriptionInscription->currentText()).ajouterUV(app->getUVManager().getUV(uvInscriptionCode->currentText()));
        app->getDossier().getInscription(uvInscriptionInscription->currentText()).modifierNote(uvInscriptionCode->currentText(), uvInscriptionNote->currentText());
    }

    QStringList notif;
    notif << "remplir" << "inscription";
    mainwindows->notification(notif);
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
    else if (panneau == "inscription")
    {
        inscriptionCode = new QLineEdit;
        inscriptionPeriode = new QComboBox;
        inscriptionFormation = new QComboBox;

        form->addRow("Code", inscriptionCode);
        form->addRow("Période", inscriptionPeriode);
        form->addRow("Formation", inscriptionFormation);

        inscriptionModifier = new QPushButton("Editer");
        inscriptionModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(inscriptionModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "formationDossier")
    {
        formationDossierCode = new QComboBox;

        form->addRow("Formation", formationDossierCode);

        formationDossierModifier = new QPushButton("Editer");
        formationDossierModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(formationDossierModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "preference")
    {
        preferenceCode = new QComboBox;
        preferencePref = new QComboBox;
        preferencePref->addItem("Exigence");
        preferencePref->addItem("Refus");

        form->addRow("UV", preferenceCode);
        form->addRow("Préférence", preferencePref);

        preferenceModifier = new QPushButton("Editer");
        preferenceModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(preferenceModifier, 0, Qt::AlignRight);
    }
    else if (panneau == "uvInscription")
    {
        uvInscriptionCode = new QComboBox;
        uvInscriptionNote = new QComboBox;
        uvInscriptionInscription = new QComboBox;

        form->addRow("UV", uvInscriptionCode);
        form->addRow("Note", uvInscriptionNote);
        form->addRow("Inscription", uvInscriptionInscription);

        uvInscriptionModifier = new QPushButton("Ajouter/Editer");
        uvInscriptionModifier->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);

        layout->addLayout(form);
        layout->addWidget(uvInscriptionModifier, 0, Qt::AlignRight);
    }

    widget->setLayout(layout);
    return widget;
}
