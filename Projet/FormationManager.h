///
/// \file FormationManager.h
/// \brief Manager des Formations de l'UTC
/// \author Nicolas Szewe
/// \date 05 juin 2014
///

#ifndef FORMATIONMANAGER_H
#define FORMATIONMANAGER_H

#include <QString>
#include <map>
#include <algorithm>
#include "Manager.h"
#include "CreditManager.h"
#include "CategorieManager.h"
#include "UvManager.h"
#include "Formation.h"

class FormationManager
{

private:
    Manager<Formation> formations;

public:
    FormationManager(): formations() {}
    Formation* getFormation(const QString code) { return &formations.get(code); }
    void load(CreditManager cm);
    void ajouterFormation(QString code, QString nom) { formations.ajouter(code, Formation(code, nom)); }
    void retirerFormation(QString code) { formations.retirer(code); }
};

#endif // FORMATIONMANAGER_H
