///
/// \file DossierManager.h
/// \brief Manager des Dossiers
/// \author Erwan Normand
/// \date 06 juin 2014
///

#ifndef DOSSIERMANAGER_H
#define DOSSIERMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Dossier.h"

class DossierManager
{
private:
    Manager<Dossier> dossiers;

public:
    DossierManager(): dossiers() {}

    void load(QString& fichier);

    Dossier& getDossier(const QString& login) { return dossiers.get(login); }
    const Dossier& getDossier(const QString& login) const { return dossiers.get(login); }
    void ajouterDossier(const QString& nom, const QString& prenom) { Dossier d(nom, prenom); dossiers.ajouter(d.getLogin(), d); }
    void retirerDossier(const QString& login) { dossiers.retirer(login); }
};

#endif // DOSSIERMANAGER_H
