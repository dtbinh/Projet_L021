///
/// \file Manager.h
/// \brief Classe template pour tous les managers d'objets.
/// \author Erwan Normand
/// \date 02 juin 2014
///

#ifndef MANAGER_H
#define MANAGER_H

#include <QtXml>
#include <map>
#include <algorithm>

template<class T>
class Manager
{
private:
    std::map<QString,T> tab;

public:
    Manager(): tab() {}

    const T& get(const QString code) const { return tab.find(code)->second; }
    void ajouter(QString code, const T& t) { tab[code] = t; }
    void retirer(QString code) { tab.erase(code); }
};

#endif // MANAGER_H
