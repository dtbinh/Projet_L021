#include "Inscription.h"

using namespace std;

void Inscription::ajouterUV(const UV& u)
{
    uvs[u.getCode()] = &u;
    notes[u.getCode()] = EC;
}

void Inscription::retirerUV(const UV& u)
{
    uvs.erase(u.getCode());
    notes.erase(u.getCode());
}

void Inscription::afficherInscription ()
{
    cout << periode.getCode() << " " << formation.getCode() << endl;

    cout << "UVs : ";
    for (map<string, const UV*>::iterator it = uvs.begin(); it != uvs.end(); it++)
    {
        cout << it->second->getCode() << " " << notes[it->second->getCode()] << "  ";
    }
    cout << endl;
}
