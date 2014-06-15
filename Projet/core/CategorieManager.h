///
/// \file CategorieManager.h
/// \brief Manager des Categories.
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef CATEGORIEMANAGER_H
#define CATEGORIEMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Observer.h"
#include "Categorie.h"

class CategorieManager : public Manager
{
private:
    Factory<Categorie> categories;

public:
    CategorieManager(const QString& cf = "",const QString& f = ""): Manager(cf, f), categories() {}

    void charger();
    void sauvegarder();

    bool estVide() const { return categories.estVide(); }
    void vider() { categories.vider(); }

    const Factory<Categorie>& getCategories() const { return categories; }
    Categorie& getCategorie(const QString& code) { return categories.get(code); }
    const Categorie& getCategorie(const QString& code) const { return categories.get(code); }
    void ajouterCategorie(const QString& code, const QString& nom);
    void retirerCategorie(const QString& code) { categories.retirer(code); }
    //void renomerCategorie(const QString& code, const QString& nouveau_code);
};

#endif // CATEGORIEMANAGER_H
