#include "UVManager.h"

using namespace std;

void UVManager::load(const CreditsManager& credman,const CategorieManager& catman,FormationManager& forman)
{
    std::vector<const Formation*> tempformations;
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
                    tempformations.push_back(&forman.getFormation(forma));
                }
                unElement = unElement.nextSiblingElement();
            }
            this->ajouterUV(strCode,nom,catman.getCategorie(cat));
            this->getUV(strCode).ajoutCredits(credman.getCredits(cred));
            if(cat=="TSH"){
                // Doit on l'ajouter aux formations ou on considere ça "à part" avec les mineurs?
            }
            else {
                for (unsigned int i = 0; i < tempformations.size(); i++)
                {
                    forman.getFormation(tempformations[i]->getCode()).ajouterUV(this->getUV(strCode));
                }
                tempformations.clear();
            }
        }
        racine = racine.nextSiblingElement();
  }
}
