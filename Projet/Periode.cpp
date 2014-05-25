#include "Periode.h"

using namespace std;

Periode::Periode(string n, unsigned int a): code(""), nom(n), annee(a)
{
    if (annee < 1970 || annee > 2069) {
        throw Exception("L'annee doit etre comprise entre 1970 et 2069.");
    }
    if (nom.size() < 1) {
        throw Exception("Le nom doit faire au moins 1 caractere.");
    }

    // Créé le code à partir du nom et de l'année
    ostringstream codetmp;
    codetmp << nom[0] << annee % 100;
    code = codetmp.str();
}

void Periode::afficher()
{
    cout << code << " (" << nom << " " << annee << ")" << endl;
}
