#ifndef UV_PROFIL_H
#define UV_PROFIL_H

#include <string>
#include <iostream>
#include <vector>
#include "Categorie.h"
#include "Credits.h"
#include "Exception.h"

using namespace std;

enum Choix {
    Confirmer,Refuser,Retarder,Avancer
};

enum Note {
    A,B,C,D,E,F,FX,RES,ABS,EC
};

enum Preference{
    Exigence,Refus,NSP
};

class UV{
private :
    string code,nom,description;
    Categorie cat;
    vector<const Credits*> cred; // Une UV peut avoir plusieurs types de crédits, il faut donc faire un tableau alloué dynamiquement
    vector<const UV*> prerequis; // On peut avoir plusieurs prérequis, il faut faire un tableau de pointeurs
public :
    UV(const string& c,const string& n, const string& d,const Categorie& categ)
    : code(c), nom(n),description(d),cat(categ),cred(vector<const Credits*>()),prerequis(vector<const UV*>()) {}
    UV(const UV& u);
    string getCode() const {return code;}
    string getNom() const {return nom;}
    string getDescription() const {return description;}
    Categorie getCat() const {return cat;}
    const vector<const Credits*>& getCredits() const { return cred; }
    const vector<const UV*>& getUVs() const { return prerequis ; }

    void ajoutPrerequis(const UV& u){ prerequis.push_back(&u); }
    void retirePrerequis(const UV& u) { if (prerequis.empty()) throw Exception("Objets vide, suppression impossible"); else prerequis.erase(remove(prerequis.begin(), prerequis.end(), &u), prerequis.end()); }
    void ajoutCredits(const Credits& c) { cred.push_back(&c); }
    void retireCredits(const Credits& c) { if (cred.empty()) throw Exception("Objets vide, suppression impossible"); else cred.erase(remove(cred.begin(), cred.end(), &c), cred.end()); }

    void affichageUV();

    //UV& operator=(const UV& u);

    ~UV(){}//A Redefinir pour qu'il detruisent les allocations et qu'ils s'enlevent des prerequis des autres
};






#endif // UV_PROFIL_H
