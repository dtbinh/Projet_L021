///
/// \file PeriodeManager.h
/// \brief Manager des Periodes
/// \author Nicolas
/// \date 05 juin 2014
///

#ifndef PERIODEMANAGER_H
#define PERIODEMANAGER_H

#include <QString>
#include <map>
#include <algorithm>
#include "Manager.h"
#include "Periode.h"

class PeriodeManager
{

private:
    Manager<Periode> periodes;

public:
    PeriodeManager(): periodes() {}

    Periode* getPeriode(const QString code)  { return &periodes.get(code); }

    void load();

    void ajouterPeriode(QString nom,unsigned int annee) {   const Periode& temp=Periode(nom,annee);
                                                            QString code=temp.getCode();
                                                            periodes.ajouter(code,temp); }
    void retirerPeriode(QString code) { periodes.retirer(code); }
};

#endif // PERIODEMANAGER_H

