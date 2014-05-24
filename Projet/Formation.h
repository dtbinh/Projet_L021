#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "UV.h"
#include "Credits.h"


class Formation
{
private:
    std::string code;
    std::string nom;
    vector<const Credits*> credits;
    vector<const Formation*> formations_parentes; // faire formations_filles
    vector<const UV*> uvs;

public:
    Formation(const std::string& c, const std::string& n) : code(c), nom(n), credits(vector<const Credits*>()), formations_parentes(vector<const Formation*>()), uvs(vector<const UV*>()) {}

    const std::string& getCode() const { return code; }
    const std::string& getNom() const { return nom; }
    const vector<const Credits*>& getCredits() const { return credits; }
    const vector<const Formation*>& getFormationsParentes() const { return formations_parentes; }
    const vector<const UV*>& getUVs() const { return uvs; }

    void ajouterCredits(const Credits& c) { credits.push_back(&c); }
    void retirerCredits(const Credits& c) { credits.erase(std::remove(credits.begin(), credits.end(), &c), credits.end()); }
    void ajouterFormationParente(const Formation& f) { formations_parentes.push_back(&f); }
    void retirerFormationParente(const Formation& f) { formations_parentes.erase(std::remove(formations_parentes.begin(), formations_parentes.end(), &f), formations_parentes.end()); }
    void ajouterUV(const UV& u) { uvs.push_back(&u); }
    void retirerUV(const UV& u) { uvs.erase(std::remove(uvs.begin(), uvs.end(), &u), uvs.end()); }

    void afficher();
};

#endif // FORMATION_H
