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
            for (int i=0;i<8-nom.size();i++)
                login=login+prenom.at(i);
            }
        else
            login=nom+prenom;
    }
    string GetNom() const {return nom;}
    string GetPrenom() const {return prenom;}
    string GetLogin() const {return login;}
    ~Dossier(){}
    void Affichage(){cout<<"Dossier de "<<nom<<" "<<prenom<<" login : "<<login<<endl;}
};

class Categorie{
    string code,nom;
public :
    Categorie(string c,string n):code(c),nom(n){}
    string GetCode(){return code;}
    string GetNom(){return nom;}
};

class Credit{
    int nombre;
    Categorie& cat;
public :
    Credit(int n,Categorie& categ):nombre(n),cat(categ){}
    int GetNombre() const {return nombre;}
    Categorie& GetCategorie() const {return cat;}
};

class UV{
private :
    string code,nom,description;
    Credit cred;
    Categorie cat;
    UV* prerequis;
    // Est ce vraiment necessaire? On l'a déja via les credits
public :
    UV(string c,string n, string d,const Credit& cre,const Categorie& categ,UV* p=0):code(c),nom(n),description(d),cred(cre),cat(categ),prerequis(p){}
    string GetCode() const {return code;}
    string GetNom() const {return nom;}
    string GetDescription() const {return description;}
    UV* GetPrerequis() const {return prerequis;}
    Credit GetCred() const {return cred;}
    Categorie GetCat() const {return cat;}
    void AffichageUV();
};



#endif // UV_PROFIL_H
