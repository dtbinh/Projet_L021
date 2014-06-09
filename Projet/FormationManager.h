///
/// \file FormationManager.h
/// \brief Manager des Formations.
/// \author Nicolas Szewe, Erwan Normand
/// \date 05 juin 2014
///

#ifndef FORMATIONMANAGER_H
#define FORMATIONMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Exception.h"
#include "Formation.h"
#include "CreditsManager.h"
#include "UVManager.h"

class FormationManager : public Manager
{
private:
    Factory<Formation> formations;

public:
    FormationManager(const QString& f = ""): Manager(f), formations() {}

    void load(const QString& fichier, const CreditsManager& credman);
    void load(const QString& fichier, const CreditsManager& credman,const UVManager& uvman,const FormationManager& filman);
    void save(const QString& fichier);

    Formation& getFormation(const QString& code) { return formations.get(code); }
    const Formation& getFormation(const QString& code) const { return formations.get(code); }
    void ajouterFormation(const QString& code, const QString& nom) { formations.ajouter(code, Formation(code, nom)); }
    void retirerFormation(const QString& code) { formations.retirer(code); }
};

#endif // FORMATIONMANAGER_H
