///
/// \file Dossier.h
/// \brief Un dossier représente le parcours d'un étudiant.
/// \author Nicolas Szewe, Erwan Normand
/// \date 02 juin 2014
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

    void setLogin();

public :
    ///
    /// \fn Dossier
    /// \param n Nom de l'étudiant
    /// \param p Prenom de l'étudiant
    /// \brief La fonction calcule automatiquement le login de l'étudiant
    ///
    Dossier(const QString& n = "", const QString& p = ""): Manager(), nom(n), prenom(p), formations(), inscriptions() {
        setLogin();
    }

    ~Dossier() {}

    ///
    /// \fn getNom
    /// \return string Nom de l'étudiant
    ///
    const QString& getNom() const { return nom; }

    void setNom(const QString& n) { nom = n; setLogin(); }

    ///
    /// \fn getPrenom
    /// \return string Prenom de l'étudiant
    ///
    const QString& getPrenom() const { return prenom; }

    void setPrenom(const QString& p) { prenom = p; setLogin(); }

    ///
    /// \fn getLogin
    /// \return string Login de l'étudiant
    ///
    const QString& getLogin() const { return login; }

    const Factory<Formation>& getFormations() const { return formations; }
    const Factory<Inscription>& getInscriptions() const { return inscriptions; }

    Formation& getFormation(const QString& code) { return formations.get(code); }
    const Formation& getFormation(const QString& code) const { return formations.get(code); }
    Inscription& getInscription(const QString& code) { return inscriptions.get(code); }
    const Inscription& getInscription(const QString& code) const { return inscriptions.get(code); }

    void ajouterFormation(const Formation& f) { formations.ajouter(f.getCode(), f); }
    void ajouterFormation(const QString& code, const QString& nom) { formations.ajouter(code, Formation(code, nom)); }
    void ajouterInscription(const QString& code, const Periode& periode, const Formation& formation) { inscriptions.ajouter(code, Inscription(code, periode, formation)); }

    void retirerFormation(const QString& code) { formations.retirer(code); }
    void retirerInscription(const QString& code) { inscriptions.retirer(code); }

    void charger(const FormationManager& forman, const PeriodeManager& periodeman, const UVManager& uvman, const NoteManager& notman);
    void sauvegarder();

    bool estVide() const { return formations.estVide() && inscriptions.estVide() && nom == "" && prenom == "" && login == ""; }
    void vider();
};

#endif // DOSSIER_H
