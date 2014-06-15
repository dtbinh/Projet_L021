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

///
/// \class Manager
/// \brief Parent de tous les managers.
///
class Manager
{
protected:
    QString chemin_fichier; // Le chemin vers dossier de stockage du fichier
    QString fichier; // Le nom du fichier

    QDomDocument chargerXml(const QString& fichier);
    QDomDocument creerXml();
    void sauvegarderXml(const QString& fichier, const QDomDocument& document);

public:
    ///
    /// \fn Manager
    /// \brief Constructeur d'un manager. Initialise le chemin du fichier et le fichier concerné
    /// \param cf Chemin du fichier du manager
    /// \param f Fichier du manager
    ///
    Manager(const QString& cf = "", const QString& f = ""): chemin_fichier(cf), fichier(f) {}

    ///
    /// \fn getCheminFichier
    /// \brief Pour obtenir le chemin d'un fichier de manager
    /// \return const QString& -> Chemin_fichier
    ///
    const QString& getCheminFichier() const { return chemin_fichier; }

    ///
    /// \fn getFichier
    /// \brief Pour obtenir le fichier de manager
    /// \return const QString& -> fichier
    ///
    const QString& getFichier() const { return fichier; }

    ///
    /// \fn setCheminFichier
    /// \brief Pour modifier le chemin d'un fichier
    /// \param cf Nouveau chemin pour le fichier
    ///
    void setCheminFichier(const QString& cf) { chemin_fichier = cf; }

    ///
    /// \fn setFichier
    /// \brief Pour modifier le fichier
    /// \param cf Nouveau fichier
    ///
    void setFichier(const QString& f) { fichier = f; }
};

#endif // COMPOSANT_H
