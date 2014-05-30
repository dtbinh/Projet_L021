#include "Formation.h"

using namespace std;

void Formation::afficher()
{
    cout << code << " " << nom << endl;

    cout << "Credits : ";
    for (unsigned int i = 0; i < credits.size(); i++)
    {
        cout << credits[i]->getNombre() << " " << credits[i]->getCategorie().getCode() << "  ";
    }
    cout << endl;

    cout << "Spécialités : ";
    for (unsigned int i = 0; i < specialites.size(); i++)
    {
        cout << specialites[i]->getCode() << " " << specialites[i]->getNom() << "  ";
    }
    cout << endl;

    cout << "UVS : ";
    for (unsigned int i = 0; i < uvs.size(); i++)
    {
        cout << uvs[i]->getCode() << " ";
    }
    cout << endl;
}
