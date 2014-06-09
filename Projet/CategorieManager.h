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

public:
    CategorieManager(): categories() {}

    void load(const QString& fichier);
    void save(const QString& fichier);

    Categorie& getCategorie(const QString& code) { return categories.get(code); }
    const Categorie& getCategorie(const QString& code) const { return categories.get(code); }
    void ajouterCategorie(const QString& code, const QString& nom) { categories.ajouter(code, Categorie(code, nom)); }
    void retirerCategorie(const QString& code) { categories.retirer(code); }
};

#endif // CATEGORIEMANAGER_H
