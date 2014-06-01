#ifndef PERIODE_H
#define PERIODE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Exception.h"

class Periode
{
private:
    std::string code;
    std::string nom;
    unsigned int annee;

public:
    Periode(std::string n, unsigned int a);

    std::string& getCode() { return code; }
    const std::string& getCode() const { return code; }
    std::string& getNom() { return nom; }
    const std::string& getNom() const { return nom; }
    unsigned int getAnnee() { return annee; }
    unsigned int getAnnee() const { return annee; }

    void afficher();
};

#endif // PERIODE_H
