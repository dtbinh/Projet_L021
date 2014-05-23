#ifndef CREDITS_H
#define CREDITS_H

#include "Categorie.h"

class Credit{ //Permet de Décrire le nombre de crédit associé à une catégorie
    int nombre;
    Categorie& cat;
public :
    Credit(int n,Categorie& categ):nombre(n),cat(categ){}
    int getNombre() const {return nombre;}
    Categorie& getCategorie() const {return cat;}
};

#endif // CREDITS_H
