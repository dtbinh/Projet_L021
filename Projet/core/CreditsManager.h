///
/// \file CreditManager.h
/// \brief Manager des Credits.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef CREDITMANAGER_H
#define CREDITMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "CategorieManager.h"
#include "Categorie.h"
#include "Credits.h"

///
/// \class CreditsManager
/// \brief Le manager des Credits
///
class CreditsManager : public Manager
{
private:
    Factory<Credits> credits;

public:
    ///
    /// \fn CreditsManager
    /// \brief Constructeur du manager de Credits. Initialise la map credits.
    /// \param cf Le chemin du dossier ou est le fichier d'initialisation des credits
    /// \param f Le fichier d'intialiation des credits
    ///
    CreditsManager(const QString& cf = "",const QString& f = ""): Manager(cf, f), credits() {}

    ///
    /// \fn charger
    /// \brief Chargement du fichier xml
    ///
    void charger(const CategorieManager& catman);

    ///
    /// \fn sauvegarder
    /// \brief Sauvegarde du fichier xml
    ///
    void sauvegarder();

    ///
    /// \fn estVide
    /// \brief Teste si le categorie manager contient des categories
    /// \return bool
    ///
    bool estVide() const { return credits.estVide(); }

    ///
    /// \fn vider
    /// \brief Vide le categorie manager de ces categories
    ///
    void vider() { credits.vider(); }

    ///
    /// \fn getCredits
    /// \brief Permet d'obtenir l'ensemble des credits contenues dans le manager
    /// \return const Factory<Credits>& -> ensemble des credits
    ///
    const Factory<Credits>& getCredits() const { return credits; }

    ///
    /// \fn getCredits
    /// \brief Permet d'obtenir un type de crédits particulier de l'ensemble des credits du manager
    /// \param code Code du credits a obtenir
    /// \return Credits& Reference vers le type de crédits
    ///
    Credits& getCredits(const QString& code) { return credits.get(code); }

    ///
    /// \fn getCredits
    /// \brief Permet d'obtenir un type de crédits particulier de l'ensemble des credits du manager
    /// \param code Code du credits a obtenir
    /// \return const Credits& Reference constante vers les credits
    ///
    const Credits& getCredits(const QString& code) const { return credits.get(code); }

    ///
    /// \fn ajouterCredits
    /// \brief Pour ajouter un type de credits au manager
    /// \param code Code du credit a ajouter
    /// \param nombre Nombre de credits a ajouter
    /// \param cat Reference constante vers la categorie du type de credits
    ///
    void ajouterCredits(const QString& code, int nombre, const Categorie& cat) { credits.ajouter(code, Credits(code, nombre, cat)); }

    ///
    /// \fn retirerCredits
    /// \brief Pour retirer un type de credits du manager
    /// \param code Code des credits
    ///
    void retirerCredits(const QString& code) { credits.retirer(code); }
};

#endif // CREDITMANAGER_H


