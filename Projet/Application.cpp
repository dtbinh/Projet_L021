#include "Application.h"

using namespace std;

void Application::load()
{
    //fichiers.ajouter("configuration", fichier);

    notman.setFichier("note_utc.xml");
    catman.setFichier("categorie_utc.xml");

    notman.load();
    catman.load();
}

void Application::save()
{
    notman.save();
    catman.save();
}
