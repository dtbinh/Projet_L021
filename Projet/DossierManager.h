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
#include "Factory.h"
#include "FormationManager.h"
#include "PeriodeManager.h"
#include "UVManager.h"
#include "NoteManager.h"
#include "Dossier.h"

class DossierManager : public Manager
{
private:
    Factory<Dossier> dossiers;

public:
    DossierManager(): dossiers() {}

    void load(QString& fichier, const FormationManager& forman, const PeriodeManager& periodeman,const UVManager& uvman,const NoteManager& notman);
    void save(QString& fichier, QString& login);

    Dossier& getDossier(const QString& login) { return dossiers.get(login); }
    const Dossier& getDossier(const QString& login) const { return dossiers.get(login); }
    const QString& ajouterDossier(const QString& nom, const QString& prenom) { Dossier d(nom, prenom); dossiers.ajouter(d.getLogin(), d); return d.getLogin();}
    void retirerDossier(const QString& login) { dossiers.retirer(login); }
};

#endif // DOSSIERMANAGER_H
