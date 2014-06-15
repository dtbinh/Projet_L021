///
/// \file Formation.h
/// \brief Un etudiant peut suivre différentes formations.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "UV.h"
#include "Credits.h"

///
/// \class Formation
/// \brief Une formation est un ensemble d'UV et un ensemble de crédits. Une formation a aussi des spécialités qui sont elles mêmes des formations.
///
class Formation
{
private:
    QString code;
    QString nom;
    std::vector<const Credits*> credits;
    std::vector<const Formation*> specialites;
    std::vector<const UV*> uvs;

public:
    ///
    /// \fn Formation
    /// \brief Constructeur de Formation. Initialise les vecteurs à 0 et crée le code et le nom de la Formation.
    /// \param c Code de la formation
    /// \param n Nom de la formation
    ///
    Formation(const QString& c = "", const QString& n = "") : code(c), nom(n), credits(), specialites(), uvs() {}

    ///
    /// \fn getCode
    /// \brief Methode pour acceder au code d'une formation
    /// \return const QString& -> Reference sur le code de la formation
    ///
    const QString& getCode() const { return code; }

    ///
    /// \fn setCode
    /// \brief Methode pour modifier le code d'une formation
    /// \param c Nouveau code de la formation
    ///
    void setCode(const QString& c) { code = c; }

    ///
    /// \fn getNom
    /// \brief Methode pour acceder au nom d'une formation
    /// \return const QString& -> Reference sur le nom de la formation
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom
    /// \brief Methode pour modifier le nom d'une formation
    /// \param n Nouveau nom de la formation
    ///
    void setNom(const QString& n) { nom = n; }

    ///
    /// \fn getCredits
    /// \brief Methode pour acceder aux vecteurs de crédits d'une formation
    /// \return const std::vector<const Credits*>& -> Référence sur l'ensemble des credits de la formation
    ///
    const std::vector<const Credits*>& getCredits() const { return credits; }

    ///
    /// \fn ajouterCredits
    /// \brief Methode pour ajouter des crédits à l'ensemble des crédits d'une formation
    /// \param c Référence vers un type de crédits déja définit
    ///
    void ajouterCredits(const Credits& c) { credits.push_back(&c); }

    ///
    /// \fn retirerCredits
    /// \brief Methode pour retire un type de crédits de l'ensemble des crédits de la formation
    /// \param c Reférence vers un type de crédits déja définit
    ///
    void retirerCredits(const Credits& c) { credits.erase(remove(credits.begin(), credits.end(), &c), credits.end()); }

    ///
    /// \fn getSpecialites
    /// \brief Methode pour acceder aux vecteurs de spécialites d'une formation. Une spécialité est elle meme une formation. (EX : MPI, FDD)
    /// \return const std::vector<const Formation*>& -> Référence sur l'ensemble des specialites (formation) de la formation
    ///
    const std::vector<const Formation*>& getSpecialites() const { return specialites; }

    ///
    /// \fn ajouterSpecialite
    /// \brief Methode pour ajouter une specialite à l'ensemble des specialites d'une formation
    /// \param f Référence vers un type de formation déja existant
    ///
    void ajouterSpecialite(const Formation& f) { specialites.push_back(&f); }

    ///
    /// \fn retirerSpecialite
    /// \brief Methode pour retire une formations de l'ensemble des specialites de la formation
    /// \param f Reférence vers un type de formation déja existant
    ///
    void retirerSpecialite(const Formation& f) { specialites.erase(remove(specialites.begin(), specialites.end(), &f), specialites.end()); }

    ///
    /// \fn getUVs
    /// \brief Methode pour acceder aux vecteurs d'uvs d'une formation.
    /// \return const std::vector<const UV*>& -> Référence sur l'ensemble des uvs de la formation
    ///
    const std::vector<const UV*>& getUVs() const { return uvs; }

    ///
    /// \fn ajouterUV
    /// \brief Methode pour ajouter une uv à l'ensemble des uvs d'une formation
    /// \param u Référence vers une uv déja existante
    ///
    void ajouterUV(const UV& u) { uvs.push_back(&u); }

    ///
    /// \fn retirerUV
    /// \brief Methode pour retire une UV de l'ensemble des UV de la formation
    /// \param u Reférence vers une UV déja existante
    ///
    void retirerUV(const UV& u) { uvs.erase(remove(uvs.begin(), uvs.end(), &u), uvs.end()); }
};

#endif // FORMATION_H
