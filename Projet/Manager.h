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
    std::map<QString,T> tab;

public:
    Manager(): tab(std::map<QString,T>()) {}

    T& get(const QString code) { return tab.find(code)->second; }

    void ajouter(QString code, const T& t) { tab[code] = t; }
    void retirer(QString code) { tab.erase(code); }
};

#endif // MANAGER_H
