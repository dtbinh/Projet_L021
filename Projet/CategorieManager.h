///
/// \file CategorieManager.h
/// \brief Manager des Categories
/// \author Erwan Normand
/// \date 01 juin 2014
///

#ifndef CATEGORIEMANAGER_H
#define CATEGORIEMANAGER_H

#include <iostream>
#include <map>
#include <algorithm>
#include "Categorie.h"

class CategorieManager
{
private:
    map<std::string,Categorie> categories;

public:
    CategorieManager(): categories(map<std::string,Categorie>()) {}

    const Categorie& getCategorie(const std::string code) const { return categories.find(code)->second; }

    void ajouterCategorie(std::string code, std::string nom) { categories[code] = Categorie(code, nom); }
    void retirerCategorie(std::string code) { categories.erase(code); }
};

#endif // CATEGORIEMANAGER_H
