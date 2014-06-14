#include "Periode.h"

using namespace std;

Periode::Periode(const QString& n, unsigned int a): code(""), nom(n), annee(a)
{
    code = nom[0] + QString::number(annee);
}
