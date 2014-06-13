///
/// \file CategorieManager.h
/// \brief Manager des Categories.
/// \author Erwan Normand
/// \date 05 juin 2014
///

#ifndef CATEGORIEMANAGER_H
#define CATEGORIEMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Categorie.h"

class CategorieManager : public Manager
{
private:
    Factory<Categorie> categories;
    //class iterator;

public:
    CategorieManager(const QString& cf = "",const QString& f = ""): Manager(cf, f), categories() {}

    void charger();
    void sauvegarder();

    bool estVide() const { return categories.estVide(); }
    void vider() { categories.vider(); }

    Categorie& getCategorie(const QString& code) { return categories.get(code); }
    const Categorie& getCategorie(const QString& code) const { return categories.get(code); }
    void ajouterCategorie(const QString& code, const QString& nom) { categories.ajouter(code, Categorie(code, nom)); }
    void retirerCategorie(const QString& code) { categories.retirer(code); }
};


/*class CategorieManager::iterator
{
private:
    Factory<Categorie>* categories;
    Categorie* index;

    iterator(Categorie* i, Factory<Categorie>* cat): index(i), categories(cat) {}
    friend class CategorieManager;

public:
    iterator(): index(), categories() {}

    Categorie operator*() { return *index; }*/
};

#endif // CATEGORIEMANAGER_H
