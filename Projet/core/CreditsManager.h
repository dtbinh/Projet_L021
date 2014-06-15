///
/// \file CreditManager.h
/// \brief Manager des Credits.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
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
    CreditsManager(const QString& cf = "",const QString& f = ""): Manager(cf, f), credits() {}

    void charger(const CategorieManager& catman);
    void sauvegarder();

    bool estVide() const { return credits.estVide(); }
    void vider() { credits.vider(); }

    const Factory<Credits>& getCredits() const { return credits; }
    Credits& getCredits(const QString& code) { return credits.get(code); }
    const Credits& getCredits(const QString& code) const { return credits.get(code); }
    void ajouterCredits(const QString& code, int nombre, const Categorie& cat) { credits.ajouter(code, Credits(code, nombre, cat)); }
    void retirerCredits(const QString& code) { credits.retirer(code); }
};

#endif // CREDITMANAGER_H
