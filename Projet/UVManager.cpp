#include "UvManager.h"

using namespace std;

void UVManager::load(CreditManager credman,CategorieManager cm)
{
    QDomDocument doc = load_xml("uv_utc.xml");

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
                else if(unElement.tagName()=="credit")
                {
                    cred=unElement.text();
                }
                else if(unElement.tagName() == "categorie")
                {
                    cat=unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            Credits credits = credman.getCredits(cred);
            Categorie categorie = cm.getCategorie(cat);
            this->ajouterUV(strCode, nom, categorie);
            //this->getUV(strCode).ajoutCredits(credits);
        }

        racine = racine.nextSiblingElement();
  }
}
