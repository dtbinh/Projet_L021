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
#include "Manager.h"
#include "Factory.h"
#include "Periode.h"

class PeriodeManager : public Manager
{
private:
    Factory<Periode> periodes;

public:
    PeriodeManager(const QString& f = ""): Manager(f), periodes() {}

    void charger();
    void sauvegarder();

    bool estVide() const { return periodes.estVide(); }
    void vider() { periodes.vider(); }

    Periode& getPeriode(const QString& code) { return periodes.get(code); }
    const Periode& getPeriode(const QString& code) const { return periodes.get(code); }
    void ajouterPeriode(const QString& nom, unsigned int annee) { Periode p(nom, annee); periodes.ajouter(p.getCode(), p); }
    void retirerPeriode(const QString& code) { periodes.retirer(code); }
};

#endif // PERIODEMANAGER_H
