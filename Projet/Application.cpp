#include "Application.h"

using namespace std;

void Application::chargerConfiguration()
{
    QDomDocument doc = this->chargerXml(dossier.getCheminFichier() + "/" + fichier);

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

            if (manager_nom == "note") {
                notman.setCheminFichier(dossier.getCheminFichier());
                notman.setFichier(manager_fichier);
            }
            else if (manager_nom == "categorie") {
                catman.setCheminFichier(dossier.getCheminFichier());
                catman.setFichier(manager_fichier);
            }
            else if (manager_nom == "periode") {
                periodeman.setCheminFichier(dossier.getCheminFichier());
                periodeman.setFichier(manager_fichier);
            }
            else if (manager_nom == "credits") {
                credman.setCheminFichier(dossier.getCheminFichier());
                credman.setFichier(manager_fichier);
            }
            else if (manager_nom == "uv") {
                uvman.setCheminFichier(dossier.getCheminFichier());
                uvman.setFichier(manager_fichier);
            }
            else if (manager_nom == "formation") {
                forman.setCheminFichier(dossier.getCheminFichier());
                forman.setFichier(manager_fichier);
            }
            else if (manager_nom == "filiere") {
                filman.setCheminFichier(dossier.getCheminFichier());
                filman.setFichier(manager_fichier);
            }
            else if (manager_nom == "dossier") {
                dossier.setCheminFichier(dossier.getCheminFichier());
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
    QDomDocument doc = this->creerXml();
    QDomElement root = doc.createElement("configuration");
    doc.appendChild(root);

    ajouterManagerXml(doc, root, "note", notman.getFichier());
    ajouterManagerXml(doc, root, "categorie", catman.getFichier());
    ajouterManagerXml(doc, root, "credits", credman.getFichier());
    ajouterManagerXml(doc, root, "uv", uvman.getFichier());
    ajouterManagerXml(doc, root, "filiere", filman.getFichier());
    ajouterManagerXml(doc, root, "formation", forman.getFichier());
    ajouterManagerXml(doc, root, "periode", periodeman.getFichier());
    ajouterManagerXml(doc, root, "dossier", dossier.getFichier());

    this->sauvegarderXml(dossier.getCheminFichier() + "/" + fichier, doc);
}

void Application::nouveau(const QString& nom, const QString& prenom)
{
    if (!estFerme()) {
        fermer();
    }

    dossier.setNom(nom);
    dossier.setPrenom(prenom);
    QString chemin_dossier = chemin_dossiers + "/" + dossier.getLogin();

    QDir dos(chemin_dossier);
    if (dos.exists()) {
        fermer();
        throw Exception("Le dossier " + chemin_dossier + " existe déjà.");
    }

    dos.setPath(chemin_fichier);
    if (!dos.exists()) {
        fermer();
        throw Exception("Le dossier " + chemin_fichier + " n'existe pas.");
    }

    dos = dos.current();
    dos.mkdir(chemin_dossier);

    dos.setPath(chemin_fichier);
    QFileInfoList fichdef = dos.entryInfoList();
    for (int i = 0; i < fichdef.size(); ++i) {
        QFile::copy(fichdef[i].filePath(), chemin_dossier + "/" + fichdef[i].fileName());
    }

    dossier.setCheminFichier(chemin_dossier);
    dossier.setFichier(dossier.getLogin() + ".xml");
    dossier.sauvegarder(); // Création du fichier

    chargerConfiguration();
    sauvegarderConfiguration();
}

void Application::charger(const QString& login)
{
    if (!estFerme()) {
        fermer();
    }

    dossier.setCheminFichier(chemin_dossiers + "/" + login);
    dossier.setFichier(login + ".xml");
    chargerConfiguration();
}

void Application::sauvegarder()
{
    if(estFerme()) {
        throw Exception("Impossible de sauvegarder, aucun Dossier n'est chargé.");
    }

    sauvegarderConfiguration();

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
}

bool Application::estFerme() const
{
    return notman.estVide() && catman.estVide() && credman.estVide() && uvman.estVide() && forman.estVide() && filman.estVide() && periodeman.estVide() && dossier.estVide();
}

void Application::ajouterManagerXml(QDomDocument& doc, QDomElement& root, const QString& n, const QString& f) const
{
    QDomElement manager = doc.createElement("manager");
    root.appendChild(manager);

    QDomElement nom = doc.createElement("nom");
    manager.appendChild(nom);
    nom.appendChild(doc.createTextNode(n));

    QDomElement fichier = doc.createElement("fichier");
    manager.appendChild(fichier);
    fichier.appendChild(doc.createTextNode(f));
}
