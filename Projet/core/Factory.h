﻿///
/// \file Factory.h
/// \brief Classe template pour gérer les objets.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef FACTORY_H
#define FACTORY_H

#include <QString>
#include <map>
#include <algorithm>
#include "Exception.h"

template<class T>
class Factory
{
private:
    std::map<QString,T> tab;

public:
    Factory(): tab() {}

    T& get(const QString& code);
    const T& get(const QString& code) const;

    typename std::map<QString,T>::const_iterator begin() const { return tab.begin(); }
    typename std::map<QString,T>::const_iterator end() const { return tab.end(); }
    typename std::map<QString,T>::iterator begin() { return tab.begin(); }
    typename std::map<QString,T>::iterator end() { return tab.end(); }

    void ajouter(const QString& code, const T& t = T()) { tab[code] = t; }
    void retirer(const QString& code) { tab.erase(code); }
    void renomer(const QString& code, const QString& nouveau_code);

    bool estVide() const { return tab.size() == 0; }
    void vider() { tab.clear(); }
};

template<class T>
T& Factory<T>::get(const QString& code)
{
    typename std::map<QString,T>::iterator it = tab.find(code);
    if (it == tab.end()) {
        throw Exception("L'objet " + code + " n'existe pas.");
    }
    return it->second;
}

template<class T>
const T& Factory<T>::get(const QString& code) const
{
    typename std::map<QString,T>::const_iterator it = tab.find(code);
    if (it == tab.end()) {
        throw Exception("L'objet " + code + " n'existe pas.");
    }
    return it->second;
}

template<class T>
void Factory<T>::renomer(const QString& code, const QString& nouveau_code)
{
    ajouter(nouveau_code, get(code));
    retirer(code);
}

#endif // FACTORY_H
