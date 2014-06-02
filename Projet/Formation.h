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
    std::vector<const Credits*> credits;
    std::vector<const Formation*> specialites; //Les formations filles
    std::vector<const UV*> uvs;

public:
    Formation(const std::string& c, const std::string& n) : code(c), nom(n), credits(std::vector<const Credits*>()), specialites(std::vector<const Formation*>()), uvs(std::vector<const UV*>()) {}

    const std::string& getCode() const { return code; }
    const std::string& getNom() const { return nom; }
    const std::vector<const Credits*>& getCredits() const { return credits; }
    const std::vector<const Formation*>& getSpecialites() const { return specialites; }
    const std::vector<const UV*>& getUVs() const { return uvs; }

    void setCode(const std::string& c) { code = c; }
    void setNom(const std::string& n) { nom = n; }

    void ajouterCredits(const Credits& c) { credits.push_back(&c); }
    void retirerCredits(const Credits& c) { credits.erase(remove(credits.begin(), credits.end(), &c), credits.end()); }
    void ajouterSpecialite(const Formation& f) { specialites.push_back(&f); }
    void retirerSpecialite(const Formation& f) { specialites.erase(remove(specialites.begin(), specialites.end(), &f), specialites.end()); }
    void ajouterUV(const UV& u) { uvs.push_back(&u); }
    void retirerUV(const UV& u) { uvs.erase(remove(uvs.begin(), uvs.end(), &u), uvs.end()); }

    void afficher();
};

#endif // FORMATION_H
