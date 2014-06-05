#ifndef PERIODE_H
#define PERIODE_H

#include <iostream>
#include <QString>
#include <sstream>
#include "Exception.h"

class Periode
{
private:
    QString code;
    QString nom;
    unsigned int annee;

public:
    Periode(QString n, unsigned int a);
    Periode(){}
    const QString& getCode() const { return code; }
    const QString& getNom() const { return nom; }
    unsigned int getAnnee() const { return annee; }

    void afficher();
};

#endif // PERIODE_H
