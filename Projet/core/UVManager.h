///
/// \file UvManager.h
/// \brief Manager des UVs
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef UVMANAGER_H
#define UVMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "UV.h"

///
/// \class UVManager
/// \brief Le manager des UVS
///
class UVManager : public Manager
{
private:
    Factory<UV> uvs;

public:
    ///
    /// \fn UVManager
    /// \brief Constructeur du manager des UVs. Initialise la map uvs.
    /// \param f Le fichier d'intialiation des uvs
    ///
    UVManager(const QString& f = ""): Manager(f), uvs() {}

    ///
    /// \fn charger
    /// \brief Chargement du fichier xml
    /// \param credman Reference sur le manager des credits
    /// \param catman Reference sur le manager des categories
    ///
    void charger(const CreditsManager& credman,const CategorieManager& catman);

    ///
    /// \fn sauvegarder
    /// \brief Sauvegarde du fichier xml
    ///
    void sauvegarder();

    ///
    /// \fn estVide
    /// \brief Teste si le uv manager contient des uvs
    /// \return bool
    ///
    bool estVide() const { return uvs.estVide(); }

    ///
    /// \fn vider
    /// \brief Vide le UV manager de ces uvs
    ///
    void vider() { uvs.vider(); }

    ///
    /// \fn getUVs
    /// \brief Permet d'obtenir l'ensemble des uvs contenues dans le manager
    /// \return const Factory<UV>& -> ensemble des uvs
    ///
    const Factory<UV>& getUVs() const { return uvs; }

    ///
    /// \fn getUV
    /// \brief Permet d'obtenir une UV particuliere de l'ensemble des uvs du manager
    /// \param code Code de l'uv a obtenir
    /// \return UV& Reference vers l'uv
    ///
    UV& getUV(const QString& code) { return uvs.get(code); }

    ///
    /// \fn getUV
    /// \brief Permet d'obtenir une UV particuliere de l'ensemble des uvs du manager
    /// \param code Code de l'uv a obtenir
    /// \return const UV& Reference vers l'uv
    ///
    const UV& getUV(const QString& code) const { return uvs.get(code); }

    ///
    /// \fn ajouterUV
    /// \brief Pour ajouter une uv au manager
    /// \param code Code de l'uv a ajouter
    /// \param nom Nom de l'uv a ajouter
    /// \param cat Reference sur la categorie de l'uv a ajouter
    ///
    void ajouterUV(const QString& code, const QString& nom, const Categorie& cat) { uvs.ajouter(code, UV(code, nom,cat)); }

    ///
    /// \fn retirerUV
    /// \brief Pour retirer une uv du manager
    /// \param code Code de l'uv a retirer
    ///
    void retirerUV(const QString& code) { uvs.retirer(code); }
};

#endif // UVMANAGER_H

