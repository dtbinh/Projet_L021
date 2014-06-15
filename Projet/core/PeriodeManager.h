///
/// \file PeriodeManager.h
/// \brief Manager des Periodes
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef PERIODEMANAGER_H
#define PERIODEMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Periode.h"

///
/// \class PeriodeManager
/// \brief Le manager des Periode
///
class PeriodeManager : public Manager
{
private:
    Factory<Periode> periodes;

public:
    ///
    /// \fn PeriodeManager
    /// \brief Constructeur du manager de Periode. Initialise la map periodes.
    /// \param f Le fichier d'intialiation des periodes
    ///
    PeriodeManager(const QString& f = ""): Manager(f), periodes() {}

    ///
    /// \fn charger
    /// \brief Chargement du fichier xml
    ///
    void charger();

    ///
    /// \fn sauvegarder
    /// \brief Sauvegarde du fichier xml
    ///
    void sauvegarder();

    ///
    /// \fn estVide
    /// \brief Teste si le periode manager contient des periodes
    /// \return bool
    ///
    bool estVide() const { return periodes.estVide(); }

    ///
    /// \fn vider
    /// \brief Vide le periode manager de ces periodes
    ///
    void vider() { periodes.vider(); }

    ///
    /// \fn getPeriodes
    /// \brief Permet d'obtenir l'ensemble des periodes contenues dans le manager
    /// \return const Factory<Periode>& -> ensemble des periodes
    ///
    const Factory<Periode>& getPeriodes() const { return periodes; }

    ///
    /// \fn getPeriode
    /// \brief Permet d'obtenir une periode particuliere de l'ensemble des periodes du manager
    /// \param code Code de la periode a obtenir
    /// \return Periode& Reference vers la periode
    ///
    Periode& getPeriode(const QString& code) { return periodes.get(code); }

    ///
    /// \fn getPeriode
    /// \brief Permet d'obtenir une periode particuliere de l'ensemble des periodes du manager
    /// \param code Code de la periode a obtenir
    /// \return const Periode& Reference vers la periode
    ///
    const Periode& getPeriode(const QString& code) const { return periodes.get(code); }

    ///
    /// \fn ajouterPeriode
    /// \brief Pour ajouter une periode au manager
    /// \param nom Nom de la periode a ajouter
    /// \param annee Annee de la periode a ajouter
    ///
    void ajouterPeriode(const QString& nom, unsigned int annee) { Periode p(nom, annee); periodes.ajouter(p.getCode(), p); }

    ///
    /// \fn retirerPeriode
    /// \brief Pour retirer une periode du manager
    /// \param code Code de la periode a retirer
    ///
    void retirerPeriode(const QString& code) { periodes.retirer(code); }
};

#endif // PERIODEMANAGER_H
