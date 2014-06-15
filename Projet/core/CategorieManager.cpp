#include "CategorieManager.h"

using namespace std;

/*void CategorieManager::renomerCategorie(const QString& code, const QString& nouveau_code)
{
    if (code != nouveau_code)
    {
        categories.get(code).setCode(nouveau_code);
        categories.renomer(code, nouveau_code);
    }
}*/

void CategorieManager::ajouterCategorie(const QString& code, const QString& nom)
{
    Categorie categorie = Categorie(code, nom);
    categories.ajouter(code, categorie);
}

void CategorieManager::charger()
{
    QDomDocument doc = this->chargerXml(chemin_fichier + "/" + fichier);

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

void CategorieManager::sauvegarder()
{
    QDomDocument doc = this->creerXml();
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

    this->sauvegarderXml(chemin_fichier + "/" + fichier, doc);
}
