#include "CategorieManager.h"

using namespace std;

void CategorieManager::load()
{
    QDomDocument doc = this->load_xml(fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "categorie")
        {
            QString tempNom, tempURL;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    tempNom = unElement.text();
                }
                else if(unElement.tagName() == "nom")
                {
                    tempURL = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            this->ajouterCategorie(tempNom,tempURL);
        }

        racine = racine.nextSiblingElement();
    }
}

void CategorieManager::save()
{
    QDomDocument doc = this->create_xml();
    QDomElement root = doc.createElement("categories");
    doc.appendChild(root);

    for (map<QString,Categorie>::const_iterator it = categories.begin(); it != categories.end(); it++)
    {
        QDomElement categorie = doc.createElement("categorie");
        root.appendChild(categorie);
        QDomElement code = doc.createElement("code");
        categorie.appendChild(code);
        QDomText codeText = doc.createTextNode(it->second.getCode());
        code.appendChild(codeText);
        QDomElement nom = doc.createElement("nom");
        categorie.appendChild(nom);
        QDomText nomText = doc.createTextNode(it->second.getNom());
        nom.appendChild(nomText);
    }

    this->save_xml(fichier, doc);
}
