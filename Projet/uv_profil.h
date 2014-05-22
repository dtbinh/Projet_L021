#ifndef UV_PROFIL_H
#define UV_PROFIL_H

#include <string>
#include <iostream>

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

class Dossier{
private:
    string nom;
    string prenom;
    string login;
public :
    Dossier(string n,string p):nom(n),prenom(p){
        if(nom.size()>=7){
            login=prenom.at(0);
            for(int j=0;j<7;j++)
                login=login+nom.at(j);
        }
        else if((nom.size()+prenom.size())>=8) {
            login=nom;
            for (unsigned int i=0;i<8-nom.size();i++)
                login=login+prenom.at(i);
            }
        else
            login=nom+prenom;
    }
    string getNom() const {return nom;}
    string getPrenom() const {return prenom;}
    string getLogin() const {return login;}
    ~Dossier(){}
    void affichage(){cout<<"Dossier de "<<nom<<" "<<prenom<<" login : "<<login<<endl;}
};

class Categorie{
    string code,nom;
public :
    Categorie(string c,string n):code(c),nom(n){}
    string getCode(){return code;}
    string getNom(){return nom;}
};

class Credit{ //Permet de Décrire le nombre de crédit associé à une catégorie
    int nombre;
    Categorie& cat;
public :
    Credit(int n,Categorie& categ):nombre(n),cat(categ){}
    int getNombre() const {return nombre;}
    Categorie& getCategorie() const {return cat;}
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
