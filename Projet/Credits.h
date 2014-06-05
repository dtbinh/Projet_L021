///
/// \file Credits.h
/// \brief Les catégories de l'UTC possèdent des crédits.
/// \author Nicolas Szewe, Erwan Normand
/// \date 05 juin 2014
///

#ifndef CREDIT_H
#define CREDIT_H

#include <iostream>
#include <QString>
#include "Categorie.h"

///
/// \class Credits
/// \brief Credits correspond à un nombre de crédits dans une catégorie.
///
class Credits
{
    QString nom;
    int nombre;
    const Categorie* categorie;

public :
    ///
    /// \fn Credits(const QString c, int n, const Categorie& c)
    /// \brief Constructeur.
    /// \param n Le nombre de crédits.
    /// \param cat Une référence d'une Categorie.
    ///
    Credits(const QString& n = "", int nb = 0, const Categorie& c = Categorie()): nom(n), nombre(nb), categorie(&c) {}

    ///
    /// \fn setNom()
    /// \brief Retourne le nom des crédits.
    /// \return const QString& Le nom.
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom(const QString& n)
    /// \brief Modifie le nom des crédits.
    ///
    void setNom(const QString& n) { nom = n; }

    ///
    /// \fn getNombre()
    /// \brief Retourne le nombre de crédits.
    /// \return int Le nombre.
    ///
    int getNombre() const { return nombre; }

    ///
    /// \fn setNombre(int nb)
    /// \brief Modifie le nombre des crédits.
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
    /// \brief Modifie la catégorie des crédits.
    ///
    void setCategorie(const Categorie& c) { categorie = &c; }

    void afficher() const { std::cout << nom.toStdString() << " : " << nombre << " " << categorie->getCode().toStdString() << std::endl; }
};

#endif // CREDIT_H
