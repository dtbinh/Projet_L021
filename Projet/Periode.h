﻿///
/// \file Periode.h
/// \brief Une formation est découpée en plusieurs périodes.
/// \author Erwan Normand
/// \date 05 juin 2014
///

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
    Periode(const QString& n="", unsigned int a =0);
    const QString& getCode() const { return code; }
    const QString& getNom() const { return nom; }
    unsigned int getAnnee() const { return annee; }

    void afficher() const;
};

#endif // PERIODE_H
