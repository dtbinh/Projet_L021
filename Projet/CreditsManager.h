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
#include "Manager.h"
#include "CategorieManager.h"
#include "Categorie.h"
#include "Credits.h"

class CreditsManager
{
private:
    Manager<Credits> credits;

public:
    CreditsManager(): credits() {}

    void load(const CategorieManager& catman);

    Credits& getCredits(const QString& code) { return credits.get(code); }
    const Credits& getCredits(const QString& code) const { return credits.get(code); }
    void ajouterCredits(const QString& code, int nombre, const Categorie& cat) { credits.ajouter(code, Credits(code, nombre, cat)); }
    void retirerCredits(const QString& code) { credits.retirer(code); }
};

#endif // CREDITMANAGER_H
