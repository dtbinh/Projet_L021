///
/// \file Categorie.h
/// \brief Les UVs de l'UTC sont décrit en catégorie
/// \author Nicolas Szewe, Erwan Normand
/// \date 27 mai 2014
///

#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QString>

class Categorie
{
    QString code, nom;

public :
    ///
    /// \fn Categorie(string c,string n)
    /// \param c Le code de l'UV a crée
    /// \param n Le nom de l'UV a crée
    /// \brief Constructeur nécessitant le nom et le code de l'UV
    ///
    Categorie(const QString& c = "", const QString& n = ""): code(c), nom(n) {}

    ///
    /// \fn getCode()
    /// \return const QString& retourne le code de la categorie
    ///
    const QString& getCode() const { return code; }

    void setCode(const QString& c) { code = c; }

    ///
    /// \fn getNom()
    /// \return const QString& retourne le nom de la categorie
    ///
    const QString& getNom() const { return nom; }

    void setNom(const QString& n) { nom = n; }
};

#endif // CATEGORIE_H
