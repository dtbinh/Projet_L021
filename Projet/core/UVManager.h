﻿///
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

class UVManager : public Manager
{
private:
    Factory<UV> uvs;

public:
    UVManager(const QString& f = ""): Manager(f), uvs() {}

    void charger(const CreditsManager& credman,const CategorieManager& catman);
    void sauvegarder();

    bool estVide() const { return uvs.estVide(); }
    void vider() { uvs.vider(); }

    const Factory<UV>& getUVs() const { return uvs; }
    UV& getUV(const QString& code) { return uvs.get(code); }
    const UV& getUV(const QString& code) const { return uvs.get(code); }
    void ajouterUV(const QString& code, const QString& nom, const Categorie& cat) { uvs.ajouter(code, UV(code, nom,cat)); }
    void retirerUV(const QString& code) { uvs.retirer(code); }
};

#endif // UVMANAGER_H

