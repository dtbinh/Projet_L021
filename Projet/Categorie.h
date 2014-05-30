///
/// \file Categorie.h
/// \brief Les UVs de l'UTC sont décrit en catégorie
/// \author Nicolas Szewe
/// \version 0.1
/// \date 27 mai 2014
///

#ifndef CATEGORIE_H
#define CATEGORIE_H

using namespace std;

class Categorie{
    string code,nom;
public :
    ///
    /// \fn Categorie
    /// Constructeur par défault de la classe Catégorie, on a besoin de lui pour
    /// le constructeur de recopie de la classe UV
    ///
    Categorie(){}

    ///
    /// \fn Categorie(string c,string n)
    /// \param c Le code de l'UV a crée
    /// \param n Le nom de l'UV a crée
    /// \brief Constructeur nécessitant le nom et le code de l'UV
    ///
    Categorie(string c,string n):code(c),nom(n){}

    ///
    /// \fn getCode
    /// \return retourne le code de la categorie
    ///
    string getCode() const {return code;}

    ///
    /// \fn getNom
    /// \return string retourne le nom de la categorie
    ///
    string getNom() const {return nom;}
};

#endif // CATEGORIE_H
