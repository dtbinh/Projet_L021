///
/// \file Credits.h
/// \brief Les UVs et les formations possèdent des crédits ECTS dans différentes catégories. Les crédits des formations sont à valider, ceux des UVs en rapportent.
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
    QString code;
    int nombre;
    const Categorie* categorie;

public :
    ///
    /// \fn Credits(const QString c, int n, const Categorie& c)
    /// \brief Constructeur.
    /// \param nb Le nombre de crédits.
    /// \param cat Une référence d'une Categorie.
    ///
    Credits(const QString& c = "", int nb = 0, const Categorie& cat = Categorie()): code(c), nombre(nb), categorie(&cat) {}

    ///
    /// \fn setNom()
    /// \brief Retourne le nom des crédits.
    /// \return const QString& Le nom.
    ///
    const QString& getCode() const { return code; }

    ///
    /// \fn setNom(const QString& n)
    /// \brief Modifie le nom des crédits.
    ///
    void setCode(const QString& n) { code = n; }

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
};

#endif // CREDIT_H
