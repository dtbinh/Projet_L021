#include "Formation.h"

using namespace std;

void Formation::afficher()
{
    cout << code.toStdString() << " " << nom.toStdString() << endl;

    cout << "Credits : ";
    for (unsigned int i = 0; i < credits.size(); i++)
    {
        cout << credits[i]->getNombre() << " ";
             //<< credits[i]->getCategorie()->getCode().toStdString() << "  ";
    }
    cout << endl;

    cout << "Spécialités : ";
    for (unsigned int i = 0; i < specialites.size(); i++)
    {
        cout << specialites[i]->getCode().toStdString() << " " << specialites[i]->getNom().toStdString() << "  ";
    }
    cout << endl;

    cout << "UVS : ";
    for (unsigned int i = 0; i < uvs.size(); i++)
    {
        cout << uvs[i]->getCode().toStdString() << " ";
    }
    cout << endl;
}

