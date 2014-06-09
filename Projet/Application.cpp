#include "Application.h"

using namespace std;

void Application::load()
{
    //fichiers.ajouter("configuration", fichier);

    fichiers.ajouter("notman", "note_utc.xml");
    fichiers.ajouter("catman", "categorie_utc.xml");

    notman.load(fichiers.get("notman"));
    catman.load(fichiers.get("catman"));
}

void Application::save()
{
    notman.load(fichiers.get("notman"));
    catman.load(fichiers.get("catman"));
}
