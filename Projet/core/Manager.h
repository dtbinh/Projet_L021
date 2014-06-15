///
/// \file Manager.h
/// \brief Un manager pour gérer nos managers d'items
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef COMPOSANT_H
#define COMPOSANT_H

#include <QString>
#include <QtXml>
#include "Exception.h"

class Manager
{
protected:
    QString chemin_fichier; // Le chemin vers dossier de stockage du fichier
    QString fichier; // Le nom du fichier

    QDomDocument chargerXml(const QString& fichier);
    QDomDocument creerXml();
    void sauvegarderXml(const QString& fichier, const QDomDocument& document);

public:
    Manager(const QString& cf = "", const QString& f = ""): chemin_fichier(cf), fichier(f) {}

    const QString& getCheminFichier() const { return chemin_fichier; }
    const QString& getFichier() const { return fichier; }
    void setCheminFichier(const QString& cf) { chemin_fichier = cf; }
    void setFichier(const QString& f) { fichier = f; }
};

#endif // COMPOSANT_H
