#include "DossierManager.h"

using namespace std;

void DossierManager::load()
{
    QDomDocument doc = dossiers.load_xml("dossier.xml");

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    /*while(!racine.isNull())
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
    }*/
}

