#ifndef FORMATION_H
#define FORMATION_H

#include <vector>
#include <uv_profil.h>

class Formation {
private:
    string code;
    string nom;
    vector<const Credit*> credits;
    vector<const Formation*> formations_parentes;
    vector<const UV*> uvs;

public:
    Formation(const string& c, const string& n) : code(c), nom(n), credits(vector<const Credit*>()), formations_parentes(vector<const Formation*>()) {}
    const string& getCode() const { return code; }
    const string& getNom() const { return nom; }

    void ajouterCredit(const Credit& c) { credits.push_back(&c); }
    void retirerCredit(const Credit& c);
    void ajouterFormationParente(const Formation& f) { formations_parentes.push_back(&f); }
    void retirerFormationParente(const Formation& f);
    void ajouterUV(const UV& u) { uvs.push_back(&u); }
    void retirerUV(const UV& u);

    void afficher();
};

#endif // FORMATION_H
