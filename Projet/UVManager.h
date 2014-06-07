///
/// \file UvManager.h
/// \brief Manager des UVs
/// \author Nicolas Szewe, Erwan Normand
/// \date 05 juin 2014
///

#ifndef UVMANAGER_H
#define UVMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "FormationManager.h"
#include "UV.h"

class UVManager
{
private:
    Manager<UV> uvs;

public:
    UVManager(): uvs() {}

    void load(const CreditsManager& credman,const CategorieManager& catman,FormationManager& forman);
    void save();

    UV& getUV(const QString& code) { return uvs.get(code); }
    const UV& getUV(const QString& code) const { return uvs.get(code); }
    void ajouterUV(const QString& code, const QString& nom, const Categorie& cat) { uvs.ajouter(code, UV(code, nom,cat)); }
    void retirerUV(const QString& code) { uvs.retirer(code); }
};

#endif // UVMANAGER_H

