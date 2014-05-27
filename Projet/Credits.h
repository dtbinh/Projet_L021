///
/// \file Credits.h
/// \brief Les UVs de l'UTC possédents des crédits
/// \author Nicolas Szewe
/// \version 0.1
/// \date 27 mai 2014
///

#ifndef CREDIT_H
#define CREDIT_H

#include "Categorie.h"

class Credits { //Permet de Décrire le nombre de crédit associé à une catégorie
    int nombre;
    Categorie& cat;
public :
    ///
    /// \fn Credits(int n,Categorie& categ)
    /// \param n Le nombre de credits
    /// \param categ Une reférence vers un objet catégorie
    /// \brief Constructeur nécessitant le nombre de crédits et la catégorie de ces crédits.
    ///
    Credits(int n,Categorie& categ):nombre(n),cat(categ){}

    ///\fn getNombre()
    /// \return int nombre de crédits
    ///
    int getNombre() const {return nombre;}

    ///
    /// \fn getCategorie
    /// \return Categorie& référence vers la catégorie
    ///
    Categorie& getCategorie() const {return cat;}
};

#endif // CREDIT_H
