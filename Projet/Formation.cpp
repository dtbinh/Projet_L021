#include "Formation.h"

using namespace std;

void Formation::retirerCredits(const Credits& c)
{
    vector<const Credits*>::iterator it = credits.begin();
    while (it != credits.end() && *it != &c) {
        ++it;
    }

    if (*it == &c) {
        credits.erase(it);
    }
}

void Formation::retirerFormationParente(const Formation& f)
{
    vector<const Formation*>::iterator it = formations_parentes.begin();
    while (it != formations_parentes.end() && *it != &f) {
        ++it;
    }

    if (*it == &f) {
        formations_parentes.erase(it);
    }
}

void Formation::retirerUV(const UV& u)
{
    vector<const UV*>::iterator it = uvs.begin();
    while (it != uvs.end() && *it != &u) {
        ++it;
    }

    if (*it == &u) {
        uvs.erase(it);
    }
}

void Formation::afficher()
{
    cout << code << "\t" << nom << endl;

    cout << "Credits : ";
    for (vector<const Credits*>::iterator credit = credits.begin(); credit != credits.end(); ++credit)
    {
        cout << (*credit)->getNombre() << " " << (*credit)->getCategorie().getCode() << "  ";
    }
    cout << endl;

    cout << "Formations parentes : ";
    for (vector<const Formation*>::iterator formation = formations_parentes.begin(); formation != formations_parentes.end(); ++formation)
    {
        cout << (*formation)->getCode() << " " << (*formation)->getNom() << "  ";
    }
    cout << endl;

    cout << "UVS : ";
    for (vector<const UV*>::iterator uv = uvs.begin(); uv != uvs.end(); ++uv)
    {
        cout << (*uv)->getCode() << " ";
    }
    cout << endl;
}
