///
/// \file Dossier.h
/// \brief Un dossier représente le parcours d'un étudiant.
/// \author Erwan Normand,Nicolas Szewe
/// \date 15 juin 2014
///

#ifndef DOSSIER_H
#define DOSSIER_H

#include <QString>
#include <vector>
#include <algorithm>
#include "Manager.h"
#include "Factory.h"
#include "FormationManager.h"
#include "NoteManager.h"
#include "PeriodeManager.h"
#include "UVManager.h"
#include "Formation.h"
#include "Inscription.h"

class Dossier : public Manager
{
private:
    QString nom;
    QString prenom;
    QString login;
    Factory<Formation> formations;
    Factory<Inscription> inscriptions;

    ///
    /// \fn setLogin
    /// \brief Definit le login a partir du nom et du prenom
    ///
    void setLogin();

public :
    ///
    /// \fn Constructeur Dossier
    /// \param n Nom de l'étudiant
    /// \param p Prenom de l'étudiant
    /// \brief La fonction calcule automatiquement le login de l'étudiant et initialise les maps formations et inscriptions à nul
    ///
    Dossier(const QString& n = "", const QString& p = ""): Manager(), nom(n), prenom(p), formations(), inscriptions() {
        setLogin();
    }

    ///
    /// \fn getNom
    /// \brief Methode qui renvoie une référence constante sur le nom de l'étudiant
    /// \return const QString& -> Nom de l'étudiant
    ///
    const QString& getNom() const { return nom; }

    ///
    /// \fn setNom
    /// \brief Methode qui permet de modifier le nom de l'étudiant. Le login sera recalculé automatiquement
    ///\param n Nouveau nom de l'étudiant
    ///
    void setNom(const QString& n) { nom = n; setLogin(); }

    ///
    /// \fn getPrenom
    /// \brief Methode qui renvoie une référence constante sur le prenom de l'étudiant
    /// \return const QString& -> Prenom de l'étudiant
    ///
    const QString& getPrenom() const { return prenom; }

    ///
    /// \fn setPrenom
    /// \brief Methode qui permet de modifier le prenom de l'étudiant. Le login sera recalculé automatiquement
    ///\param p Nouveau prenom de l'étudiant
    ///
    void setPrenom(const QString& p) { prenom = p; setLogin(); }

    ///
    /// \fn getLogin
    /// \brief Methode qui renvoie une référence constante sur le login de l'étudiant
    /// \return const QString& -> Login de l'étudiant
    ///
    const QString& getLogin() const { return login; }

    ///
    /// \fn getFormations
    /// \brief Methode qui renvoie une référence constante sur la map de formations
    /// \return  const Factory<Formation>& -> L'ensemble des formations de l'étudiant
    ///
    const Factory<Formation>& getFormations() const { return formations; }

    ///
    /// \fn getFormation
    /// \brief Methode qui renvoie une référence sur une formation particulière
    /// \param code Le code de la formation à récupérer
    /// \return  Formation& -> Une formation particulière de l'étudiant
    ///
    Formation& getFormation(const QString& code) { return formations.get(code); }

    ///
    /// \fn getFormation
    /// \brief Methode qui renvoie une référence constante sur une formation particulière
    /// \param code Le code de la formation à récupérer
    /// \return  const Formation& -> Une formation particulière de l'étudiant
    ///
    const Formation& getFormation(const QString& code) const { return formations.get(code); }

    ///
    /// \fn ajouterFormation
    /// \brief Methode pour ajouter une formation à un dossier par référence direct sur la formation (déja existante)
    /// \param f Réference constante sur la formation à ajouter
    ///
    void ajouterFormation(const Formation& f) { formations.ajouter(f.getCode(), f); }

    ///
    /// \fn retirerFormation
    /// \brief Methode pour supprimer une formation à un dossier
    /// \param code Code de la formation à supprimer (ex : GI, TC)
    ///
    void retirerFormation(const QString& code) { formations.retirer(code); }


    ///
    /// \fn getInscriptions
    /// \brief Methode qui renvoie une référence constante sur la map d'inscriptions
    /// \return  const Factory<Inscription>& -> L'ensemble des inscriptions de l'étudiant
    ///
    const Factory<Inscription>& getInscriptions() const { return inscriptions; }

    ///
    /// \fn getInscription
    /// \brief Methode qui renvoie une référence sur une inscription particulière
    /// \param code Le code de l'inscription à récupérer
    /// \return Inscription& -> Une inscription particulière de l'étudiant
    ///
    Inscription& getInscription(const QString& code) { return inscriptions.get(code); }

    ///
    /// \fn getInscription
    /// \brief Methode qui renvoie une référence constante sur une inscription particulière
    /// \param code Le code de l'inscription à récupérer
    /// \return  const Inscription& -> Une inscription particulière de l'étudiant
    ///
    const Inscription& getInscription(const QString& code) const { return inscriptions.get(code); }

    ///
    /// \fn ajouterInscription
    /// \brief Methode pour ajouter une inscription à un dossier.
    /// \brief La méthode va créer l'inscription et l'ajouter dans la map inscriptions
    /// \param code Code de l'inscription (ex : GI02 , TC07)
    /// \param periode Reférence vers la période de cette inscription
    /// \param formation Référence vers une formation.
    ///
    void ajouterInscription(const QString& code, const Periode& periode, const Formation& formation) { inscriptions.ajouter(code, Inscription(code, periode, formation)); }

    ///
    /// \fn retirerInscription
    /// \brief Methode pour supprimer une inscription à un dossier
    /// \param code Code de l'inscription à supprimer
    ///
    void retirerInscription(const QString& code) { inscriptions.retirer(code); }



    ///
    /// \fn charger
    /// \brief Méthode qui charge un dossier depuis un fichier xml
    /// \param forman Le manager des formations
    /// \param periodeman Le manager des périodes
    /// \param uvman Le manager des UVs
    /// \param notman Le manager des notes
    ///
    void charger(const FormationManager& forman, const PeriodeManager& periodeman, const UVManager& uvman, const NoteManager& notman);

    ///
    /// \fn sauvegarder
    /// \brief Méthode qui sauvegarde un dossier dans un fichier xml
    ///
    void sauvegarder();

    ///
    /// \fn getCredits
    /// \brief Methode qui calcule le nombre de credits que vous avez dans les différentes catégories en fonction de vos résultats dans vos inscriptions
    /// \param catman Le manager de Categorie
    /// \return const std::vector<Credits> Un vecteur avec les différents crédits que vous avez. (Un element du vecteur correspond à la somme des crédits de une categorie)
    ///
    const std::vector<Credits> getCredits(const CategorieManager& catman) const ;

    ///
    /// \fn estVide
    /// \brief Pour vérifier que aucun dossier n'est actuellement ouvert
    /// \return bool
    ///
    bool estVide() const { return formations.estVide() && inscriptions.estVide() && nom == "" && prenom == "" && login == ""; }

    ///
    /// \fn vider
    /// \brief Permet de fermer un dossier
    ///
    void vider();
};

#endif // DOSSIER_H
