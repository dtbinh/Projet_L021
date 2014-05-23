#include "UV.h"

void UV::affichageUV(){
    cout<<code<<"---"<<nom<<"---"<<description<<endl;
    cout<<"Categorie : "<<cat.getCode()<<endl;
    cout<<" Credits : ";
    for(unsigned int i=0;i<nb_cred;i++)
        cout<<cred[i]->getNombre()<<" "<<cred[i]->getCategorie().getCode()<<"     ";
    cout<<endl;
    if (prerequis!=0){
        cout<<"Prerequis : ";
        for(unsigned int i=0;i<nb_pre;i++)
        cout<<" "<<prerequis[i]->getCode();
    cout<<endl;
    }
}

UV::UV(string c,string n, string d,Credits* cre,const Categorie& categ,UV* p)
    :code(c),nom(n),description(d),cat(categ),nb_cred(1)
{
    if(p==0) nb_pre=0;
    else {
        nb_pre=1;
        prerequis=new UV*[nb_pre];
        prerequis[0]=p;
    } //Initialisation prerequis
    cred=new Credits*[nb_cred];
    cred[0]=cre;
}

void UV::ajoutPrerequis(UV* u){
    nb_pre++;
    UV** new_prerequis=new UV*[nb_pre];
    for(unsigned int i=0;i<nb_pre;i++)
        new_prerequis[i]=prerequis[i];
    new_prerequis[nb_pre-1]=u;
    UV** old=prerequis;
    prerequis=new_prerequis;
    delete[] old;
}

void UV::retirePrerequis(UV* u){
    unsigned int i=0;
    while(prerequis[i]!=u || i>nb_pre) i++;
    if (i>nb_pre) cout<<"L'UV n'est pas un prerequis"<<endl; //Ajouter exception
    else
        for(i;i<nb_pre;i++)
            prerequis[i]=prerequis[i+1];
    nb_pre--;
}

void UV::ajoutCredits(Credits* c){
    nb_cred++;
    Credits** new_credits=new Credits*[nb_cred];
    for(unsigned int i=0;i<nb_cred;i++)
        new_credits[i]=cred[i];
    new_credits[nb_cred-1]=c;
    Credits** old=cred;
    cred=new_credits;
    delete[] old;
}

void UV::retireCredits(Credits* c){
    unsigned int i=0;
    if(nb_cred==1) cout<<"Impossible d'enlever ces credits, ce sont les derniers"<<endl;
    else{
    while(cred[i]!=c || i>nb_cred) i++;
    if (i>nb_cred) cout<<"L'UV n'a pas ce type de credits"<<endl; //Ajouter exception
    else
        for(i;i<nb_cred;i++)
            cred[i]=cred[i+1];
    nb_cred--;
    }
}

