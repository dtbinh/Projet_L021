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

#endif // UV_PROFIL_H
