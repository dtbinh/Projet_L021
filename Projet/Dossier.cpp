#include "Dossier.h"

using namespace std;

void Dossier::setLogin()
{
    if (nom.size() >= 7) {
        login = prenom.at(0);
        for (int j=0; j<7; j++) {
            login += nom.at(j);
        }
    }
    else if ((nom.size() + prenom.size()) >= 8) {
        login = nom;
        for (int i=0; i<8-nom.size(); i++)
            login += prenom.at(i);
    }
    else {
        login = nom + prenom;
    }
}

void Dossier::afficher()
{    
    cout << "Dossier de " << nom.toStdString( )<< " " << prenom.toStdString() << " login : " << login.toStdString() << endl;

    for (map<QString,Formation>::const_iterator it = formations.begin(); it != formations.end(); it++)
    {
        cout << it->second.getCode().toStdString() << " "<< it->second.getNom().toStdString() << " ";
    }
    cout << endl;

    for (map<QString,Inscription>::const_iterator it = inscriptions.begin(); it != inscriptions.end(); it++)
    {
        //it->second.afficher(); // Impossible, la méthode afficher de Inscription doit être const.
    }
}
