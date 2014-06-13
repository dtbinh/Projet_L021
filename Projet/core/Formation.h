///
/// \file Formation.h
/// \brief Un etudiant peut suivre différentes formations.
/// \author Erwan Normand
/// \date 05 juin 2014
///

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
    QString code;
    QString nom;
    std::vector<const Credits*> credits;
    std::vector<const Formation*> specialites;
    std::vector<const UV*> uvs;

public:
    Formation(const QString& c = "", const QString& n = "") : code(c), nom(n), credits(), specialites(), uvs() {}

    const QString& getCode() const { return code; }
    const QString& getNom() const { return nom; }
    const std::vector<const Credits*>& getCredits() const { return credits; }
    const std::vector<const Formation*>& getSpecialites() const { return specialites; }
    const std::vector<const UV*>& getUVs() const { return uvs; }

    void setCode(const QString& c) { code = c; }
    void setNom(const QString& n) { nom = n; }

    void ajouterCredits(const Credits& c) { credits.push_back(&c); }
    void retirerCredits(const Credits& c) { credits.erase(remove(credits.begin(), credits.end(), &c), credits.end()); }
    void ajouterSpecialite(const Formation& f) { specialites.push_back(&f); }
    void retirerSpecialite(const Formation& f) { specialites.erase(remove(specialites.begin(), specialites.end(), &f), specialites.end()); }
    void ajouterUV(const UV& u) { uvs.push_back(&u); }
    void retirerUV(const UV& u) { uvs.erase(remove(uvs.begin(), uvs.end(), &u), uvs.end()); }
};

#endif // FORMATION_H
