///
/// \file Categorie.h
/// \brief Les UVs de l'UTC sont décrit en catégorie
/// \author Nicolas Szewe, Erwan Normand
/// \date 27 mai 2014
///

#ifndef CATEGORIE_H
#define CATEGORIE_H

class Categorie {
    std::string code, nom;
public :
    ///
    /// \fn Categorie(string c,string n)
    /// \param c Le code de l'UV a crée
    /// \param n Le nom de l'UV a crée
    /// \brief Constructeur nécessitant le nom et le code de l'UV
    ///
    Categorie(const std::string& c = "", const std::string& n = ""): code(c), nom(n) {}

    ///
    /// \fn getCode()
    /// \return const string& retourne le code de la categorie
    ///
    const std::string& getCode() const { return code; }

    ///
    /// \fn getNom()
    /// \return const string& retourne le nom de la categorie
    ///
    const std::string& getNom() const { return nom; }
};

#endif // CATEGORIE_H
