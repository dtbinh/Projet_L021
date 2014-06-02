///
/// \file Dossier.h
/// \brief Un dossier représente le parcours d'un étudiant
/// \author Nicolas Szewe
/// \version 0.1
/// \date 27 mai 2014
///

#ifndef DOSSIER_H
#define DOSSIER_H

#include "Formation.h"
#include "Inscription.h"

using namespace std;

class Dossier{
private:
    string nom;
    string prenom;
    string login;
    vector<const Formation*> formation;
    vector<const Inscription*> inscription;
public :
    ///
    /// \fn Dossier
    /// \param n Nom de l'étudiant
    /// \param p Prenom de l'étudiant
    /// \brief La fonction calcule automatiquement le login de l'étudiant
    ///
    Dossier(string n,string p);
    ///
    /// \fn getNom
    /// \return string Nom de l'étudiant
    ///
    string getNom() const {return nom;}

    ///
    /// \fn getPrenom
    /// \return string Prenom de l'étudiant
    ///
    string getPrenom() const {return prenom;}

    ///
    /// \fn getLogin
    /// \return string Login de l'étudiant
    ///
    string getLogin() const {return login;}

    ~Dossier(){}

    ///
    /// \fn affichage
    /// \brief Simple fonction d'affichage
    ///
    void affichage();

    void ajoutFormation(const Formation& f){ formation.push_back(&f); }
    void retireFormation(const Formation& f) { if (formation.empty()) throw Exception("Objets vide, suppression impossible");
        else formation.erase(remove(formation.begin(), formation.end(), &f), formation.end()); }

    void ajoutInscription(const Inscription& f){ inscription.push_back(&f); }
    void retireInscription(const Inscription& f) { if (inscription.empty()) throw Exception("Objets vide, suppression impossible");
        else inscription.erase(remove(inscription.begin(), inscription.end(), &f), inscription.end()); }
};

#endif // DOSSIER_H
