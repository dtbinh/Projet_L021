#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Periode.h"
#include "UV.h"

class Inscription
{
private:
    const Periode& periode;
    vector<UV> uvs;
    vector<Note> notes;

public:
   Inscription(const Periode& p): periode(p), uvs(vector<UV>()), notes(vector<Note>()) {}

   const Periode& getPeriode() const { return periode; }
   const vector<UV>& getUVs() const { return uvs; }
   const vector<Note>& getNotes() const { return notes; }

   void ajouterUV(const UV& u) { uvs.push_back(u); }
   void retirerUV(const UV& u) { }
};

#endif // INSCRIPTION_H
