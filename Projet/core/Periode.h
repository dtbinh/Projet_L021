///
/// \file Periode.h
/// \brief Une formation est découpée en plusieurs périodes.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef PERIODE_H
#define PERIODE_H

#include <iostream>
#include <QString>
#include <sstream>
#include "Exception.h"

///
/// \class Periode
/// \brief Periode correspond à un semestre étudiant.
///
class Periode
{
private:
    QString code;
    QString nom;
    unsigned int annee;

    ///
    /// \fn setCode
    /// \brief Determine le code d'une periode à partir de son nom et de l'année
    ///
    void setCode(){code = nom[0] + QString::number(annee);}

public:
    ///
    /// \fn Periode
    /// \brief Constructeur de Periode, le code de la periode est obtenue automatiquement à partir du nom et de l'annee
    /// \param n Nom de la periode
    /// \param a Annee de la periode
    ///
    Periode(const QString& n="", unsigned int a=0): code(""), nom(n), annee(a){ setCode(); }

    ///
    /// \fn getCode
    /// \brief Renvoie une référence vers le code de la periode
    /// \return const QString& -> Code de la periode
    ///
    const QString& getCode() const { return code; }

    ///
    /// \fn getNom
    /// \brief Renvoie une référence vers le nom de la periode
    /// \return const QString& -> Nom de la periode
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom
    /// \brief Pour modifier le nom de la periode. Modifie le code automatiquement
    /// \param n Nouveau nom de la periode
    ///
    void setNom(const QString& n) { nom = n; setCode();}

    ///
    /// \fn getAnnee
    /// \brief Renvoie l'annee de la periode
    /// \return unsigned int -> Annee de la periode
    ///
    unsigned int getAnnee() const { return annee; }

    ///
    /// \fn setAnnee
    /// \brief Pour modifier l'annee de la periode. Modifie le code automatiquement
    /// \param a Nouvelle année de la periode
    ///
    void setAnnee(unsigned int a) { annee = a; setCode();}

};

#endif // PERIODE_H
