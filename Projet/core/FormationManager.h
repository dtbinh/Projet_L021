///
/// \file FormationManager.h
/// \brief Manager des Formations.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef FORMATIONMANAGER_H
#define FORMATIONMANAGER_H

#include <QString>
#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "Exception.h"
#include "Formation.h"
#include "CreditsManager.h"
#include "UVManager.h"

///
/// \class FormationManager
/// \brief Le manager des Formation
///
class FormationManager : public Manager
{
private:
    Factory<Formation> formations;

public:
    ///
    /// \fn FormationManager
    /// \brief Constructeur du manager de formation. Initialise la map formations.
    /// \param cf Le chemin du dossier ou est le fichier d'initialisation des formations
    /// \param f Le fichier d'intialiation des formations
    ///
    FormationManager(const QString& cf = "", const QString& f = ""): Manager(cf, f), formations() {}

    ///
    /// \fn charger
    /// \brief Chargement du fichier xml (Pour les filieres)
    /// \param credman Reference vers le manager des credits
    ///
    void charger(const CreditsManager& credman);

    ///
    /// \fn charger
    /// \brief Chargement du fichier xml (Pour les formations parentes)
    /// \param credman Reference vers le manager des credits
    /// \param uvman Reference vers le manager des uvs
    /// \param filman Reference vers le manager des filieres
    ///
    void charger(const CreditsManager& credman, const UVManager& uvman, const FormationManager& filman);

    ///
    /// \fn sauvegarder
    /// \brief Sauvegarde du fichier xml
    ///
    void sauvegarder();

    ///
    /// \fn estVide
    /// \brief Teste si le formation manager contient des formations
    /// \return bool
    ///
    bool estVide() const { return formations.estVide(); }

    ///
    /// \fn vider
    /// \brief Vide le formation manager de ces formations
    ///
    void vider() { formations.vider(); }

    ///
    /// \fn getFormations
    /// \brief Permet d'obtenir l'ensemble des formations contenues dans le manager
    /// \return const Factory<Formation>& -> ensemble des formations
    ///
    const Factory<Formation>& getFormations() const { return formations; }

    ///
    /// \fn getFormation
    /// \brief Permet d'obtenir une formation particuliere de l'ensemble des formations du manager
    /// \param code Code de la formation a obtenir
    /// \return Formation& Reference vers la formation
    ///
    Formation& getFormation(const QString& code) { return formations.get(code); }

    ///
    /// \fn getFormation
    /// \brief Permet d'obtenir une formation particuliere de l'ensemble des formations du manager
    /// \param code Code de la formation a obtenir
    /// \return const Formation& Reference vers la formation
    ///
    const Formation& getFormation(const QString& code) const { return formations.get(code); }

    ///
    /// \fn ajouterFormation
    /// \brief Pour ajouter une formation au manager
    /// \param code Code de la formation a ajouter
    /// \param nom Nom de la formation a ajouter
    ///
    void ajouterFormation(const QString& code, const QString& nom) { formations.ajouter(code, Formation(code, nom)); }

    ///
    /// \fn retirerFormation
    /// \brief Pour retirer une formation du manager
    /// \param code Code de la formation a retirer
    ///
    void retirerFormation(const QString& code) { formations.retirer(code); }
};

#endif // FORMATIONMANAGER_H
