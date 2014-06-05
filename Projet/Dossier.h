///
/// \file Dossier.h
/// \brief Un dossier représente le parcours d'un étudiant
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
    std::map<QString,const Formation*> formation;
    std::map<QString,const Inscription*> inscription;


public :
    ///
    /// \fn Dossier
    /// \param n Nom de l'étudiant
    /// \param p Prenom de l'étudiant
    /// \brief La fonction calcule automatiquement le login de l'étudiant
    ///
    Dossier(QString n, QString p): nom(n), prenom(p), formation(std::map<QString,const Formation*>()), inscription(std::map<QString,const Inscription*>()) {
        setLogin();
    }

    ~Dossier(){}

    ///
    /// \fn getNom
    /// \return string Nom de l'étudiant
    ///
    const QString& getNom() const { return nom; }

    void setNom(const QString& n) { nom = n; }

    ///
    /// \fn getPrenom
    /// \return string Prenom de l'étudiant
    ///
    const QString& getPrenom() const { return prenom; }

    void setPrenom(const QString& p) { prenom = p; }

    ///
    /// \fn getLogin
    /// \return string Login de l'étudiant
    ///
    const QString& getLogin() const { return login; }



    void setLogin();

    void ajoutFormation(const Formation& f);
    void retireFormation(QString code) { formation.erase(code); }

    void ajoutInscription(const Inscription& f);
    void retireInscription(QString code) { inscription.erase(code); }

    ///
    /// \fn affichage
    /// \brief Simple fonction d'affichage
    ///
    void affichage();
};

#endif // DOSSIER_H
