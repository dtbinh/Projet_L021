///
/// \file CreditManager.h
/// \brief Manager des Credit
/// \author Nicolas Szewe
/// \date 04 juin 2014
///

#ifndef CREDITMANAGER_H
#define CREDITMANAGER_H

#include <QString>
#include <map>
#include <algorithm>
#include "Manager.h"
#include "Categorie.h"
#include "Credits.h"
#include "CategorieManager.h"

class CreditManager
{

private:
    Manager<Credits> credits;

public:
    CreditManager(): credits() {}

    const Credits& getCredit(const QString code) const { return credits.get(code); }

    void load(CategorieManager cm);

    void ajouterCredit(QString code, int nombre,const Categorie* cat) { credits.ajouter(code, Credits(code, nombre,cat)); }
    void retirerCredit(QString code) { credits.retirer(code); }
};

#endif // CREDITMANAGER_H



