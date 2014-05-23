#ifndef UV_PROFIL_H
#define UV_PROFIL_H

#include <string>
#include <iostream>
#include "Categorie.h"
#include "Credits.h"

using namespace std;

enum class Choix {
    Confirmer,Refuser,Retarder,Avancer
};

enum class Note{
    A,B,C,D,E,F,FX,RES,ABS,EC
};

enum class Preference{
    Exigence,Refus,NSP
};

class UV{
private :
    string code,nom,description;
    unsigned int nb_cred;
    Credit** cred; // Une UV peut avoir plusieurs types de crédits, il faut donc faire un tableau alloué dynamiquement
    Categorie cat;
    unsigned int nb_pre;
    UV** prerequis; // On peut avoir plusieurs prérequis, il faut faire un tableau de pointeurs
public :
    UV(string c,string n, string d,Credit* cre,const Categorie& categ,UV* p=0);
    string getCode() const {return code;}
    string getNom() const {return nom;}
    string getDescription() const {return description;}
    Categorie getCat() const {return cat;}
    void ajoutPrerequis(UV* u);
    void retirePrerequis(UV* u);
    void ajoutCredits(Credit* c);//Exactement la meme que prerequis --> Template?
    void retireCredits(Credit* c);// Meme remarque
    void affichageUV();
    ~UV(){}//A Redefinir pour qu'il detruisent les allocations et qu'ils s'enlevent des prerequis des autres
};



#endif // UV_PROFIL_H
