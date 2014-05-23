#ifndef CREDIT_H
#define CREDIT_H

#include "Categorie.h"

class Credits { //Permet de Décrire le nombre de crédit associé à une catégorie
    int nombre;
    Categorie& cat;
public :
    Credits(int n,Categorie& categ):nombre(n),cat(categ){}
    int getNombre() const {return nombre;}
    Categorie& getCategorie() const {return cat;}
};

#endif // CREDIT_H
