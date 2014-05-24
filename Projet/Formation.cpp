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

    cout << "Formations parentes : ";
    for (unsigned int i = 0; i < formations_parentes.size(); i++)
    {
        cout << formations_parentes[i]->getCode() << " " << formations_parentes[i]->getNom() << "  ";
    }
    cout << endl;

    cout << "UVS : ";
    for (unsigned int i = 0; i < uvs.size(); i++)
    {
        cout << uvs[i]->getCode() << " ";
    }
    cout << endl;
}
