#include "CreditsManager.h"

using namespace std;

void CreditsManager::charger(const CategorieManager& catman)
{
    QDomDocument doc = this->chargerXml(chemin_fichier + "/" + fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "credits")
        {
            QString strCode,cat;
            int nombr;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    strCode = unElement.text();
                }
                else if(unElement.tagName() == "nombre")
                {
                    nombr = unElement.text().toInt();
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            const Categorie& categorie = catman.getCategorie(cat);
            this->ajouterCredits(strCode, nombr, categorie);
        }

        racine = racine.nextSiblingElement();
    }
}

void CreditsManager::sauvegarder()
{
    QDomDocument doc = this->creerXml();
    QDomElement root = doc.createElement("xml");
    doc.appendChild(root);

    for (map<QString,Credits>::const_iterator it = credits.begin(); it != credits.end(); it++)
    {
        QDomElement credits = doc.createElement("credits");
        root.appendChild(credits);
        QDomElement code = doc.createElement("code");
        credits.appendChild(code);
        QDomText nomText = doc.createTextNode(it->second.getCode());
        code.appendChild(nomText);
        QDomElement nombre = doc.createElement("nombre");
        credits.appendChild(nombre);
        QString tempNombre=QString::number(it->second.getNombre());
        QDomText nombreText = doc.createTextNode(tempNombre);
        nombre.appendChild(nombreText);
        QDomElement categorie = doc.createElement("categorie");
        credits.appendChild(categorie);
        QDomText categorieText = doc.createTextNode(it->second.getCategorie().getCode());
        categorie.appendChild(categorieText);
    }

    this->sauvegarderXml(chemin_fichier + "/" + fichier, doc);
}
