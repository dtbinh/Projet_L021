#include "Completion.h"
#include <string>
#include <iostream>

using namespace std;

Completion::Completion(const UVManager& uvman) : solutions() {
    QString codeuv,choix,pref;
    while(choix!="fin"){
        //cin.clear();
        cout<<"Sur quelle UV voulez vous emettre une preference?"<<endl;
        //cin>>codeuv;
        codeuv="LO21";
        uvman.getUV(codeuv);
        cout<<"Quelle préférence souhaitez vous emettre? (Exigence,Refus ou NSP)"<<endl;
        //cin>>pref;
        pref="Exigence";
        if (pref=="Exigence")
            preferences[codeuv]=Exigence;
        else if(pref=="Refus")
            preferences[codeuv]=Refus;
        else if(pref=="NSP")
            preferences[codeuv]=NSP;
        else
            cout<<"Exigence incorrect"<<endl;
        cout<<"Voulez vous continuez? Tapez fin pour arreter"<<endl;
        //cin>>choix;
        choix="fin";
    }


}
