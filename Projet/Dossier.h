#ifndef DOSSIER_H
#define DOSSIER_H

using namespace std;

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

#endif // DOSSIER_H
