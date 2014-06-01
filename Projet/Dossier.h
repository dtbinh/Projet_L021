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
    Dossier(string n,string p):nom(n),prenom(p),formation(vector<const Formation*>()),inscription(vector<const Inscription*>()){
        if(nom.size()>=7){
            login=prenom.at(0);
            for(int j=0;j<7;j++)
                login=login+nom.at(j);
        }
        else if((nom.size()+prenom.size())>=8) {
            login=nom;
            for (unsigned int i=0;i<8-nom.size();i++)
                login=login+prenom.at(i);
            }
        else
            login=nom+prenom;
    }

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
    void affichageDossier();

    void ajoutFormation(const Formation& f){ formation.push_back(&f); }
    void retireFormation(const Formation& f) { if (formation.empty()) throw Exception("Objets vide, suppression impossible");
        else formation.erase(remove(formation.begin(), formation.end(), &f), formation.end()); }

    void ajoutInscription(const Inscription& f){ inscription.push_back(&f); }
    void retireInscription(const Inscription& f) { if (inscription.empty()) throw Exception("Objets vide, suppression impossible");
        else inscription.erase(remove(inscription.begin(), inscription.end(), &f), inscription.end()); }
};

#endif // DOSSIER_H
