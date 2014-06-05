#include "Periode.h"
#include <QTextStream>

using namespace std;

Periode::Periode(QString n, unsigned int a): code(""), nom(n), annee(a)
{
    if (annee < 1970 || annee > 2069) {
        throw Exception("L'annee doit etre comprise entre 1970 et 2069.");
    }
    if (nom.size() < 1) {
        throw Exception("Le nom doit faire au moins 1 caractere.");
    }

    // Créé le code à partir du nom et de l'année
    code=nom[0]+QString::number(annee % 100);
}


void Periode::afficher()
{
    cout << code.toStdString() << " (" << nom.toStdString() << " " << annee << ")" << endl;
}
