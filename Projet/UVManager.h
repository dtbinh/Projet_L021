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
#include "AbstractManager.h"
#include "Manager.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "UV.h"

class UVManager : public AbstractManager
{
private:
    Manager<UV> uvs;

public:
    UVManager(): uvs() {}

    void load(CreditManager credman, CategorieManager cm);

    const UV& getUV(const QString& code) const { return uvs.get(code); }
    void ajouterUV(const QString& code, const QString& nom, const Categorie& cat) { uvs.ajouter(code, UV(code, nom,cat)); }
    void retirerUV(const QString& code) { uvs.retirer(code); }
};

#endif // UVMANAGER_H

