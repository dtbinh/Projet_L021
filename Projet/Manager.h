///
/// \file Manager.h
/// \brief Class template model of all the Managers
/// \author Erwan Normand
/// \date 02 juin 2014
///

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <map>
#include <algorithm>
#include "Categorie.h"

template<class T>
class Manager
{
private:
    std::map<std::string,T> tab;

public:
    Manager(): tab(std::map<std::string,T>()) {}

    const T& get(const std::string code) const { return tab.find(code)->second; }

    void ajouter(std::string code, const T& t) { tab[code] = t; }
    void retirer(std::string code) { tab.erase(code); }
};

#endif // MANAGER_H
