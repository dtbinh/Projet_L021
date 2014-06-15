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
   Inscription(const QString& c = "", const Periode& p = Periode(), const Formation& f = Formation()): code(c), periode(&p), formation(&f), uvs(), notes() {}

   const QString& getCode() const { return code; }
   const Periode& getPeriode() const { return *periode; }
   const Formation& getFormation() const { return *formation; }
   const Factory<UV>& getUVs() const { return uvs; }
   const Factory<Note>& getNotes() const { return notes; }

   void setCode(const QString& c) { code = c; }
   void setPeriode(const Periode& p) { periode = &p; }
   void setFormation(const Formation& f) { formation = &f; }

   UV& getUV(const QString& code) { return uvs.get(code); }
   const UV& getUV(const QString& code) const { return uvs.get(code); }
   void ajouterUV(const UV& uv);
   void ajouterUV(const QString& code, const QString& nom, const Categorie& cat);
   void retirerUV(const QString& code);

   void modifierNote(const QString& code, const Note& n) { notes.get(code) = n; }
};

#endif // INSCRIPTION_H
