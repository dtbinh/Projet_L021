///
/// \file CategorieManager.h
/// \brief Manager des Categories.
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef CATEGORIEMANAGER_H
#define CATEGORIEMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Observer.h"
#include "Categorie.h"

///
/// \class CategorieManager
/// \brief Le manager des Categorie
///
class CategorieManager : public Manager
{
private:
    Factory<Categorie> categories;

public:
    ///
    /// \fn CategorieManager
    /// \brief Constructeur du manager de Categorie. Initialise la map categories.
    /// \param cf Le chemin du dossier ou est le fichier d'initialisation des categories
    /// \param f Le fichier d'intialiation des categories
    ///
    CategorieManager(const QString& cf = "",const QString& f = ""): Manager(cf, f), categories() {}

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
    /// \brief Teste si le categorie manager contient des categories
    /// \return bool
    ///
    bool estVide() const { return categories.estVide(); }

    ///
    /// \fn vider
    /// \brief Vide le categorie manager de ces categories
    ///
    void vider() { categories.vider(); }

    ///
    /// \fn getCategories
    /// \brief Permet d'obtenir l'ensemble des categories contenues dans le manager
    /// \return const Factory<Categorie>& -> ensemble des categories
    ///
    const Factory<Categorie>& getCategories() const { return categories; }

    ///
    /// \fn getCategorie
    /// \brief Permet d'obtenir une categorie particulière de l'ensemble des catégories du manager
    /// \param code Code de la categorie a obtenir
    /// \return Categorie& Reference vers la categorie
    ///
    Categorie& getCategorie(const QString& code) { return categories.get(code); }

    ///
    /// \fn getCategorie
    /// \brief Permet d'obtenir une categorie particulière de l'ensemble des catégories du manager
    /// \param code Code de la categorie a obtenir
    /// \return const Categorie& Reference constante vers la categorie
    ///
    const Categorie& getCategorie(const QString& code) const { return categories.get(code); }

    ///
    /// \fn ajouterCategorie
    /// \brief Pour ajouter une categorie au manager
    /// \param code Code de la categorie a ajouter
    /// \param nom Nom de la categorie a ajouter
    ///
    void ajouterCategorie(const QString& code, const QString& nom);

    ///
    /// \fn retirerCategorie
    /// \brief Pour retirer une categorie du manager
    /// \param code Code de la categorie
    ///
    void retirerCategorie(const QString& code) { categories.retirer(code); }
};

#endif // CATEGORIEMANAGER_H
