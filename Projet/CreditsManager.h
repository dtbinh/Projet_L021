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
#include "Factory.h"
#include "CategorieManager.h"
#include "Categorie.h"
#include "Credits.h"

class CreditsManager : public Manager
{
private:
    Factory<Credits> credits;

public:
    CreditsManager(const QString& f = ""): Manager(f), credits() {}

    void load(const CategorieManager& catman);
    void save();

    Credits& getCredits(const QString& code) { return credits.get(code); }
    const Credits& getCredits(const QString& code) const { return credits.get(code); }
    void ajouterCredits(const QString& code, int nombre, const Categorie& cat) { credits.ajouter(code, Credits(code, nombre, cat)); }
    void retirerCredits(const QString& code) { credits.retirer(code); }
};

#endif // CREDITMANAGER_H
