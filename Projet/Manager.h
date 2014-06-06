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

    T& get(const QString& code) { return tab.find(code)->second; }
    const T& get(const QString& code) const { return tab.find(code)->second; }

    void ajouter(const QString& code, const T& t) { tab[code] = t; }
    void retirer(const QString& code) { tab.erase(code); }
};

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
