///
/// \file Credits.h
/// \brief Les UVs et les formations possèdent des crédits ECTS dans différentes catégories.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef CREDIT_H
#define CREDIT_H

#include <iostream>
#include <QString>
#include "Categorie.h"

///
/// \class Credits
/// \brief Les Credits associent à un nombre de crédits,une catégorie.
///
class Credits
{
    QString nom;
    int nombre;
    const Categorie* categorie;

public :
    ///
    /// \fn Credits(const QString c, int n, const Categorie& c)
    /// \brief Constructeur de la classe Credits.
    /// \brief Tous les parametres peuvent ne pas être donnée pour rendre ce constructeur, constructeur par défault
    /// \param n Le nom des crédits pour identification ultérieure.
    /// \param nb Le nombre de credits.
    /// \param cat Une référence d'une Categorie.
    ///
    Credits(const QString& n = "", int nb = 0, const Categorie& c = Categorie()): nom(n), nombre(nb), categorie(&c) {}

    ///
    /// \fn getNom()
    /// \brief Retourne une référence vers le nom des crédits.
    /// \return const QString& -> Le nom.
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom(const QString& n)
    /// \param n Le nouveau nom des crédits
    /// \brief Modifie le nom des crédits.
    ///
    void setNom(const QString& n) { nom = n; }

    ///
    /// \fn getNombre()
    /// \brief Retourne le nombre de crédits.
    /// \return int -> Le nombre.
    ///
    int getNombre() const { return nombre; }

    ///
    /// \fn setNombre(int nb)
    /// \brief Modifie le nombre des crédits
    /// \param nb Le nouveau nombre de crédits
    ///
    void setNombre(int nb) { nombre = nb; }

    ///
    /// \fn getCategorie()
    /// \brief Retourne une référence constante de la catégorie.
    /// \return const Categorie& La catégorie.
    ///
    const Categorie& getCategorie() const { return *categorie; }

    ///
    /// \fn setCategorie(const Categorie& c)
    /// \brief Remplace la référénce de categorie par la nouvelle.
    /// \param c La nouvelle référence sur categorie
    ///
    void setCategorie(const Categorie& c) { categorie = &c; }
};

#endif // CREDIT_H
