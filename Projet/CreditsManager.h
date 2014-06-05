///
/// \file CreditManager.h
/// \brief Manager des Credits.
/// \author Nicolas Szewe, Erwan Normand
/// \date 04 juin 2014
///

#ifndef CREDITMANAGER_H
#define CREDITMANAGER_H

#include <QString>
#include <QtXml>
#include <fstream>
#include "AbstractManager.h"
#include "Manager.h"
#include "CategorieManager.h"
#include "Categorie.h"
#include "Credits.h"

class CreditManager : public AbstractManager
{
private:
    Manager<Credits> credits;

public:
    CreditManager(): credits() {}

    void load(const CategorieManager& catman);

    const Credits& getCredits(const QString& code) const { return credits.get(code); }
    void ajouterCredits(const QString& code, int nombre, const Categorie& cat) { credits.ajouter(code, Credits(code, nombre, cat)); }
    void retirerCredits(const QString& code) { credits.retirer(code); }
};

#endif // CREDITMANAGER_H



