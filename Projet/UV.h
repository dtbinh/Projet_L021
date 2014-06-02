///
/// \file UV.h
/// \brief Classe décrivant les matières de l'UTC
/// \author Nicolas Szewe
/// \version 0.1
/// \date 27 mai 2014
///

#ifndef UV_PROFIL_H
#define UV_PROFIL_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Categorie.h"
#include "Credits.h"
#include "Exception.h"

///
/// \enum Choix
/// \brief Différents choix pour une complétion
///
enum Choix {
    Confirmer,Refuser,Retarder,Avancer
};

///
/// \enum Note
/// \brief Les différentes notes que peuvent obtenir les étudiants pour une UV
///
enum Note {
    A,B,C,D,E,F,FX,RES,ABS,EC
};

///
/// \enum Preference
/// \brief Un étudiant peut donner une préférence quand à la volonté de faire une UV ou non
///
enum Preference{
    Exigence,Refus,NSP
};

class UV
{
private:
    std::string code,nom,description;
    Categorie cat;
    std::vector<const Credits*> cred; // Une UV peut avoir plusieurs types de crédits, il faut donc faire un tableau alloué dynamiquement
    std::vector<const UV*> prerequis; // On peut avoir plusieurs prérequis, il faut faire un tableau de pointeurs
public:
    ///
    /// \fn UV(const string& c,const string& n, const string& d,const Categorie& categ)
    /// \param c Le code d'une UV
    /// \param n le nom d'une UV
    /// \param d La description d'une UV
    /// \param categ La catégorie de l'UV
    /// \brief Le constructeur initialise un vecteur pour les crédits et les prérequis d'une UV
    ///
    UV(const std::string& c="",const std::string& n="", const std::string& d="",const Categorie& categ=Categorie())
    : code(c), nom(n),description(d),cat(categ),cred(std::vector<const Credits*>()),prerequis(std::vector<const UV*>()) {}

    ///
    /// \fn UV(const UV& u)
    /// \param u Une référence vers l'UV à copier
    /// \brief Constructeur de recopie de la classe UV
    ///
    UV(const UV& u);

    ///
    /// \fn getCode
    /// \return string Le code de l'UV
    ///
    const std::string& getCode() const {return code;}

    ///
    /// \fn getNom
    /// \return string Le nom de l'UV
    ///
    const std::string& getNom() const {return nom;}

    ///
    /// \fn setCode
    /// \param c Le nouveau code pour l'UV
    /// \brief Fonction pour modifier le code d'une uv
    ///
    void setCode(std::string c){code=c;}

    ///
    /// \fn getDescription
    /// \return string La description de l'UV
    ///
    const std::string& getDescription() const {return description;}

    ///
    /// \fn getCat
    /// \return Categorie La categorie auquel appartient l'UV
    ///
    const Categorie& getCat() const {return cat;}

    ///
    /// \fn getCredits
    /// \return Les différents crédits que possédent l'UV
    ///
    const std::vector<const Credits*>& getCredits() const { return cred; }

    ///
    /// \fn getPrerequis
    /// \return Les différents prérequis que possédent l'UV
    ///
    const std::vector<const UV*>& getPrerequis() const { return prerequis ; }

    ///
    /// \fn ajoutPrerequis
    /// \param u Une référence sur l'UV a ajouter en prérequis
    /// \brief Un simple push_back dans le conteneur vecteur Prerequis pour ajouter l'UV dans les prérequis
    ///
    void ajoutPrerequis(const UV& u){ prerequis.push_back(&u); }

    ///
    /// \fn retirePrerequis
    /// \param u Une référence sur l'UV a retirer en prérequis
    /// \brief Utilise remove sur le conteneur vecteur prerequis pour retirer l'uv des prérequis
    ///
    void retirePrerequis(const UV& u) { prerequis.erase(remove(prerequis.begin(), prerequis.end(), &u), prerequis.end()); }

    ///
    /// \fn ajoutCredits
    /// \param c Une référence sur un objet de la classe crédit
    /// \brief Utilise la fonction push_back sur le conteneur vecteur cred pour ajouter un type de crédit
    ///
    void ajoutCredits(const Credits& c) { cred.push_back(&c); }

    ///
    /// \fn retireCredits
    /// \param c Une rérence sur un objet de la classe crédit
    /// \brief Retire des crédits d'une UV
    ///
    void retireCredits(const Credits& c) { cred.erase(remove(cred.begin(), cred.end(), &c), cred.end()); }

    ///
    /// \fn affichageUV
    /// \brief Fonction d'affichage d'une UV
    ///
    void affichage();

    //UV& operator=(const UV& u);

    ~UV();//A Redefinir pour qu'il detruisent les allocations et qu'ils s'enlevent des prerequis des autres
};

#endif // UV_PROFIL_H
