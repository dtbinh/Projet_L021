///
/// \file PeriodeManager.h
/// \brief Manager des Periodes
/// \author Nicolas Szewe, Erwan Normand
/// \date 05 juin 2014
///

#ifndef PERIODEMANAGER_H
#define PERIODEMANAGER_H

#include <QString>
#include <QtXml>
#include "AbstractManager.h"
#include "Manager.h"
#include "Periode.h"

class PeriodeManager : public AbstractManager
{
private:
    Manager<Periode> periodes;

public:
    PeriodeManager(): periodes() {}

    void load();

    const Periode& getPeriode(const QString& code) const { return periodes.get(code); }
    void ajouterPeriode(const QString& nom, unsigned int annee) { Periode p(nom, annee); periodes.ajouter(p.getCode(), p); }
    void retirerPeriode(const QString& code) { periodes.retirer(code); }
};

#endif // PERIODEMANAGER_H
