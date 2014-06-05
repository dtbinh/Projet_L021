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
#include <fstream>
#include "AbstractManager.h"
#include "Manager.h"
#include "Formation.h"

class FormationManager : public AbstractManager
{
private:
    Manager<Formation> formations;

public:
    FormationManager(): formations() {}

    //void load(CreditManager credman); //cpp non fonctionnel

    const Formation& getFormation(const QString& code) { return formations.get(code); }
    void ajouterFormation(const QString& code, const QString& nom) { formations.ajouter(code, Formation(code, nom)); }
    void retirerFormation(const QString& code) { formations.retirer(code); }
};

#endif // FORMATIONMANAGER_H
