#include "Application.h"

using namespace std;

void Application::loadConfiguration()
{
    QDomDocument doc = load_xml(fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if (racine.tagName() == "manager")
        {
            QString manager_nom, manager_fichier;
            QDomElement element = racine.firstChildElement();

            while(!element.isNull())
            {
                if (element.tagName() == "nom") {
                    manager_nom = element.text();
                }
                else if (element.tagName() == "fichier") {
                    manager_fichier = element.text();
                }

                element = element.nextSiblingElement();
            }

            if (manager_nom == "notman") {
                notman.setFichier(manager_fichier);
            }
            else if (manager_nom == "catman") {
                catman.setFichier(manager_fichier);
            }
            else if (manager_nom == "credman") {
                credman.setFichier(manager_fichier);
            }
        }

        racine = racine.nextSiblingElement();
    }
}

void Application::load()
{
    loadConfiguration();

    notman.load();
    catman.load();
    credman.load(catman);
}

void Application::save()
{
    notman.save();
    catman.save();
    credman.save();
}
