///
/// \file Application.h
/// \brief L'application, gestionnaire des managers.
/// \author Erwan Normand
/// \date 10 juin 2014
///

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "DossierManager.h"
#include "FormationManager.h"
#include "Inscription.h"
#include "NoteManager.h"
#include "PeriodeManager.h"
#include "UVManager.h"

class Application : Manager
{
private:
    NoteManager notman;
    CategorieManager catman;
    CreditsManager credman;
    UVManager uvman;
    FormationManager forman; // A factoriser dans un Factory
    FormationManager filman;
    PeriodeManager periodeman;
    //DossierManager dosman;

    void loadConfiguration();

public:
    Application(const QString& f = ""): Manager(f), notman(), catman(), uvman(), forman(), filman(), periodeman() {}

    void load();
    void save();

    NoteManager& getNoteManager() { return notman; }
    const NoteManager& getNoteManager() const { return notman; }

    CategorieManager& getCategorieManager() { return catman; }
    const CategorieManager& getCategorieManager() const { return catman; }

    CreditsManager& getCreditsManager() { return credman; }
    const CreditsManager& getCreditsManager() const { return credman; }

    UVManager& getUVManager() { return uvman; }
    const UVManager& getUVManager() const { return uvman; }

    FormationManager& getFormationManager() { return forman; }
    const FormationManager& getFormationManager() const { return forman; }

    FormationManager& getFiliereManager() { return filman; }
    const FormationManager& getFiliereManager() const { return filman; }

    PeriodeManager& getPeriodeManager() { return periodeman; }
    const PeriodeManager& getPeriodeManager() const { return periodeman; }

    /*DossierManager& getDossierManager() { return dosman; }
    const DossierManager& getDossierManager() const { return dosman; }*/


    void setNoteManager(const NoteManager& n) { notman = n; }
    void setCategorieManager(const CategorieManager& c) { catman = c; }
    void setCreditsManager(const CreditsManager& uv) { credman = uv; }
    void setUVManager(const UVManager& uv) { uvman = uv; }
    void setFormationManager(const FormationManager& f) { forman = f; }
    void setFiliereManager(const FormationManager& f) { filman = f; }
    void setPeriodeManager(const PeriodeManager& p) { periodeman = p; }
    //void setDossierManager(const DossierManager& d) { dosman = d; }
};

#endif // APPLICATION_H
