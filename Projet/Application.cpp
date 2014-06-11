#include "Application.h"

using namespace std;

Application::Application(const QString& login): Manager(), dossier_fichier(""), notman(), catman(), uvman(), forman(), filman(), periodeman(), dossier()
{
    this->setFichier("configuration.xml");
    if (login != "") {
        setDossier(login);
    }
}

void Application::loadConfiguration()
{
    QDomDocument doc = this->load_xml(dossier_fichier + "/" + fichier);

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
                    manager_fichier = dossier_fichier + "/" + element.text();
                }

                element = element.nextSiblingElement();
            }

            if (manager_nom == "note") {
                notman.setFichier(manager_fichier);
            }
            else if (manager_nom == "categorie") {
                catman.setFichier(manager_fichier);
            }
            else if (manager_nom == "credits") {
                credman.setFichier(manager_fichier);
            }
            else if (manager_nom == "uv") {
                uvman.setFichier(manager_fichier);
            }
            else if (manager_nom == "formation") {
                forman.setFichier(manager_fichier);
            }
            else if (manager_nom == "filiere") {
                filman.setFichier(manager_fichier);
            }
            else if (manager_nom == "periode") {
                periodeman.setFichier(manager_fichier);
            }
            else if (manager_nom == "dossier") {
                dossier.setFichier(manager_fichier);
            }
        }

        racine = racine.nextSiblingElement();
    }
}

void Application::load(const QString& login)
{
    if (login != "") {
        setDossier(login);
    }

    loadConfiguration();

    notman.load();
    catman.load();
    credman.load(catman);
    uvman.load(credman, catman);
    filman.load(credman);
    forman.load(credman, uvman, filman);
    periodeman.load();
    dossier.load(forman, periodeman, uvman, notman);
}

void Application::save()
{
    notman.save();
    catman.save();
    credman.save();
    uvman.save();
    filman.save();
    forman.save();
    periodeman.save();
    dossier.save();
}
