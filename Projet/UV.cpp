#include "UV.h"

using namespace std;

void UV::affichage(){
    cout<<code.toStdString()<<"---"<<nom.toStdString()<<endl;
    cout<<"Categorie : "<<cat.getCode().toStdString()<<endl;
    cout<<"Credits : ";
    for(unsigned int i=0;i<cred.size();i++)
        cout<<cred[i]->getNombre()<<" ";
           //<<cred[i]->getCategorie()->getCode().toStdString()<<"     ";
    cout<<endl;
        /*cout<<"Prerequis : ";
        for(unsigned int i=0;i<prerequis.size();i++)
        cout<<" "<<prerequis[i]->getCode().toStdString();
    cout<<endl;*/ //Affichage que l'on remettra plus tard
    cout<<endl;
}

UV::UV(const UV& u){
    code=u.code;
    nom=u.nom;
    cat=u.cat;
    for(unsigned int i=0;i<u.cred.size();i++)
            cred.push_back(u.cred[i]);
    for(unsigned int i=0;i<u.prerequis.size();i++)
            prerequis.push_back(u.prerequis[i]);
}


UV::~UV(){
    code="NULL";
    nom="NULL";

}



