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

class Application
{
private:
    NoteManager notman;
    CategorieManager catman;
    Factory<QString> fichiers;

public:
    Application(): notman(), catman(), fichiers() {}

    void load();
    void save();

    NoteManager& getNoteManager() { return notman; }
    const NoteManager& getNoteManager() const { return notman; }
    CategorieManager& getCategorieManager() { return catman; }
    const CategorieManager& getCategorieManager() const { return catman; }

    void setNoteManager(const NoteManager& n) { notman = n; }
    void setCategorieManager(const CategorieManager& c) { catman = c; }
};

#endif // APPLICATION_H
