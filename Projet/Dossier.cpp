#include "Dossier.h"

using namespace std;

void Dossier::setLogin()
{
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

void Dossier::afficher()
{    
    cout << "Dossier de "<<nom.toStdString()<<" "<<prenom.toStdString()<<" login : "<<login.toStdString()<<endl;
    for (map<QString,const Formation*>::const_iterator it = formation.begin(); it != formation.end(); it++)
    {
        cout << it->second->getCode().toStdString() << " "<< it->second->getNom().toStdString() << " ";
    }
    cout<<endl;
    for (map<QString,const Inscription*>::const_iterator it = inscription.begin(); it != inscription.end(); it++)
    {
        it->second->afficher();
    }
}

void Dossier::ajouterFormation(const Formation &f)
{
     formation[f.getCode()]=&f;
}

void Dossier::ajouterInscription(const Inscription &f)
{
    inscription[f.getPeriode().getCode()]=&f;
}


