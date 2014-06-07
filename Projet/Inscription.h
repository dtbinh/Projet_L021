///
/// \file Inscription.h
/// \brief Un étudiant s'inscrit à des UVs à chaque période de ses formations
/// \author Erwan Normand
/// \date 05 juin 2014
///

#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <iostream>
#include <map>
#include <algorithm>
#include "Periode.h"
#include "Formation.h"
#include "UV.h"
#include "Note.h"

class Inscription
{
private:
    const Periode* periode;
    const Formation* formation;
    std::map<QString,UV> uvs;
    std::map<QString,Note> notes;

public:
   Inscription(const Periode& p, const Formation& f): periode(&p), formation(&f), uvs() {}

   const Periode& getPeriode() const { return *periode; }
   const Formation& getFormation() const { return *formation; }
   const std::map<QString,UV>& getUVs() const { return uvs; }
   const std::map<QString,Note>& getNotes() const { return notes; }

   void setPeriode(const Periode& p) { periode = &p; }
   void setFormation(const Formation& f) { formation = &f; }

   void ajouterUV(const UV& u);
   void retirerUV(const UV& u);
   void modifierNote(const UV& u, const Note& n) { notes[u.getCode()] = n; }
   
   void afficher() const;
};

#endif // INSCRIPTION_H
