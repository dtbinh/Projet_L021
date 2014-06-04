///
/// \file CategorieManager.h
/// \brief Manager des Categories
/// \author Erwan Normand
/// \date 01 juin 2014
///

#ifndef CATEGORIEMANAGER_H
#define CATEGORIEMANAGER_H

#include <QString>
#include <map>
#include <algorithm>
#include "Manager.h"
#include "Categorie.h"

class CategorieManager
{

private:
    Manager<Categorie> categories;

public:
    CategorieManager(): categories() {}

    Categorie* getCategorie(const QString code)  { return &categories.get(code); }

    void load();

    void ajouterCategorie(QString code, QString nom) { categories.ajouter(code, Categorie(code, nom)); }
    void retirerCategorie(QString code) { categories.retirer(code); }
};

#endif // CATEGORIEMANAGER_H


