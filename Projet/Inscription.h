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
    map<string, const UV*> uvs; // Il faut des objets UV et non des pointeurs : les UVs doivent être recopiées pour être protégées des modifications possibles après leur inscription
    map<string, Note> notes;

public:
   Inscription(const Periode& p, const Formation& f): periode(p), formation(f), uvs(map<string, const UV*>()), notes(map<string, Note>()) {}
   const Periode& getPeriode() const { return periode; }
   const map<string, const UV*>& getUVs() const { return uvs; }
   const map<string, Note>& getNotes() const { return notes; }

   void ajouterUV(const UV& u);
   void retirerUV(const UV& u);
   
   void afficherInscription() ;
};

#endif // INSCRIPTION_H
