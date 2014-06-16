///
/// \file Application.h
/// \brief L'application, gestionnaire des managers.
/// \author Erwan Normand, Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtXml>
#include <QDir>
#include "Manager.h"
#include "Factory.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "Dossier.h"
#include "FormationManager.h"
#include "Inscription.h"
#include "NoteManager.h"
#include "PeriodeManager.h"
#include "UVManager.h"
#include "Completion.h"

///
/// \class Application
/// \brief Le manager des managers
///
class Application : Manager
{
private:
    QString chemin_dossiers; // Le chemin du dossier de stockage des xml des Dossiers
    NoteManager notman;
    CategorieManager catman;
    CreditsManager credman;
    UVManager uvman;
    FormationManager forman;
    FormationManager filman;
    PeriodeManager periodeman;
    Dossier dossier;
    Completion compman;

    ///
    /// \fn chargerConfiguration
    /// \brief Chargement et initialisation de tous les managers
    ///
    void chargerConfiguration();

    ///
    /// \fn sauvegarderConfiguration
    /// \brief Sauvegarde des configurations utilisateurs concernant les différents fichier xml et manager
    ///
    void sauvegarderConfiguration();

    void ajouterManagerXml(QDomDocument& doc, QDomElement& root, const QString& n, const QString& f) const;

public:
    ///
    /// \fn Application
    /// \brief Le constructeur de Application. Initialise tous les managers et définit le chemin de nos fichiers.
    /// \param cd chemin pour acceder aux fichier spécifique
    /// \param chemin_default Chemin pour acceder au fichier par default
    /// \param f fichier de configuration
    ///
    Application(const QString& cd, const QString& chemin_default, const QString& f): Manager(chemin_default, f), chemin_dossiers(cd),
        notman(), catman(), credman(), uvman(), forman(), filman(), periodeman(), dossier(),compman() {}

    ~Application();

    ///
    /// \fn nouveau
    /// \brief Crée un nouveau dossier et l'initialise avec la configuration par default
    /// \param nom Le nom de l'étudiant
    /// \param prenom Le prenom de l'étudiant
    ///
    void nouveau(const QString& nom, const QString& prenom);

    ///
    /// \fn charger
    /// \brief Charge le dossier existant
    /// \param f login de l'étudiant dont ou souhaite ouvrir le dossier
    ///
    void charger(const QString& f = "");

    ///
    /// \fn sauvegarder
    /// \brief Pour sauvegarder les modifications faites dans l'application
    ///
    void sauvegarder();

    ///
    /// \fn fermer
    /// \brief Pour fermer un dossier
    ///
    void fermer();

    ///
    /// \fn estFerme
    /// \brief Teste si un dossier est ouvert dans l'application
    /// \return bool
    ///
    bool estFerme() const;

    ///
    /// \fn listeConfigurations
    /// \brief Renvoie la liste des fichiers de configurations existant
    /// \return QStringList -> Liste de configuration
    ///
    QStringList listeConfigurations() const;

    ///
    /// \fn listeDossiers
    /// \brief Renvoie la liste des dossier existant
    /// \return QStringList -> Liste de dossier
    ///
    QStringList listeDossiers() const;

    ///
    /// \fn getNoteManager
    /// \brief Renvoie le manager des notes
    /// \return NoteManager&
    ///
    NoteManager& getNoteManager() { return notman; }
    const NoteManager& getNoteManager() const { return notman; }

    ///
    /// \fn getCategorieManager
    /// \brief Renvoie le manager des categories
    /// \return CategorieManager&
    ///
    CategorieManager& getCategorieManager() { return catman; }

    ///
    /// \fn getCategorieManager
    /// \brief Renvoie le manager des categories
    /// \return const CategorieManager&
    ///
    const CategorieManager& getCategorieManager() const { return catman; }

    ///
    /// \fn getCreditsManager
    /// \brief Renvoie le manager des credits
    /// \return CreditsManager&
    ///
    CreditsManager& getCreditsManager() { return credman; }

    ///
    /// \fn getCreditsManager
    /// \brief Renvoie le manager des credits
    /// \return const CreditsManager&
    ///
    const CreditsManager& getCreditsManager() const { return credman; }

    ///
    /// \fn getUVManager
    /// \brief Renvoie le manager des uvs
    /// \return UVManager&
    ///
    UVManager& getUVManager() { return uvman; }

    ///
    /// \fn getUVManager
    /// \brief Renvoie le manager des uvs
    /// \return const UVManager&
    ///
    const UVManager& getUVManager() const { return uvman; }

    ///
    /// \fn getFormationManager
    /// \brief Renvoie le manager des formations
    /// \return FormationManager&
    ///
    FormationManager& getFormationManager() { return forman; }

    ///
    /// \fn getFormationManager
    /// \brief Renvoie le manager des formations
    /// \return const FormationManager&
    ///
    const FormationManager& getFormationManager() const { return forman; }

    ///
    /// \fn getFiliereManager
    /// \brief Renvoie le manager des filieres
    /// \return FiliereManager&
    ///
    FormationManager& getFiliereManager() { return filman; }

    ///
    /// \fn getFiliereManager
    /// \brief Renvoie le manager des filieres
    /// \return const FiliereManager&
    ///
    const FormationManager& getFiliereManager() const { return filman; }

    ///
    /// \fn getPeriodeManager
    /// \brief Renvoie le manager des periodes
    /// \return PeriodeManager&
    ///
    PeriodeManager& getPeriodeManager() { return periodeman; }

    ///
    /// \fn getPeriodeManager
    /// \brief Renvoie le manager des periodes
    /// \return const PeriodeManager&
    ///
    const PeriodeManager& getPeriodeManager() const { return periodeman; }

    ///
    /// \fn getDossier
    /// \brief Renvoie un dossier
    /// \return Dossier&
    ///
    Dossier& getDossier() { return dossier; }

    ///
    /// \fn getDossier
    /// \brief Renvoie un dossier
    /// \return const Dossier&
    ///
    const Dossier& getDossier() const { return dossier; }

    ///
    /// \fn getCompletion
    /// \brief Renvoie les completions d'un dossier
    /// \return Completion&
    ///
    Completion& getCompletion(){return compman;}

    ///
    /// \fn getCompletion
    /// \brief Renvoie les completions d'un dossier
    /// \return const Completion&
    ///
    const Completion& getCompletion() const {return compman;}

};

#endif // APPLICATION_H
