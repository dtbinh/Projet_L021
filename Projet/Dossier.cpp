﻿#include "Dossier.h"

using namespace std;

Dossier::Dossier(string n,string p):nom(n),prenom(p),formation(vector<const Formation*>()),inscription(vector<const Inscription*>()){
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

void Dossier::affichage(){
    cout<<"Dossier de "<<nom<<" "<<prenom<<" login : "<<login<<endl;
    for(unsigned int i=0;i<formation.size();i++)
        cout<<formation[i]->getCode()<<" "<<formation[i]->getNom()<<"     ";
    cout<<endl;
        for(unsigned int i=0;i<inscription.size();i++){
           inscription[i]->afficher();
        }
    cout<<endl;

}

