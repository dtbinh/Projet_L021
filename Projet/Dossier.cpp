#include "Dossier.h"

using namespace std;


void Dossier::affichageDossier(){
    cout<<"Dossier de "<<nom<<" "<<prenom<<" login : "<<login<<endl;
    for(unsigned int i=0;i<formation.size();i++)
        cout<<formation[i]->getCode()<<" "<<formation[i]->getNom()<<"     ";
    cout<<endl;
        for(unsigned int i=0;i<inscription.size();i++){
            cout<<inscription[i]->getPeriode().getCode()<<endl;
           // inscription[i]->afficherInscription();
        }
    cout<<endl;

}

