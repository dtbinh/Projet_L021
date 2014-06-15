///
/// \file UV.h
/// \brief Les UVs sont les matières de l'UTC.
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef UV_PROFIL_H
#define UV_PROFIL_H

#include <QString>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Categorie.h"
#include "Credits.h"

///
/// \class UV
/// \brief Une UV est un enseignment. Il posséde une catégorie et un ou plusieurs types de crédits.
///
class UV
{
private :
    QString code, nom;
    const Categorie* categorie;
    std::vector<const Credits*> cred;

public:
    ///
    /// \fn UV
    /// \param c Le code d'une UV
    /// \param n le nom d'une UV
    /// \param categ Reference sur une categorie déja existante
    /// \brief Le constructeur d'une UV. Il initialise un vecteur pour les crédits d'une UV
    ///
    UV(const QString& c = "", const QString& n = "", const Categorie& cat = Categorie())
        : code(c), nom(n), categorie(&cat), cred() {}

    ///
    /// \fn UV
    /// \param u Une référence vers l'UV à copier
    /// \brief Constructeur de recopie de la classe UV
    ///
    UV(const UV& u);

    ///
    /// \fn getCode
    /// \brief Pour acceder au code d'une UV
    /// \return const QString& -> Le code de l'UV
    ///
    const QString& getCode() const { return code; }

    ///
    /// \fn setCode
    /// \param c Le nouveau code pour l'UV
    /// \brief Fonction pour modifier le code d'une uv
    ///
    void setCode(const QString& c) { code = c; }

    ///
    /// \fn getNom
    /// \brief Pour acceder au nom d'une UV
    /// \return const QString& -> Le nom de l'UV
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom
    /// \param c Le nouveau nom pour l'UV
    /// \brief Fonction pour modifier le nom d'une uv
    ///
    void setNom(const QString& n) { nom = n; }

    ///
    /// \fn getCategorie
    /// \brief Pour acceder à la catégorie d'une UV
    /// \return const Categorie& -> Référence vers la categorie auquel appartient l'UV
    ///
    const Categorie& getCategorie() const { return *categorie; }

    ///
    /// \fn setCategorie(const Categorie& cat)
    /// \param cat Référence vers une categorie existante qui sera la nouvelle categorie pour l'UV
    /// \brief Modifie la catégorie de l'UV.
    ///
    void setCategorie(const Categorie& cat) { categorie = &cat; }

    ///
    /// \fn getCredits
    /// \brief Retourne les différents crédits que possédent l'UV
    /// \return const std::vector<const Credits*>& -> L'ensemble des crédits que possédent une UV
    ///
    const std::vector<const Credits*>& getCredits() const { return cred; }

    ///
    /// \fn ajoutCredits
    /// \param c Une référence sur un objet de la classe crédit déja existant.
    /// \brief Ajoute des crédits à l'ensemble des crédits de l'UV
    ///
    void ajoutCredits(const Credits& c) { cred.push_back(&c); }

    ///
    /// \fn retireCredits
    /// \param c Une rérence sur un objet de la classe crédit déja existant.
    /// \brief Retire des crédits à l'ensemble des crédits d'une UV
    ///
    void retireCredits(const Credits& c) { cred.erase(remove(cred.begin(), cred.end(), &c), cred.end()); }
};

#endif // UV_PROFIL_H
