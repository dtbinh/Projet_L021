///
/// \file UvManager.h
/// \brief Manager des Uvs
/// \author Nicolas Szewe
/// \date 04 juin 2014
///

#ifndef UVMANAGER_H
#define UVMANAGER_H

#include <QString>
#include <map>
#include <algorithm>
#include "Manager.h"
#include "CreditManager.h"
#include "CategorieManager.h"
#include "UV.h"

class UvManager
{

private:
    Manager<UV> uvs;

public:
    UvManager(): uvs() {}
    UV* getUv(const QString code)  { return &uvs.get(code); }
    void load(CreditManager credman,CategorieManager cm);
    void ajouterUv(QString code, QString nom,const Categorie cat) { uvs.ajouter(code, UV(code, nom,cat)); }
    void retirerUv(QString code) { uvs.retirer(code); }
};

#endif // UVMANAGER_H

