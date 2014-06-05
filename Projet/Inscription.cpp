#include "Inscription.h"

using namespace std;

void Inscription::ajouterUV(const UV& u)
{
    uvs[u.getCode()] = u;
    notes[u.getCode()] = EC;
}

void Inscription::retirerUV(const UV& u)
{
    uvs.erase(u.getCode());
    notes.erase(u.getCode());
}

void Inscription::modifierNote(const UV& u, const Note& n)
{
    notes[u.getCode()] = n;
}

void Inscription::afficher() const
{
    cout << periode->getCode().toStdString() << " " << formation->getCode().toStdString() << endl;

    cout << "UVs : ";
    for (map<QString,UV>::const_iterator it = uvs.begin(); it != uvs.end(); it++)
    {
        cout << it->second.getCode().toStdString() << " " << notes.find(it->second.getCode())->second << "  ";
    }
    cout << endl;
}
