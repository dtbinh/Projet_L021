#include "UVManager.h"

using namespace std;

void UVManager::load(CreditsManager credman, CategorieManager catman, FormationManager forman)
{
    QDomDocument doc = uvs.load_xml("uv_utc.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "uv")
       {
            QDomElement unElement = racine.firstChildElement();
            QString strCode,cat,nom,cred,forma;

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
                else if(unElement.tagName() == "branche")
                {
                    forma=unElement.text();
                    //cout<<forma.toStdString()<<endl;
                }
                unElement = unElement.nextSiblingElement();
            }

            Credits credit=credman.getCredits(cred);
            Categorie categorie=catman.getCategorie(cat);
            this->ajouterUV(strCode,nom,categorie);
            //this->getUV(strCode).ajoutCredits(credit); //bug mystrérieux ici
            //forman.getFormation(forma)->ajouterUV(*this->getUv(strCode));
        }
        racine = racine.nextSiblingElement();
  }
}
