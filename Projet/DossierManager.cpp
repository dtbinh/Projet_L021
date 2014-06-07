#include "DossierManager.h"

using namespace std;

void DossierManager::load(QString& fichier)
{
    QDomDocument doc = dossiers.load_xml(fichier);

    QDomElement racine = doc.documentElement();
    racine = racine.firstChildElement();

    while(!racine.isNull())
    {
        if(racine.tagName() == "dossier")
        {
            QString tempNom, tempPrenom;
            QDomElement unElement = racine.firstChildElement();

            while(!unElement.isNull())
            {
                if(unElement.tagName() == "nom")
                {
                    tempNom = unElement.text();
                }
                else if(unElement.tagName() == "prenom")
                {
                    tempPrenom = unElement.text();
                }
                unElement = unElement.nextSiblingElement();
            }

            this->ajouterDossier(tempNom,tempPrenom);
        }

        racine = racine.nextSiblingElement();
    }
}

