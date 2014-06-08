///
/// \file Dossier.h
/// \brief Un dossier représente le parcours d'un étudiant.
/// \author Nicolas Szewe, Erwan Normand
/// \date 02 juin 2014
///

#ifndef DOSSIER_H
#define DOSSIER_H

#include <QString>
#include <vector>
#include <algorithm>
#include "Formation.h"
#include "Inscription.h"

class Dossier
{
private:
    QString nom;
    QString prenom;
    QString login;
    std::vector<const Formation*> formations;
    std::vector<const Inscription*> inscriptions;

    void setLogin();

public :
    ///
    /// \fn Dossier
    /// \param n Nom de l'étudiant
    /// \param p Prenom de l'étudiant
    /// \brief La fonction calcule automatiquement le login de l'étudiant
    ///
    Dossier(const QString& n = "", const QString& p = ""): nom(n), prenom(p), formations(), inscriptions() {
        setLogin();
    }

    ~Dossier() {}

    ///
    /// \fn getNom
    /// \return string Nom de l'étudiant
    ///
    const QString& getNom() const { return nom; }

    void setNom(const QString& n) { nom = n; setLogin(); }

    ///
    /// \fn getPrenom
    /// \return string Prenom de l'étudiant
    ///
    const QString& getPrenom() const { return prenom; }

    void setPrenom(const QString& p) { prenom = p; setLogin(); }

    const std::vector<const Formation*>& getFormations() const { return formations; }

    const std::vector<const Inscription*>& getInscriptions() const { return inscriptions; }


    ///
    /// \fn getLogin
    /// \return string Login de l'étudiant
    ///
    const QString& getLogin() const { return login; }

    void ajouterFormation(const Formation& f) { formations.push_back(&f); }
    void retirerFormation(const Formation& f) { formations.erase(remove(formations.begin(), formations.end(), &f), formations.end()); }

    void ajouterInscription(const Inscription& i) { inscriptions.push_back(&i); }
    void retirerInscription(const Inscription& i) { inscriptions.erase(remove(inscriptions.begin(), inscriptions.end(), &i), inscriptions.end()); }

    ///
    /// \fn affichage
    /// \brief Simple fonction d'affichage
    ///
    void afficher();
};

#endif // DOSSIER_H
