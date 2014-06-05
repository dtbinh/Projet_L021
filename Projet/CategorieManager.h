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
#include <fstream>
#include "AbstractManager.h"
#include "Manager.h"
#include "Categorie.h"

class CategorieManager : public AbstractManager
{
private:
    Manager<Categorie> categories;

public:
    CategorieManager(): categories(Manager<Categorie>()) {}

    void load();

    const Categorie& getCategorie(const QString& code) const { return categories.get(code); }
    void ajouterCategorie(const QString& code, const QString& nom) { categories.ajouter(code, Categorie(code, nom)); }
    void retirerCategorie(const QString& code) { categories.retirer(code); }
};

#endif // CATEGORIEMANAGER_H


