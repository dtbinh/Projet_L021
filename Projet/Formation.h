#ifndef FORMATION_H
#define FORMATION_H

#include <iostream>
#include <vector>
#include "UV.h"
#include "Credits.h"

class Formation
{
private:
    std::string code;
    std::string nom;
    vector<const Credits*> credits;
    vector<const Formation*> formations_parentes;
    vector<const UV*> uvs;

public:
    Formation(const std::string& c, const std::string& n) : code(c), nom(n), credits(vector<const Credits*>()), formations_parentes(vector<const Formation*>()) {}
    const std::string& getCode() const { return code; }
    const std::string& getNom() const { return nom; }
    const vector<const Credits*>& getCredits() const { return credits;  }

    void ajouterCredits(const Credits& c) { credits.push_back(&c); }
    void retirerCredits(const Credits& c);
    void ajouterFormationParente(const Formation& f) { formations_parentes.push_back(&f); }
    void retirerFormationParente(const Formation& f);
    void ajouterUV(const UV& u) { uvs.push_back(&u); }
    void retirerUV(const UV& u);

    void afficher();
};

#endif // FORMATION_H
