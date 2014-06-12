#include "Application.h"

using namespace std;

void Application::chargerConfiguration()
{
    QDomDocument doc = this->charger_xml(chemin_dossier + "/" + fichier);

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
                    manager_fichier = chemin_dossier + "/" + element.text();
                }

                element = element.nextSiblingElement();
            }

            if (manager_nom == "note") {
                notman.setFichier(manager_fichier);
            }
            else if (manager_nom == "categorie") {
                catman.setFichier(manager_fichier);
            }
            else if (manager_nom == "periode") {
                periodeman.setFichier(manager_fichier);
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
            else if (manager_nom == "dossier") {
                dossier.setFichier(manager_fichier);
            }
        }

        racine = racine.nextSiblingElement();
    }

    notman.charger();
    catman.charger();
    periodeman.charger();
    credman.charger(catman);
    uvman.charger(credman, catman);
    filman.charger(credman);
    forman.charger(credman, uvman, filman);
    dossier.charger(forman, periodeman, uvman, notman);
}

void Application::sauvegarderConfiguration()
{
    QDomDocument doc = this->creer_xml();
    QDomElement root = doc.createElement("configuration");
    doc.appendChild(root);

    //struct managers { QString nom, fichier; }

    //for(vector)
    /*QDomElement manager = doc.createElement("manager");
    root.appendChild(manager);
    QDomElement nom = doc.createElement("nom");
    manager.appendChild(nom);
    nom.appendChild(doc.createTextNode(managers[i].nom));
    QDomElement fichier = doc.createElement("nom");
    manager.appendChild(fichier);
    fichier.appendChild(doc.createTextNode(managers[i].fichier));*/

    this->sauvegarder_xml(chemin_dossier + "/" + fichier, doc);
}

void Application::nouveau(const QString& nom, const QString& prenom)
{
    if (!estFerme()) {
        fermer();
    }

    dossier.setNom(nom);
    dossier.setPrenom(prenom);
    chemin_dossier = chemin_dossiers + "/" + dossier.getLogin();

    QDir dos(chemin_dossier);
    if (dos.exists()) {
        fermer();
        throw Exception("Le dossier " + chemin_dossier + " existe déjà.");
    }

    dos.setPath(chemin_default);
    if (!dos.exists()) {
        fermer();
        throw Exception("Le dossier " + chemin_default + " n'existe pas.");
    }

    dos = dos.current();
    dos.mkdir(chemin_dossier);

    dos.setPath(chemin_default);
    QFileInfoList fichdef = dos.entryInfoList();
    for (int i = 0; i < fichdef.size(); ++i) {
        QFile::copy(fichdef[i].filePath(), chemin_dossier + "/" + fichdef[i].fileName());
    }

    dossier.setFichier(chemin_dossier + "/" + dossier.getLogin() + ".xml");
    dossier.sauvegarder(); // Création du fichier

    chargerConfiguration();
    sauvegarderConfiguration();
}

void Application::charger(const QString& login)
{
    if (!estFerme()) {
        fermer();
    }

    chemin_dossier = chemin_dossiers + "/" + login;
    chargerConfiguration();
}

void Application::sauvegarder()
{
    if(estFerme()) {
        throw Exception("Impossible de sauvegarder, aucun Dossier n'est chargé.");
    }

    //sauvegarderConfiguration();

    notman.sauvegarder();
    catman.sauvegarder();
    periodeman.sauvegarder();
    credman.sauvegarder();
    uvman.sauvegarder();
    filman.sauvegarder();
    forman.sauvegarder();
    dossier.sauvegarder();
}

void Application::fermer()
{
    dossier.vider();
    forman.vider();
    filman.vider();
    uvman.vider();
    credman.vider();
    periodeman.vider();
    catman.vider();
    notman.vider();

    chemin_dossier = "";
}

bool Application::estFerme() const
{
    return notman.estVide() && catman.estVide() && credman.estVide() && uvman.estVide() && forman.estVide() && filman.estVide() && periodeman.estVide() && dossier.estVide();
}
