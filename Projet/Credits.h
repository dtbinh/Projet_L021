///
/// \file Credits.h
/// \brief Les UVs de l'UTC possédents des crédits. Permet de décrire le nombre de crédit associé à une catégorie.
/// \author Nicolas Szewe, Erwan Normand
/// \version 0.1
/// \date 27 mai 2014
///

#ifndef CREDIT_H
#define CREDIT_H

#include "Categorie.h"

class Credits {
    std::string code;
    int nombre;
    const Categorie& cat;
public :
    ///
    /// \fn Credits(int n,Categorie& categ)
    /// \param n Le nombre de credits
    /// \param categ Une reférence vers un objet catégorie
    /// \brief Constructeur nécessitant le nombre de crédits et la catégorie de ces crédits.
    ///
    Credits(const std::string& c, int n, const Categorie& categ): code(c), nombre(n), cat(categ) {}

    ///
    /// \fn getCode()
    /// \return string code
    ///
    const std::string& getCode() const { return code; }

    ///
    /// \fn getNombre()
    /// \return int nombre de crédits
    ///
    int getNombre() const { return nombre; }

    ///
    /// \fn getCategorie
    /// \return const Categorie& référence vers la catégorie
    ///
    const Categorie& getCategorie() const { return cat; }
};

#endif // CREDIT_H
