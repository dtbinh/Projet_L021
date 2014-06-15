///
/// \file Categorie.h
/// \brief Les UVs de l'UTC sont décrites en catégories.
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <iostream>
#include <QString>

///
/// \class Categorie
/// \brief Categorie correspond à un nom et à un code comme identifiant.
///
class Categorie
{
private:
    QString code, nom;

public:
    ///
    /// \fn Categorie(const QString& c, const QString& n)
    /// \brief Constructeur
    /// \param c Le code de la Categorie a créer.
    /// \param n Le nom de la Categorie a créer.
    ///
    Categorie(const QString& c = "", const QString& n = ""): code(c), nom(n) {}

    ///
    /// \fn getCode()
    /// \brief Retourne une réference constante sur le code de la Categorie.
    /// \return const QString& -> Le code.
    ///
    const QString& getCode() const { return code; }

    ///
    /// \fn setCode(const QString& c)
    /// \param c Le nouveau code pour la Categorie
    /// \brief Modifie le code de la Categorie.
    ///
    void setCode(const QString& c) { code = c; }

    ///
    /// \fn getNom()
    /// \brief Retourne une référence constante sur le nom de la Categorie.
    /// \return const QString& -> Le nom.
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom(const QString& n)
    /// \param n Le nouveau nom de la Categorie
    /// \brief Modifie le nom de la Categorie.
    ///
    void setNom(const QString& n) { nom = n; }
};

#endif // CATEGORIE_H
