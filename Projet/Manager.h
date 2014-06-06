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
#include "Exception.h"

template<class T>
class Manager
{
private:
    std::map<QString,T> tab;

public:
    Manager(): tab() {}

    QDomDocument load_xml(const QString& file);

    T& get(const QString& code);
    const T& get(const QString& code) const;

    void ajouter(const QString& code, const T& t) { tab[code] = t; }
    void retirer(const QString& code) { tab.erase(code); }
};

template<class T>
T& Manager<T>::get(const QString& code)
{
    typename std::map<QString,T>::iterator it = tab.find(code);
    if (it == tab.end()) {
        throw Exception("L'objet " + code + " n'existe pas.");
    }
    return it->second;
}

template<class T>
const T& Manager<T>::get(const QString& code) const
{
    typename std::map<QString,T>::const_iterator it = tab.find(code);
    if (it == tab.end()) {
        throw Exception("L'objet " + code + " n'existe pas.");
    }
    return it->second;
}

template<class T>
QDomDocument Manager<T>::load_xml(const QString& file)
{
    QFile fichier(file);
    if (!fichier.open(QFile::ReadOnly | QFile::Text)) {
        throw Exception("Impossible d'ouvrir le fichier.");
    }

    QDomDocument doc;
    doc.setContent(&fichier, false);

    return doc;
}

#endif // MANAGER_H
