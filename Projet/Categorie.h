#ifndef CATEGORIE_H
#define CATEGORIE_H

using namespace std;

class Categorie{
    string code,nom;
public :
    Categorie(){}
    Categorie(string c,string n):code(c),nom(n){}
    string getCode(){return code;}
    string getNom(){return nom;}
};

#endif // CATEGORIE_H
