///
/// \file Dossier.h
/// \brief Un dossier représente le parcours d'un étudiant
/// \author Nicolas Szewe, Erwan Normand
/// \date 02 juin 2014
///

#ifndef DOSSIER_H
#define DOSSIER_H

#include <string>
#include <vector>
#include <algorithm>
#include "Formation.h"
#include "Inscription.h"

class Dossier
{
private:
    std::string nom;
    std::string prenom;
    std::string login;
    std::vector<const Formation*> formation;
    std::vector<const Inscription*> inscription;

public :
    ///
    /// \fn Dossier
    /// \param n Nom de l'étudiant
    /// \param p Prenom de l'étudiant
    /// \brief La fonction calcule automatiquement le login de l'étudiant
    ///
    Dossier(std::string n, std::string p): nom(n), prenom(p), formation(std::vector<const Formation*>()), inscription(std::vector<const Inscription*>()) {
        setLogin();
    }

    ~Dossier(){}

    ///
    /// \fn getNom
    /// \return string Nom de l'étudiant
    ///
    const std::string& getNom() const { return nom; }

    void setNom(const std::string& n) { nom = n; }

    ///
    /// \fn getPrenom
    /// \return string Prenom de l'étudiant
    ///
    const std::string& getPrenom() const { return prenom; }

    void setPrenom(const std::string& p) { prenom = p; }

    ///
    /// \fn getLogin
    /// \return string Login de l'étudiant
    ///
    const std::string& getLogin() const { return login; }

    void setLogin();

    void ajoutFormation(const Formation& f){ formation.push_back(&f); }
    void retireFormation(const Formation& f) { formation.erase(remove(formation.begin(), formation.end(), &f), formation.end()); }

    void ajoutInscription(const Inscription& f){ inscription.push_back(&f); }
    void retireInscription(const Inscription& f) { inscription.erase(remove(inscription.begin(), inscription.end(), &f), inscription.end()); }

    ///
    /// \fn affichage
    /// \brief Simple fonction d'affichage
    ///
    void affichage();
};

#endif // DOSSIER_H
