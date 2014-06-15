#include "UVManager.h"

using namespace std;

void UVManager::charger(const CreditsManager& credman,const CategorieManager& catman)
{
    QDomDocument doc = this->chargerXml(chemin_fichier + "/" + fichier);
    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "uv")
       {
            QDomElement unElement = racine.firstChildElement();
            QString strCode,cat,nom,cred;

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "code")
                {
                    strCode = unElement.text();
                }
                else if(unElement.tagName() == "nom")
                {
                    nom = unElement.text();
                }
                else if(unElement.tagName()=="credits")
                {
                    cred=unElement.text();
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat=unElement.text();
                }

                unElement = unElement.nextSiblingElement();
            }
            this->ajouterUV(strCode,nom,catman.getCategorie(cat));
            this->getUV(strCode).ajoutCredits(credman.getCredits(cred));

        }
        racine = racine.nextSiblingElement();
  }
}

void UVManager::sauvegarder()
{
    QDomDocument doc = this->creerXml();
    QDomElement root = doc.createElement("uvs");
    doc.appendChild(root);

    for (map<QString,UV>::const_iterator it = uvs.begin(); it != uvs.end(); it++)
    {
        QDomElement uv = doc.createElement("uv");
        root.appendChild(uv);
        QDomElement code = doc.createElement("code");
        uv.appendChild(code);
        QDomText codeText = doc.createTextNode(it->second.getCode());
        code.appendChild(codeText);
        QDomElement nom = doc.createElement("nom");
        uv.appendChild(nom);
        QDomText nomText = doc.createTextNode(it->second.getNom());
        nom.appendChild(nomText);
        std::vector<const Credits*> tempcredits= it->second.getCredits();
        for(unsigned int i=0;i<tempcredits.size();++i){
            QDomElement credits = doc.createElement("credits");
            uv.appendChild(credits);
            QDomText creditText = doc.createTextNode(tempcredits[i]->getCode());
            credits.appendChild(creditText);
        }
        QDomElement categorie = doc.createElement("categorie");
        uv.appendChild(categorie);
        QDomText categorieText = doc.createTextNode(it->second.getCategorie().getCode());
        categorie.appendChild(categorieText);
    }

    this->sauvegarderXml(chemin_fichier + "/" + fichier, doc);
}
