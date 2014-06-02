#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <iostream>
#include <map>
#include <algorithm>
#include "Periode.h"
#include "Formation.h"
#include "UV.h"

class Inscription
{
private:
    const Periode& periode;
    const Formation& formation;
    map<string,UV> uvs;
    map<string,Note> notes;

public:
   Inscription(const Periode& p, const Formation& f): periode(p), formation(f), uvs(map<string,UV>()), notes(map<string,Note>()) {}

   const Periode& getPeriode() const { return periode; }
   const Formation& getFormation() const { return formation; }
   const map<string,UV>& getUVs() const { return uvs; }
   const map<string,Note>& getNotes() const { return notes; }

   void ajouterUV(const UV& u);
   void retirerUV(const UV& u);
   void modifierNote(const UV& u, const Note& n);
   
   void afficher() const;
};

#endif // INSCRIPTION_H
