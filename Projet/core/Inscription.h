///
/// \file Inscription.h
/// \brief Un étudiant s'inscrit à des UVs à chaque période de ses formations
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <iostream>
#include <map>
#include <algorithm>
#include <QString>
#include "Factory.h"
#include "Periode.h"
#include "Formation.h"
#include "UV.h"
#include "Note.h"
#include "Categorie.h"

class Inscription
{
private:
    QString code;
    const Periode* periode;
    const Formation* formation;
    Factory<UV> uvs;
    Factory<Note> notes;

public:
    ///
    /// \fn Inscription
    /// \brief Constructeur de la classe Inscription. Les vecteurs uvs et notes sont initialisés à null.
    /// \param c Code de l'inscription
    /// \param p Pointeur sur la periode de l'inscription
    /// \param f Pointeur sur la formation de l'inscription.
    ///
   Inscription(const QString& c = "", const Periode& p = Periode(), const Formation& f = Formation()): code(c), periode(&p), formation(&f), uvs(), notes() {}

   ///
   /// \fn getCode
   /// \brief Accede au code d'une inscription
   /// \return const QString& -> Code d'une inscription
   ///
   const QString& getCode() const { return code; }

   ///
   /// \fn setCode
   /// \brief Pour modifier le code d'une inscription
   /// \param c Le nouveau code de l'inscription
   ///
   void setCode(const QString& c) { code = c; }

   ///
   /// \fn getPeriode
   /// \brief Renvoie une référence sur la periode de l'inscription
   /// \return const Periode& -> Periode d'une inscription
   ///
   const Periode& getPeriode() const { return *periode; }

   ///
   /// \fn setPeriode
   /// \brief Pour modifier la periode d'une inscription
   /// \param p Reference vers une periode déja existante
   ///
   void setPeriode(const Periode& p) { periode = &p; }

   ///
   /// \fn getFormation
   /// \brief Renvoie une référence sur la formation de l'inscription
   /// \return const Formation& -> Formation d'une inscription
   ///
   const Formation& getFormation() const { return *formation; }

   ///
   /// \fn setFormation
   /// \brief Pour modifier la formation d'une inscription
   /// \param f Reference vers une formation déja existante
   ///
   void setFormation(const Formation& f) { formation = &f; }

   ///
   /// \fn getUVs
   /// \brief Renvoie l'ensemble des uvs d'une inscription
   /// \return const Factory<UV>& -> Ensemble des uvs d'une inscription
   ///
   const Factory<UV>& getUVs() const { return uvs; }

   ///
   /// \fn getUV
   /// \brief Renvoie une uv particuliere de l'ensemble des uvs d'une inscription
   /// \param code Code de l'UV a récupérer
   /// \return UV& -> Référence sur l'UV recherchée
   ///
   UV& getUV(const QString& code) { return uvs.get(code); }

   ///
   /// \fn getUV
   /// \brief Renvoie une uv particuliere de l'ensemble des uvs d'une inscription
   /// \param code Code de l'UV a récupérer
   /// \return const UV& -> Référence constante sur l'UV recherchée
   ///
   const UV& getUV(const QString& code) const { return uvs.get(code); }

   ///
   /// \fn ajouterUV
   /// \brief Pour ajouter une UV à une inscription
   /// \param uv Référence sur une UV déja existante
   ///
   void ajouterUV(const UV& uv);

   ///
   /// \fn retirerUV
   /// \brief Pour retirer une UV d'une inscription
   /// \param code Code de l'UV à retirer
   ///
   void retirerUV(const QString& code);

   ///
   /// \fn getNotes
   /// \brief Renvoie l'ensemble des notes d'une inscription
   /// \return const Factory<Note>& -> Ensemble des notes d'une inscription
   ///
   const Factory<Note>& getNotes() const { return notes; }

   ///
   /// \fn modifierNote
   /// \brief Pour modifier la note obtenue à une UV
   /// \param code Code de l'UV dont la note est a modifiée
   /// \param n Nouvelle note pour l'UV concernée
   ///
   void modifierNote(const QString& code, const Note& n) { notes.get(code) = n; }





};

#endif // INSCRIPTION_H
