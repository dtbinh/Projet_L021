#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtXml>
#include "Manager.h"
#include "Factory.h"
#include "CreditsManager.h"
#include "CategorieManager.h"
#include "DossierManager.h"
#include "Inscription.h"
#include "UVManager.h"
#include "PeriodeManager.h"
#include "FormationManager.h"
#include "NoteManager.h"

class Application : Manager
{
private:
    NoteManager notman;
    CategorieManager catman;
    CreditsManager credman;

    void loadConfiguration();

public:
    Application(const QString& f = ""): Manager(f), notman(), catman() {}

    void load();
    void save();

    NoteManager& getNoteManager() { return notman; }
    const NoteManager& getNoteManager() const { return notman; }
    CategorieManager& getCategorieManager() { return catman; }
    const CategorieManager& getCategorieManager() const { return catman; }
    CreditsManager& getCreditsManager() { return credman; }
    const CreditsManager& getCreditsManager() const { return credman; }


    void setNoteManager(const NoteManager& n) { notman = n; }
    void setCategorieManager(const CategorieManager& c) { catman = c; }
    void setCreditsManager(const CreditsManager& c) { credman = c; }
};

#endif // APPLICATION_H
