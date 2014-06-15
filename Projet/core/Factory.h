///
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

///
/// \class Factory
/// \brief Simplifie l'utilisation des maps. Design pattern Factory
///
class Factory
{
private:
    std::map<QString,T> tab;

public:
    ///
    /// \class Factory
    /// \brief Constructeur de l'objet factory. Initialisation de la map
    ///
    Factory(): tab() {}

    ///
    /// \fn get
    /// \brief Pour récupérer l'élement dans la map
    /// \param code Code de l'objet a recuperer. (key)
    /// \return T& Reference vers l'objet de type T
    ///
    T& get(const QString& code);

    ///
    /// \fn get
    /// \brief Pour récupérer l'élement dans la map
    /// \param code Code de l'objet a recuperer. (key)
    /// \return const T& Reference vers l'objet de type T
    ///
    const T& get(const QString& code) const;

    ///
    /// \fn begin
    /// \brief Permet d'obtenir un itérateur sur le premier element de la map
    /// \return typename std::map<QString,T>::const_iterator Iterateur constant
    ///
    typename std::map<QString,T>::const_iterator begin() const { return tab.begin(); }

    ///
    /// \fn end
    /// \brief Permet d'obtenir un itérateur sur le dernier element de la map
    /// \return typename std::map<QString,T>::const_iterator Iterateur constant
    ///
    typename std::map<QString,T>::const_iterator end() const { return tab.end(); }

    ///
    /// \fn begin
    /// \brief Permet d'obtenir un itérateur sur le premier element de la map
    /// \return typename std::map<QString,T>::iterator Iterateur
    ///
    typename std::map<QString,T>::iterator begin() { return tab.begin(); }

    ///
    /// \fn end
    /// \brief Permet d'obtenir un itérateur sur le dernier element de la map
    /// \return typename std::map<QString,T>::iterator Iterateur
    ///
    typename std::map<QString,T>::iterator end() { return tab.end(); }

    ///
    /// \fn ajouter
    /// \brief Pour ajouter un element a une map
    /// \param code Code de l'objet (key)
    /// \param t Objet de type T
    ///
    void ajouter(const QString& code, const T& t = T()) { tab[code] = t; }

    ///
    /// \fn retirer
    /// \brief Pour retirer un element a une map
    /// \param code Code de l'objet a retirer (key)
    ///
    void retirer(const QString& code) { tab.erase(code); }

    ///
    /// \fn estVide
    /// \brief Teste si la map est vide
    /// \return bool
    ///
    bool estVide() const { return tab.size() == 0; }

    ///
    /// \fn vider
    /// \brief Vide la map
    ///
    void vider() { tab.clear(); }

    ///
    /// \fn renommer
    /// \brief pour modifier la clé d'un element de la map
    /// \param code Ancien clé de l'element
    /// \param nouveau_code Nouvelle clé de l'element
    ///
    void renomer(const QString& code, const QString& nouveau_code);
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
