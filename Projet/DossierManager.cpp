#include "DossierManager.h"

using namespace std;

void DossierManager::load(QString& fichier,const FormationManager& forman)
{
    std::vector<const Formation*> tempformations;
    QString tempForma="NULL";
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
                else if(unElement.tagName() == "formation"){
                    tempForma = unElement.text();
                    tempformations.push_back(&forman.getFormation(tempForma));
                }
                unElement = unElement.nextSiblingElement();
            }
            QString login=this->ajouterDossier(tempNom,tempPrenom);
            if (tempForma!="NULL"){
                for (unsigned int i = 0; i < tempformations.size(); i++)
                {
                    this->getDossier(login).ajouterFormation(*tempformations[i]);
                }
                tempformations.clear();
                tempForma="NULL";
            }
        }
        racine = racine.nextSiblingElement();
    }
}

