///
/// \file Credits.h
/// \brief Les UVs de l'UTC possédents des crédits. Permet de décrire le nombre de crédit associé à une catégorie.
/// \author Nicolas Szewe, Erwan Normand
/// \date 27 mai 2014
///

#ifndef CREDIT_H
#define CREDIT_H

#include <QString>
#include "Categorie.h"

class Credits
{
    QString code;
    int nombre;
    const Categorie& categorie;

public :
    ///
    /// \fn Credits(int n,Categorie& categ)
    /// \param n Le nombre de credits
    /// \param categ Une reférence vers un objet catégorie
    /// \brief Constructeur nécessitant le nombre de crédits et la catégorie de ces crédits.
    ///
    Credits(const QString& c, int n, const Categorie& cat): code(c), nombre(n), categorie(cat) {}

    ///
    /// \fn getCode()
    /// \return string code
    ///
    const QString& getCode() const { return code; }

    void setCode(const QString& c) { code = c; }

    ///
    /// \fn getNombre()
    /// \return int nombre de crédits
    ///
    int getNombre() const { return nombre; }

    void setNombre(int n) { nombre = n; }

    ///
    /// \fn getCategorie
    /// \return const Categorie& référence vers la catégorie
    ///
    const Categorie& getCategorie() const { return categorie; }

    //void setCategorie(const Categorie& c) { categorie = c; }
};

#endif // CREDIT_H
