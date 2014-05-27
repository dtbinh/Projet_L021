#include "UV.h"

void UV::affichageUV(){
    cout<<code<<"---"<<nom<<"---"<<description<<endl;
    cout<<"Categorie : "<<cat.getCode()<<endl;
    cout<<" Credits : ";
    for(unsigned int i=0;i<cred.size();i++)
        cout<<cred[i]->getNombre()<<" "<<cred[i]->getCategorie().getCode()<<"     ";
    cout<<endl;
        cout<<"Prerequis : ";
        for(unsigned int i=0;i<prerequis.size();i++)
        cout<<" "<<prerequis[i]->getCode();
    cout<<endl;

}

UV::UV(const UV& u){
    code=u.code;
    nom=u.nom;
    description=u.description;
    cat=u.cat;
    for(unsigned int i=0;i<u.cred.size();i++)
            cred.push_back(u.cred[i]);
    for(unsigned int i=0;i<u.prerequis.size();i++)
            prerequis.push_back(u.prerequis[i]);
}

UV::~UV(){

}


