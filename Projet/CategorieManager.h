///
/// \file CategorieManager.h
/// \brief Manager des Categories
/// \author Erwan Normand
/// \date 01 juin 2014
///

#ifndef CATEGORIEMANAGER_H
#define CATEGORIEMANAGER_H

#include <string>
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

    const Categorie& getCategorie(const std::string code) const { return categories.get(code); }

    void ajouterCategorie(std::string code, std::string nom) { categories.ajouter(code, Categorie(code, nom)); }
    void retirerCategorie(std::string code) { categories.retirer(code); }
};

#endif // CATEGORIEMANAGER_H


